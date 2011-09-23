/*************************************************************
 * This file was automatically generated on 2011-09-20.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

namespace Tinkerforge
{
	public class BrickletDualRelay : Device 
	{
		private static byte TYPE_SET_STATE = 1;
		private static byte TYPE_GET_STATE = 2;


		public BrickletDualRelay(string uid) : base(uid) 
		{

		}

		public void SetState(bool relay1, bool relay2)
		{
			byte[] data = new byte[6];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_STATE, 1, data);
			LEConverter.To((ushort)6, 2, data);
			LEConverter.To(relay1, 4, data);
			LEConverter.To(relay2, 5, data);

			ipcon.Write(this, data, TYPE_SET_STATE, false);
		}

		public void GetState(out bool relay1, out bool relay2)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_STATE, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_STATE, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetState in time");
			}

			relay1 = LEConverter.BoolFrom(4, answer);
			relay2 = LEConverter.BoolFrom(5, answer);

			writeEvent.Set();
		}

		public void RegisterCallback(System.Delegate d)
		{
		}
	}
}
