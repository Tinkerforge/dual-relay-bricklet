#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_dual_relay'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change to your UID

ipcon = IPConnection.new # Create IP connection
dr = BrickletDualRelay.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Turn relays alternating on/off for 10 times with 1 second delay
for i in 0..9
  sleep 1

  if i % 2 == 1
    dr.set_state true, false
  else
    dr.set_state false, true
  end
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
