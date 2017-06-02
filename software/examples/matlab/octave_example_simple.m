function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Dual Relay Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    dr = javaObject("com.tinkerforge.BrickletDualRelay", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Turn relays alternating on/off 10 times with 1 second delay
    for i = 0:4
        pause(1);
        dr.setState(true, false);
        pause(1);
        dr.setState(false, true);
    end

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
