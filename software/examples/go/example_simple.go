package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/dual_relay_bricklet"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"time"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Dual Relay Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	dr, _ := dual_relay_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Turn relays alternating on/off 10 times with 1 second delay
	for i := 0; i < 5; i++ {
		time.Sleep(1000 * time.Millisecond)
		dr.SetState(true, false)
		time.Sleep(1000 * time.Millisecond)
		dr.SetState(false, true)
	}

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
