import com.tinkerforge.BrickletDualRelay;
import com.tinkerforge.IPConnection;

public class ExampleSimple {
	private static final String host = new String("localhost");
	private static final int port = 4223;
	private static final String UID = new String("ABC"); // Change to your UID
	
	// Note: To make the example code cleaner we do not handle exceptions. Exceptions you
	//       might normally want to catch are described in the commnents below
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(host, port); // Create connection to brickd (Can throw IOException)

		BrickletDualRelay dr = new BrickletDualRelay(UID); // Create device object
		ipcon.addDevice(dr); // Add device to ip connection (Can throw IPConnection.TimeoutException)
		// Don't use device before it is added to a connection
		

		// Turn relays alternating on/off for 10 times with 1 second delay
		for(int i = 0; i < 10; i++) {
			Thread.sleep(1000);
			if(i % 2 == 1) {
				dr.setState(true, false);
			} else {
				dr.setState(false, true);
			}
		}

		System.out.println("Press ctrl+c to exit");
		ipcon.joinThread();
	}
}
