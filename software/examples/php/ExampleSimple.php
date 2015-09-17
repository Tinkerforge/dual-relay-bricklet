<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDualRelay.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDualRelay;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$dr = new BrickletDualRelay(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Turn relays alternating on/off 10 times with 1 second delay
for($i = 0; $i < 5; $i++) {
    sleep(1);
    $dr->setState(TRUE, FALSE);
    sleep(1);
    $dr->setState(FALSE, TRUE);
}

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
