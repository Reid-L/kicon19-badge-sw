# Copyright (c) 2019 Maciej Suminski <orson@orson.net.pl>
#
# This source code is free software; you can redistribute it
# and/or modify it in source code form under the terms of the GNU
# General Public License as published by the Free Software
# Foundation; either version 2 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.


import serial
import struct
import time
import binascii
import commands_def as cmd_defs

class KiconBadge:
    def __init__(self, port):
        self._serial = None
        self._serial = serial.Serial(port, 115200, timeout=0.1)   # TODO baud?

    def __del__(self):
        if self._serial:
            self._serial.close()

    def _crc(self, data):
        crc = 0

        try:
            for c in data:
                crc = crc ^ c
        except TypeError:
            crc = data  # handle int

        return crc

    def _make_resp(self, resp):
        return struct.pack('>BBB', 1, resp, self._crc(resp))

    def _make_cmd(self, cmd, data=None):
        if data != None:
            data_bytes = struct.pack('>B%ds' % len(data), cmd, data)
            data_len = len(data_bytes)
            return struct.pack('>B%dsB' % data_len,    # struct format
                    data_len, data_bytes, self._crc(data_bytes))
        else:
            return struct.pack('>BBB', 1, cmd, self._crc(cmd))

    def _get_resp(self):
        resp_len = self._serial.read(1)[0]
        resp_data = self._serial.read(resp_len + 1) # +1 for CRC
        resp_type = resp_data[0]
        resp_crc = resp_data[-1]
        calc_crc = self._crc(resp_data[:-1])
        raw_data = resp_data[1:-1]      # strip command response type and CRC

        if resp_crc != calc_crc:
            raise Exception('CRC error (expected 0x%x, got 0x%x)'
                    % (calc_crc, resp_crc))

        if resp_type != cmd_defs.CMD_RESP_OK:
            raise Exception('Response != OK: code = 0x%.2x, data = "%s"'
                    % (resp_type, str(binascii.hexlify(raw_data), 'ascii')))

        return raw_data

    def reset(self):
        # special command type, cannot be created with make_cmd
        reset_cmd = struct.pack('>B', cmd_defs.CMD_TYPE_RESET)
        reset_resp = self._make_resp(cmd_defs.CMD_RESP_RESET)

        self._serial.write(reset_cmd)
        time.sleep(0.1)
        self._serial.read(len(reset_resp))

        trials = 0
        while self._serial.read(len(reset_resp)) != reset_resp:
            self._serial.write(reset_cmd)
            trials = trials + 1
            time.sleep(0.1)

            if trials == 256:
                raise Exception('No response after reset')

    def uart_send(self, data):
        uart_cmd = self._make_cmd(cmd_defs.CMD_TYPE_UART, data)
        self._serial.write(uart_cmd)
        self._get_resp()
