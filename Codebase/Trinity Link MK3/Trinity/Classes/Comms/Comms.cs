using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;
using System.IO.Ports;
using System.Threading;
using System.Windows.Forms;

namespace Trinity
{

    public class Comms
    {
        const byte TRANSMISSION_IN_NONE = 0;
        const byte TRANSMISSION_IN_LEDMANAGER = 1;
        const byte TRANSMISSION_IN_PANEL = 2;
        const byte TRANSMISSION_IN_DIODE = 3;
        const byte TRANSMISSION_IN_IDENT = 4;

        const byte TRANSMISSION_OUT_NONE         = 0;
        const byte TRANSMISSION_OUT_PANELFX      = 1;
        const byte TRANSMISSION_OUT_PANELCUSTOM  = 2;
        const byte TRANSMISSION_OUT_DIODEFX      = 3;
        const byte TRANSMISSION_OUT_DIODECUSTOM  = 4;
        const byte TRANSMISSION_OUT_BRIGHTNESS   = 5;
        const byte TRANSMISSION_OUT_SLEEPTIMER   = 6;
        const byte TRANSMISSION_OUT_LIGHTSENSOR  = 7;
        const byte TRANSMISSION_OUT_REQUEST      = 8;
        const byte TRANSMISSION_OUT_IDENT        = 9;

        const byte AUTOCONNECT_FAILED   = 0;
        const byte AUTOCONNECT_SUCCESS  = 1;
        const byte AUTOCONNECT_BUSY     = 2;
        const byte BUFFERSIZE = 5;
        const byte TIMEOUTATTEMPTS = 20;

        bool connected;
        byte readyTransmissionType;
        byte timeoutTimer;
        byte[] transmissionData = new byte[BUFFERSIZE];
        SerialPort serial = new SerialPort();
        Transmission_LedManager buffer_ledManager;
        Transmission_Panel buffer_panel;
        Transmission_Diode buffer_diode;
        string[] ports;
        int currentConnectingPort = -1; //-1 Because a ++ will set it to 0
        bool currentlyConnecting;

