using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Trinity;

namespace TrinityTestProject
{
    [TestClass]
    public class PanelTests
    {
        [TestMethod]
        public void Test_Panel_Constructor()
        {
            byte panelNumber = 15;
            byte fxOffset = 255;
            byte fxSpeed = 31;
            byte fxType = 15;
            byte fxNumber = 15;
            byte redValue = 255;
            byte greenValue = 255;
            byte blueValue = 255;

            Panel panel = new Panel(panelNumber, fxOffset, fxSpeed, fxType, fxNumber, redValue, greenValue, blueValue);
            
            Assert.AreEqual(panelNumber, panel.PanelNumber);
            Assert.AreEqual(fxOffset, panel.FxOffset);
            Assert.AreEqual(fxSpeed, panel.FxSpeed);
            Assert.AreEqual(fxType, panel.FxType);
            Assert.AreEqual(fxNumber, panel.FxNumber);
            Assert.AreEqual(redValue, panel.RedValue);
            Assert.AreEqual(greenValue, panel.GreenValue);
            Assert.AreEqual(blueValue, panel.BlueValue);
        }

        [TestMethod]
        public void Test_Panel_Constructor_TooHighValues()
        {
            byte panelNumber = 15;
            byte fxOffset = 255;
            byte fxSpeed = 31;
            byte fxType = 15;
            byte fxNumber = 15;
            byte redValue = 255;
            byte greenValue = 255;
            byte blueValue = 255;

            Panel panel = new Panel(255, 255, 255, 255, 255, 255, 255, 255);

            Assert.AreEqual(panelNumber, panel.PanelNumber);
            Assert.AreEqual(fxOffset, panel.FxOffset);
            Assert.AreEqual(fxSpeed, panel.FxSpeed);
            Assert.AreEqual(fxType, panel.FxType);
            Assert.AreEqual(fxNumber, panel.FxNumber);
            Assert.AreEqual(redValue, panel.RedValue);
            Assert.AreEqual(greenValue, panel.GreenValue);
            Assert.AreEqual(blueValue, panel.BlueValue);
        }

        [TestMethod]
        public void Test_Panel_UpdatePanel_Correct()
        {
            byte panelNumber = 15;
            byte fxOffset = 255;
            byte fxSpeed = 31;
            byte fxType = 15;
            byte fxNumber = 15;
            byte redValue = 255;
            byte greenValue = 255;
            byte blueValue = 255;

            Panel panel = new Panel(15, 0, 0, 0, 0, 0, 0, 0);

            panel.UpdatePanel(panelNumber, fxOffset, fxSpeed, fxType, fxNumber, redValue, greenValue, blueValue);

            Assert.AreEqual(panelNumber, panel.PanelNumber);
            Assert.AreEqual(fxOffset, panel.FxOffset);
            Assert.AreEqual(fxSpeed, panel.FxSpeed);
            Assert.AreEqual(fxType, panel.FxType);
            Assert.AreEqual(fxNumber, panel.FxNumber);
            Assert.AreEqual(redValue, panel.RedValue);
            Assert.AreEqual(greenValue, panel.GreenValue);
            Assert.AreEqual(blueValue, panel.BlueValue);
        }


        [TestMethod]
        public void Test_Panel_UpdatePanel_UpdateWrongPanel()
        {
            byte panelNumber = 15;
            byte fxOffset = 255;
            byte fxSpeed = 31;
            byte fxType = 15;
            byte fxNumber = 15;
            byte redValue = 255;
            byte greenValue = 255;
            byte blueValue = 255;

            Panel panel = new Panel(0, 0, 0, 0, 0, 0, 0, 0);

            panel.UpdatePanel(panelNumber, fxOffset, fxSpeed, fxType, fxNumber, redValue, greenValue, blueValue);

            Assert.AreNotEqual(panelNumber, panel.PanelNumber);
            Assert.AreEqual(0, panel.FxOffset);
            Assert.AreEqual(0, panel.FxSpeed);
            Assert.AreEqual(0, panel.FxType);
            Assert.AreEqual(0, panel.FxNumber);
            Assert.AreEqual(0, panel.RedValue);
            Assert.AreEqual(0, panel.GreenValue);
            Assert.AreEqual(0, panel.BlueValue);
        }

        [TestMethod]
        public void Test_Panel_ToString()
        {
            byte panelNumber = 15;
            byte fxOffset = 255;
            byte fxSpeed = 31;
            byte fxType = 15;
            byte fxNumber = 15;
            byte redValue = 255;
            byte greenValue = 255;
            byte blueValue = 255;

            Panel panel = new Panel(panelNumber, fxOffset, fxSpeed, fxType, fxNumber, redValue, greenValue, blueValue);

            string theoreticalString = "/ 15 / 255, 31, 15, 15 / 255, 255, 255 /";

            Assert.AreEqual(theoreticalString, panel.ToString());
        }

        [TestMethod]
        public void Test_Panel_ToCommand()
        {
            byte panelNumber = 15;
            byte fxOffset = 255;
            byte fxSpeed = 31;
            byte fxType = 15;
            byte fxNumber = 15;
            byte redValue = 255;
            byte greenValue = 255;
            byte blueValue = 255;

            Panel panel = new Panel(panelNumber, fxOffset, fxSpeed, fxType, fxNumber, redValue, greenValue, blueValue);

            string theoreticalString = "//ÿ/ÿÿÿ/";

            Assert.AreEqual(theoreticalString, panel.ToCommand());
        }
    }
}
