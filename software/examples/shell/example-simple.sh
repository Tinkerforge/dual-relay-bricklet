#!/bin/sh
# connects to localhost:4223 by default, use --host and --port to change it

# change to your UID
uid=dbs

# turn relay 1 on and relay 2 off
tinkerforge call dual-relay-bricklet $uid set-state true false