        //Constructor
        public Comms()
        {
        }
        //Private
        public byte decodeTransmissionType()
        {
            if (
                transmissionData[0] == 'T' &&
                transmissionData[1] == 'X' &&
                transmissionData[2] == 'L' &&
                transmissionData[3] == 'E' &&
                transmissionData[4] == 'D'
            )
            {
                return TRANSMISSION_IN_LEDMANAGER;
            }
            if (
                transmissionData[0] == 'T' &&
                transmissionData[1] == 'X' &&
                transmissionData[2] == 'P' &&
                transmissionData[3] == 'A' &&
                transmissionData[4] == 'N'
            )
            {
                return TRANSMISSION_IN_PANEL;
            }
            if (
                transmissionData[0] == 'T' &&
                transmissionData[1] == 'X' &&
                transmissionData[2] == 'D' &&
                transmissionData[3] == 'I' &&
                transmissionData[4] == 'O'
            )
            {
                return TRANSMISSION_IN_DIODE;
            }
            if (
                transmissionData[0] == 'I' &&
                transmissionData[1] == 'D' &&
                transmissionData[2] == 'E' &&
                transmissionData[3] == 'N' &&
                transmissionData[4] == 'T'
            )
            {
                return TRANSMISSION_IN_IDENT;
            }

            return TRANSMISSION_IN_NONE;
        }
        private byte waitAndRead()
        {
            while (serial.BytesToRead == 0)
            {


                Thread.Sleep(1);
                timeoutTimer++;
                if (timeoutTimer == TIMEOUTATTEMPTS)
                {
                    Console.WriteLine("\n[WaitAndRead timed out]");
                    timeoutTimer = 0;
                    return (0);
                }
            }

            for (int i = 0; i < (BUFFERSIZE - 1); i++)
            {
                transmissionData[i] = transmissionData[i + 1];
            }
            transmissionData[BUFFERSIZE - 1] = (byte)serial.ReadByte();
            Console.Write((char)transmissionData[BUFFERSIZE - 1]);


            return transmissionData[BUFFERSIZE - 1];
        }
        private bool doTransmissionEndCheck()
        {
            for (byte i = 0; i < BUFFERSIZE; i++)
            {
                waitAndRead();
                if
                (
                    transmissionData[0] == 'C' &&
                    transmissionData[1] == 'l' &&
                    transmissionData[2] == 'e' &&
                    transmissionData[3] == 'a' &&
                    transmissionData[4] == 'r'
                )
                {
                    Console.WriteLine("[LINK-CLR-ACK]");
                    return true;
                }
            }

            printBuffer();

            
            Console.WriteLine("[LINK-CLR-NCK]");
            return false;
        }
        private void printBuffer()
        {
            Console.Write("[LINK-BUF-PRI: ");
            for (byte i = 0; i < BUFFERSIZE; i++)
            {
                Console.Write((char)transmissionData[i]);
            }
            Console.WriteLine("]");
        }
        private void disconnect()
        {
            Console.WriteLine("Closed port " + serial.PortName);
            connected = false;
            serial.Close();
        }
        //Public
        public void manuallyConnect(int baudrate, string port)
        {
            if (serial.IsOpen)
            {
                disconnect();
            }
            serial.PortName = port;
            serial.BaudRate = baudrate;
            serial.Open();
            connected = true;
            Console.WriteLine("Manually connected to " + port);
        }
        public void autoConnect(int baudrate)
        {
            ports = SerialPort.GetPortNames();
            serial.BaudRate = baudrate;
            currentConnectingPort = -1; //-1 Because a ++ will set it to 0
        }
        public byte autoConnect_tick() //0:Failed, 1:Success, 2:Busy.
        {

            if (currentlyConnecting)
            {
                if (tick() == false)
                {
                    Console.WriteLine("AUTOCONNECT ROUND NEGATIVE");
                    serial.Close();
                    currentlyConnecting = false;
                }
                if (getReadyTransmissionType() == TRANSMISSION_IN_IDENT)
                {
                    connected = true;
                    Console.WriteLine("AUTOCONNECT SUCCESSFUL!!!");
                    return AUTOCONNECT_SUCCESS;
                }
            }
            else
            {
                currentConnectingPort++;
                if (currentConnectingPort == ports.Length)
                {
                    Console.WriteLine("AUTOCONNECT FAILED");
                    return AUTOCONNECT_FAILED;
                }
                else
                {
                    disconnect();
                    Console.WriteLine("AUTOCONNECT ATTEMPTING " + ports[currentConnectingPort]);
                    serial.PortName = ports[currentConnectingPort];
                    serial.Open();
                    transmit(TRANSMISSION_OUT_IDENT, "");
                    currentlyConnecting = true;
                    waitAndRead();
                }
            }
            return AUTOCONNECT_BUSY;
        }
        public bool tick() //0:Nothing, 1:All data was probably read.
        {
            if (serial.IsOpen || connected)
            {
                try
                {
                    while (serial.BytesToRead != 0)
                    {
                        for (int i = 0; i < (BUFFERSIZE - 1); i++)
                        {
                            transmissionData[i] = transmissionData[i + 1];
                        }
                        transmissionData[BUFFERSIZE - 1] = (byte)serial.ReadByte();
                        Console.Write((char)transmissionData[BUFFERSIZE - 1]);

                        //printBuffer();

                        byte receivedTransmissionType = decodeTransmissionType();

                        /*
                        if (receivedTransmissionType != TRANSMISSION_IN_NONE)
                        {
                            Console.Write("Transmission ");
                            Console.Write(receivedTransmissionType);
                        }
                        */

                        switch (receivedTransmissionType)
                        {
                            case TRANSMISSION_IN_LEDMANAGER:
                                Console.Write("[LINK-DET-MAN]");

                                buffer_ledManager.brightness = waitAndRead();
                                buffer_ledManager.speed = waitAndRead();
                                buffer_ledManager.enabled = Convert.ToBoolean(waitAndRead());
                                break;
                            case TRANSMISSION_IN_PANEL:
                                Console.Write("[LINK-DET-PAN]");

                                buffer_panel.number = waitAndRead();
                                buffer_panel.compassDir = waitAndRead();
                                buffer_panel.clockDir = Convert.ToBoolean(waitAndRead());
                                buffer_panel.diodeAmount = waitAndRead();

                                buffer_panel.brightness = waitAndRead();
                                buffer_panel.effect = waitAndRead();
                                buffer_panel.colour = waitAndRead();
                                buffer_panel.offset = waitAndRead();
                                buffer_panel.speed = waitAndRead();
                                buffer_panel.repeat = Convert.ToBoolean(waitAndRead());
                                buffer_panel.detailed = Convert.ToBoolean(waitAndRead());

                                buffer_panel.r = waitAndRead();
                                buffer_panel.g = waitAndRead();
                                buffer_panel.b = waitAndRead();
                                break;
                            case TRANSMISSION_IN_DIODE:
                                Console.Write("[LINK-DET-DIO]");
                                buffer_panel.number = waitAndRead();

                                buffer_panel.brightness = waitAndRead();
                                buffer_panel.effect = waitAndRead();
                                buffer_panel.colour = waitAndRead();
                                buffer_panel.offset = waitAndRead();
                                buffer_panel.speed = waitAndRead();
                                buffer_panel.repeat = Convert.ToBoolean(waitAndRead());

                                buffer_panel.r = waitAndRead();
                                buffer_panel.g = waitAndRead();
                                buffer_panel.b = waitAndRead();
                                break;
                            case TRANSMISSION_IN_IDENT:
                                Console.Write("[LINK-DET-ID]");
                                break;
                        }

                        if (receivedTransmissionType != TRANSMISSION_IN_NONE)
                        {
                            if (doTransmissionEndCheck())
                            {
                                readyTransmissionType = receivedTransmissionType;
                                Console.WriteLine("[LINK-TRANS-ACK]");
                            }
                            else
                            {
                                Console.WriteLine("[LINK-TRANS-ACK]");
                            }
                        }

                        while (serial.BytesToRead == 0)
                        {
                            Thread.Sleep(1);
                            timeoutTimer++;
                            if (timeoutTimer == TIMEOUTATTEMPTS)
                            {
                                Console.WriteLine("\n[Tick serial timed out]");
                                timeoutTimer = 0;
                                return true;
                            }
                        }
                    }
                }
                catch (System.InvalidOperationException)
                {
                    disconnect();
                }
            }
            return false;
        }
        public void transmit(byte transmissionType, string data)
        {
            switch (transmissionType)
            {
                case TRANSMISSION_OUT_PANELFX:
                    serial.Write("PanFx");
                    break;
                case TRANSMISSION_OUT_PANELCUSTOM:
                    serial.Write("PanCu");
                    break;
                case TRANSMISSION_OUT_DIODEFX:
                    serial.Write("DioFx");
                    break;
                case TRANSMISSION_OUT_DIODECUSTOM:
                    serial.Write("DioCu");
                    break;
                case TRANSMISSION_OUT_BRIGHTNESS:
                    serial.Write("Brigh");
                    break;
                case TRANSMISSION_OUT_SLEEPTIMER:
                    serial.Write("Sleep");
                    break;
                case TRANSMISSION_OUT_LIGHTSENSOR:
                    serial.Write("Light");
                    break;
                case TRANSMISSION_OUT_REQUEST:
                    serial.Write("Reque");
                    break;
                case TRANSMISSION_OUT_IDENT:
                    serial.Write("Ident");
                    break;
            }
            serial.Write(data);
            serial.Write("Clear");
        }
        public byte getReadyTransmissionType()
        {
            if (readyTransmissionType == TRANSMISSION_IN_IDENT)
            {
                readyTransmissionType = TRANSMISSION_IN_NONE;
                return TRANSMISSION_IN_IDENT;
            }
            return readyTransmissionType;
        }
        public string getConnectedPort()
        {
            return serial.PortName;
        }
        public bool getConnected()
        {
            return connected;
        }
        public string[] getPorts()
        {
            ports = SerialPort.GetPortNames();
            return ports;
        }
        public Transmission_LedManager getTransmission_LedManager()
        {
            return buffer_ledManager;
        }
        public Transmission_Panel getTransmission_Panel()
        {
            return buffer_panel;
        }
        public Transmission_Diode getTransmission_Diode()
        {
            return buffer_diode;
        }
        

        //Old Code
        public bool getConnectionClearance() //Checks if the system is connected properly in order to safely transmit.
        {
            throw new NotImplementedException();
        }
        public void serialWrite(string text) //Prints to the serial monitor
        {
            throw new NotImplementedException();
        }

    }
}
