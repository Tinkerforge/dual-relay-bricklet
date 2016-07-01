#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_dual_relay'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Dual Relay Bricklet

ipcon = IPConnection.new # Create IP connection
dr = BrickletDualRelay.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Turn relays alternating on/off 10 times with 1 second delay
for _ in 0..4
  sleep 1
  dr.set_state true, false
  sleep 1
  dr.set_state false, true
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
