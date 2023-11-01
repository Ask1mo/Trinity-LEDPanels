using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System.IO.Ports;



namespace Trinity
{

    public class Comms
    {
        SerialPort serialPort = new SerialPort();
        byte[] transmissionData = new byte[maxTransmissionLength];
        const byte maxTransmissionLength = 11;

        byte amountOfBrokenBits = 0;
        byte brokenBitX = 0;
        byte brokenBitY = 0;

        public bool SetupMapClearance { get; set; }

        public Comms()//Constructor
        {
            SetupMapClearance = false;
        }
        public bool getConnectionClearance() //Checks if the system is connected properly in order to safely transmit.
        {
            if (serialPort.IsOpen && SetupMapClearance) return true;
            return false;
        }
        public bool getSerialPortState() //Checks if the serial port is connected
        {
            if (serialPort.IsOpen) return true;
            return false;
        }
        public void disconnectSerialPort() //Closes the serial port
        {
            serialPort.Close();
        }
        public void connectSerialPort(string name, int baudRate) //Opens a serial port
        {
            serialPort.PortName = name;
            serialPort.BaudRate = baudRate;
            serialPort.Open();
        }
        public void serialWrite(string text) //Prints to the serial monitor
        {
            serialPort.Write(text);
        }
        public bool serialRead() //Reads from the serial monitor
        {
            while (serialPort.BytesToRead != 0)
            {
                byte newByte = (byte)serialPort.ReadByte();

                for (byte i = 0; i < maxTransmissionLength-1; i++)
                {
                    transmissionData[i] = transmissionData[i+1];
                }
                transmissionData[maxTransmissionLength-1] = newByte;

                



                //transmissionData[byteNumber] = (byte)serialPort.ReadByte();
                //Console.Write("Received: ");
                //Console.Writeline(transmissionData[byteNumber]);
                Console.Write((char)transmissionData[0]);

                if (messageCompleteChecker())
                {
                    return true;
                }
            }
            return false;
        }

        /*public void messageCorruptor() //Corrupts a random bit in a random byte from a transmission
        {
            byte pos = Panel.GetSomeRandomNumber(0, 8);
            transmissionData[pos] = (byte)(transmissionData[pos] & Panel.GetSomeRandomNumber(0, 255));
        }*/
        public bool messageCompleteChecker()
        {
            Console.Write("   -BUFFER: ");
            for (int i = 0; i < maxTransmissionLength; i++)
            {
                Console.Write((char)transmissionData[i]);
            }
            Console.WriteLine();



            if(
                transmissionData[0] == '/' &&
                transmissionData[2] == '/' &&
                transmissionData[6] == '/' &&
                transmissionData[10] == '/'
              )
                {
                Console.WriteLine("Successful match");
                return true;
                }
            return false;
        }
        
        /*public bool messageParityChecker()
        {
            //transmissionData[0] = 0;
            bool transmissionCorrect = true;
            for (byte i = 0; i < 8; i++)
            {
                if (!byteParityChecker(transmissionData[i]))
                {
                    Console.Write("BROKEN PARITY DETECTED: Y");
                    Console.WriteLine(i);
                    brokenBitY = i;
                    amountOfBrokenBits++;
                    transmissionCorrect = false;
                }
            }


            int tiltedMessageTemp = 0; //Temporary slot for data
            int[] tiltedMessage = new int[8]; //Copy of the transmission data but rotated 90* left/counter-clockwise
            for (byte i = 0; i < 8; i++)
            {
                tiltedMessage[i] = 0; //makes sure the data is empty
            }

            //Rotating the transmission data
            for (byte j = 0; j < 8; j++) // x-ax for message / y-ax for tilted message
            {
                for (byte i = 0; i < 8; i++) // y-ax for message / x-ax for tilted message
                {
                    tiltedMessageTemp = transmissionData[i]; //Takes one of the 8 bytes of a message

                    //shifts the message byte so the relevant bit ends up in the correct x-axis location for the tilted message
                    if ((i + j) > 7) tiltedMessageTemp = tiltedMessageTemp >> (((7 - j) - i) * -1); //Moves to the right
                    else tiltedMessageTemp = tiltedMessageTemp << ((7 - j) - i); //Moves to the left

                    tiltedMessageTemp = tiltedMessageTemp & (128 >> i); //Filters the rest of the message byte out, so only the relevant data remains.
                    tiltedMessage[j] = tiltedMessage[j] | tiltedMessageTemp; //Puts the bit in the correct y-slot of the tilted message
                }
            }


            for (byte i = 0; i < 8; i++)
            {
                if (!byteParityChecker((byte)tiltedMessage[i]))
                {
                    Console.Write("BROKEN PARITY DETECTED: X");
                    Console.WriteLine(i);
                    brokenBitX = i;
                    amountOfBrokenBits++;
                    transmissionCorrect = false;
                }
            }

            return transmissionCorrect;




        }
        */
        /*bool byteParityChecker(byte data)
        {
            byte ones = 0;
            int testData;

            for (byte i = 0; i < 7; i++)
            {
                testData = data;
                testData = testData & (128>>i);
                if (testData == (128>>i)) ones++;
            }

            if (ones == 0 || ones == 2 || ones == 4 || ones == 6 || ones == 8)
            {
                return false;
            }

            return true;
        }
        */
        /*public bool attemptTransmissionRepair()
        {
            Console.WriteLine("Broken bit detected... Starting repair");
            while (amountOfBrokenBits == 2 || amountOfBrokenBits == 4 || amountOfBrokenBits == 6)
            {
                Console.WriteLine("Repairing...");
                int bitToChange = 1;
                int byteToChange = transmissionData[brokenBitY];
                bitToChange = bitToChange << brokenBitX;
                byteToChange = byteToChange ^ bitToChange;
                transmissionData[brokenBitY] = (byte)byteToChange;

                amountOfBrokenBits -= 2;

                if (messageParityChecker())
                {
                    Console.WriteLine("Repair complete");
                    return true;
                }
            }
            Console.WriteLine("Repair failed");
            return false;
        }
        */

        public Panel transmissionDecoder()
        {
            Console.WriteLine("Leaf transmission complete, interpreting data");



            byte panelNumber = transmissionData[1];

            byte offset = transmissionData[3];
            byte speed = transmissionData[4];

            int fxType = transmissionData[5];
            fxType = fxType >> 4;
            fxType = fxType & 0x0F;
            int fxNumber = transmissionData[5];
            fxNumber = fxNumber & 0xF0;

            byte redValue = transmissionData[7];
            byte greenValue = transmissionData[8];
            byte blueValue = transmissionData[9];

            Panel panel = new Panel(panelNumber, offset, speed, (byte)fxType, (byte)fxNumber, redValue, greenValue, blueValue);
            return panel;
        }

        public int getBufferSize()
        {
            return serialPort.BytesToRead;
        }
        public void clearBuffer()
        {
            while (serialPort.BytesToRead != 0)
            {
                transmissionData[0] = (byte)serialPort.ReadByte();
            }
            for (byte i = 0; i < 8; i++)
            {
                transmissionData[i] = 0;
            }
        }
    }
}
