using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Trinity.Classes.Comms;
using Trinity;
using System.Windows.Forms;

namespace Trinity.Classes.Comms
{
    public class LedManager
    {
        byte brightness;
        byte speed;
        bool enabled;
        public List<Panel> panels = new List<Panel>();

        public LedManager()
        {
          Console.WriteLine("LedManager Starting...");

          brightness    = 100;
          speed         = 1;

          Console.WriteLine("...LedManager Started");
        }

        private Panel getPanel(byte panelNumber) //Searches for a panel in active panel storage
        {
            foreach (Panel panel in panels)
            {
                if (panel.getNumber() == panelNumber)
                {
                    return panel;
                }
            }
            return null;
        }

        private void addPanel(Panel panelToAdd)
        {
            Panel existingPanel = getPanel(panelToAdd.getNumber());
            if (existingPanel == null)
            {
                panels.Add(panelToAdd);
                return;
            }
            return;
        }

        



        //Public
        public void tick()
        {
            for (byte panelNumber = 0; panelNumber < panels.Count; panelNumber++)
            {
                panels[panelNumber].tick();
                for (byte diodeNumber = 0; diodeNumber < panels[panelNumber].getDiodeAmount(); diodeNumber++)
                {
                    //leds[panels[panelNumber].getDiodeStart() + diodeNumber] = panels[panelNumber].getDiodeRGB(diodeNumber, brightness);
                }
            }
        }
        void print()
        {
            //FastLED.show();
        }
        byte getBrightness()
        {
            return brightness;
        }
        void setBrightness(byte brightness)
        {
            this.brightness = brightness;
        }
        int getPanelAmount()
        {
            return panels.Count;
        }
        byte getPanelDiodeAmount(byte panelNumber)
        {
            return panels[panelNumber].getDiodeAmount();
        }
        public void setDataFromTransmission(Transmission_LedManager data)
        {
            brightness = data.brightness;
            speed = data.speed;
        }
        public void setPanelDataFromTransmission(Transmission_Panel data)
        {
            Panel existingPanel = getPanel(data.number);
            if (existingPanel == null) //If the panel doesn't exist in the ledmanager (Create new one)
            {
                Panel newPanel = new Panel(data.number, data.compassDir, data.clockDir, data.diodeAmount);
                newPanel.setDataFromTransmisison(data);
                addPanel(newPanel);
            }
            else //If the panel exists in the ledmanager (Update it)
            {
                existingPanel.setDataFromTransmisison(data);
            }
        }
        public void setPanelDiodeDataFromTransmission(Transmission_Diode data)
        {
            getPanel(data.panelNumber).setDiodeDataFromTransmisison(data);
        }
        void setEnabled(bool enabled)
        {
            this.enabled = enabled;
        }
        String convertToTansmission()
        {
            String data = "";

            data += (char)brightness;
            data += (char)speed;
            data += Convert.ToChar(enabled);

            return data;
        }
        String convertPanelToTransmission(byte panelNumber)
        {
            return panels[panelNumber].convertToTransmission();
        }
        String convertPanelDiodeToTransmission(byte panelNumber, byte diodeNumber)
        {
            return panels[panelNumber].convertDiodeToTransmission(diodeNumber);
        }

    }
}
