#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_dual_relay'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = '6hL' # Change to your UID

ipcon = IPConnection.new HOST, PORT # Create IP connection to brickd
dr = BrickletDualRelay.new UID # Create device object
ipcon.add_device dr # Add device to IP connection
# Don't use device before it is added to a connection

# Turn relays alternating on/off for 10 times with 1 second delay
for i in 0..9
  sleep 1
  puts "#{i}"
  if i % 2 == 1
    dr.set_state true, false
  else
    dr.set_state false, true
  end
end

puts 'Press key to exit'
$stdin.gets
ipcon.destroy
