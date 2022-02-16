using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Trinity;

namespace TrinityTestProject
{
    [TestClass]
    public class PresetTests
    {
        [TestMethod]
        public void Test_Preset_Constructor()
        {
            string testName = "testName";
            string testDesigner = "testDesigner";
            string testCollection = "testCollection";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);

            Assert.AreEqual(preset.Name, testName);
            Assert.AreEqual(preset.Designer, testDesigner);
            Assert.AreEqual(preset.Collection, testCollection);
            Assert.AreEqual(preset.DesignedFor, testDesignedFor);
            Assert.AreEqual(preset.Brightness, testBrightness);
            Assert.AreEqual(preset.Slowness, testSlowness);
            Assert.AreEqual(preset.LatestFavourite, false);
        }

        [TestMethod]
        public void Test_Preset_Constructor_NoStrings()
        {
            string testName = "";
            string testDesigner = "";
            string testCollection = "";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);

            Assert.AreEqual(preset.Name, "noName");
            Assert.AreEqual(preset.Designer, "noDesigner");
            Assert.AreEqual(preset.Collection, "noCollection");
            Assert.AreEqual(preset.DesignedFor, testDesignedFor);
            Assert.AreEqual(preset.Brightness, testBrightness);
            Assert.AreEqual(preset.Slowness, testSlowness);
            Assert.AreEqual(preset.LatestFavourite, false);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void Test_MultiplierMap_Constructor_NoDesignedFor()
        {
            string testName = "";
            string testDesigner = "";
            string testCollection = "";
            string testDesignedFor = "";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);

            Assert.AreEqual(preset, null);

            Assert.AreEqual(preset.Name, null);
            Assert.AreEqual(preset.Designer, null);
            Assert.AreEqual(preset.Collection, null);
            Assert.AreEqual(preset.DesignedFor, null);
            Assert.AreEqual(preset.Brightness, null);
            Assert.AreEqual(preset.Slowness, null);
            Assert.AreEqual(preset.LatestFavourite, null);
        }


        [TestMethod]
        public void Test_Preset_AddPresetPanel_correct()
        {
            string testName = "testName";
            string testDesigner = "testDesigner";
            string testCollection = "testCollection";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);
            Panel panel = new Panel(1, 2, 3, 4, 5, 6, 7, 8);
            preset.AddPresetPanel(panel);

            Panel foundPanel = preset.FindPresetPanel(1);


            Assert.AreEqual(preset.PresetPanels.Count, 1);

            Assert.AreEqual(foundPanel.PanelNumber, 1);
            Assert.AreEqual(foundPanel.FxOffset, 2);
            Assert.AreEqual(foundPanel.FxSpeed, 3);
            Assert.AreEqual(foundPanel.FxType, 4);
            Assert.AreEqual(foundPanel.FxNumber, 5);
            Assert.AreEqual(foundPanel.RedValue, 6);
            Assert.AreEqual(foundPanel.GreenValue, 7);
            Assert.AreEqual(foundPanel.BlueValue, 8);
        }


        [TestMethod]
        public void Test_Preset_AddPresetPanel_Add2SamePanels()
        {
            string testName = "testName";
            string testDesigner = "testDesigner";
            string testCollection = "testCollection";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);
            Panel panel1 = new Panel(1, 2, 3, 4, 5, 6, 7, 8);
            Panel panel2 = new Panel(1, 9, 9, 9, 9, 9, 9, 9);
            preset.AddPresetPanel(panel1);
            preset.AddPresetPanel(panel2);

            Panel foundPanel = preset.FindPresetPanel(1);


            Assert.AreEqual(preset.PresetPanels.Count, 1);

            Assert.AreEqual(1, foundPanel.PanelNumber);
            Assert.AreEqual(2, foundPanel.FxOffset);
            Assert.AreEqual(3, foundPanel.FxSpeed);
            Assert.AreEqual(4, foundPanel.FxType);
            Assert.AreEqual(5, foundPanel.FxNumber);
            Assert.AreEqual(6, foundPanel.RedValue);
            Assert.AreEqual(7, foundPanel.GreenValue);
            Assert.AreEqual(8, foundPanel.BlueValue);


        }


        [TestMethod]
        [ExpectedException(typeof(System.NullReferenceException))]
        public void Test_Preset_AddPresetPanel_AddCorruptedPanel()
        {
            string testName = "testName";
            string testDesigner = "testDesigner";
            string testCollection = "testCollection";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);
            Panel panel1 = preset.FindPresetPanel(0);
            preset.AddPresetPanel(panel1);

            Panel foundPanel = preset.FindPresetPanel(0);


            Assert.AreEqual(0, preset.PresetPanels.Count);
            Assert.AreEqual(null, foundPanel);

            Assert.AreEqual(null, foundPanel.PanelNumber);
            Assert.AreEqual(null, foundPanel.FxOffset);
            Assert.AreEqual(null, foundPanel.FxSpeed);
            Assert.AreEqual(null, foundPanel.FxType);
            Assert.AreEqual(null, foundPanel.FxNumber);
            Assert.AreEqual(null, foundPanel.RedValue);
            Assert.AreEqual(null, foundPanel.GreenValue);
            Assert.AreEqual(null, foundPanel.BlueValue);
        }


        [TestMethod]
        public void Test_Preset_FindPresetPanel_Correct()
        {
            string testName = "testName";
            string testDesigner = "testDesigner";
            string testCollection = "testCollection";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);

            Panel panel1 = new Panel(1, 2, 3, 4, 5, 6, 7, 8);
            preset.PresetPanels.Add(panel1);


            Panel foundPanel = preset.FindPresetPanel(1);


            Assert.AreEqual(1, preset.PresetPanels.Count);

            Assert.AreEqual(1, foundPanel.PanelNumber);
            Assert.AreEqual(2, foundPanel.FxOffset);
            Assert.AreEqual(3, foundPanel.FxSpeed);
            Assert.AreEqual(4, foundPanel.FxType);
            Assert.AreEqual(5, foundPanel.FxNumber);
            Assert.AreEqual(6, foundPanel.RedValue);
            Assert.AreEqual(7, foundPanel.GreenValue);
            Assert.AreEqual(8, foundPanel.BlueValue);
        }


        [TestMethod]
        [ExpectedException(typeof(System.NullReferenceException))]
        public void Test_Preset_FindPresetPanel_Nonexistent()
        {
            string testName = "testName";
            string testDesigner = "testDesigner";
            string testCollection = "testCollection";
            string testDesignedFor = "testDesignedFor";
            byte testBrightness = 100;
            byte testSlowness = 100;

            Preset preset = new Preset(testName, testDesigner, testCollection, testDesignedFor, testBrightness, testSlowness);

            Panel foundPanel = preset.FindPresetPanel(0);


            Assert.AreEqual(0, preset.PresetPanels.Count);
            Assert.AreEqual(null, foundPanel);

            Assert.AreEqual(null, foundPanel.PanelNumber);
            Assert.AreEqual(null, foundPanel.FxOffset);
            Assert.AreEqual(null, foundPanel.FxSpeed);
            Assert.AreEqual(null, foundPanel.FxType);
            Assert.AreEqual(null, foundPanel.FxNumber);
            Assert.AreEqual(null, foundPanel.RedValue);
            Assert.AreEqual(null, foundPanel.GreenValue);
            Assert.AreEqual(null, foundPanel.BlueValue);
        }




    }
}
