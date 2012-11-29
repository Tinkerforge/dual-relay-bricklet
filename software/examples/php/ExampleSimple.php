<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDualRelay.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDualRelay;

$host = 'localhost';
$port = 4223;
$uid = '6hL'; // Change to your UID

$ipcon = new IPConnection(); // Create IP connection
$dr = new BrickletDualRelay($uid, $ipcon); // Create device object

$ipcon->connect($host, $port); // Connect to brickd
// Don't use device before ipcon is connected

// Turn relays alternating on/off for 10 times with 1 second delay
for($i = 0; $i < 10; $i++) {
    sleep(1);

    if ($i % 2 == 1) {
        $dr->setState(TRUE, FALSE);
    } else {
        $dr->setState(FALSE, TRUE);
    }
}

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));

?>
