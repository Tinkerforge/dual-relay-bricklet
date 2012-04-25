using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "ABC"; // Change to your UID

	static void Main() 
	{
		IPConnection ipcon = new IPConnection(HOST, PORT); // Create connection to brickd
		BrickletDualRelay dr = new BrickletDualRelay(UID); // Create device object
		ipcon.AddDevice(dr); // Add device to IP connection
		// Don't use device before it is added to a connection

		// Turn relays alternating on/off for 10 times with 1 second delay
		for(int i = 0; i < 10; i++)
		{
			System.Threading.Thread.Sleep(1000);
			if(i % 2 == 0) 
			{
				dr.SetState(true, false);
			} 
			else
			{
				dr.SetState(false, true);
			}
		}

		System.Console.WriteLine("Press ctrl+c to exit");
		ipcon.JoinThread();
	}
}
