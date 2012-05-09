<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletDualRelay.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletDualRelay;

$host = 'localhost';
$port = 4223;
$uid = '6hL'; // Change to your UID

$ipcon = new IPConnection($host, $port); // Create IP connection to brickd
$dr = new BrickletDualRelay($uid); // Create device object

$ipcon->addDevice($dr); // Add device to IP connection
// Don't use device before it is added to a connection

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
$ipcon->destroy();

?>
