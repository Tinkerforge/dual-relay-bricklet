#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Dual Relay Bricklet

import time

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_dual_relay import BrickletDualRelay

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    dr = BrickletDualRelay(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Turn relays alternating on/off 10 times with 1 second delay
    for i in range(5):
        time.sleep(1)
        dr.set_state(True, False)
        time.sleep(1)
        dr.set_state(False, True)

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()
