using System;

using System.IO.Ports;
using System.Windows.Forms;

namespace SeriPortApp2
{
    public partial class Form1 : Form
    {
        private string veri;

        public Form1()
        {
           
            InitializeComponent();

            string[] ports = SerialPort.GetPortNames(); // aktif portlari bulmak  
            foreach (string portName in ports)
            {
                cb_port.Items.Add(portName);
            }

            serialPort1.DataReceived += new SerialDataReceivedEventHandler(SerialPort1_DataReceived);
            serialPort1.NewLine = "\n";
        }
        private void SerialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            veri = serialPort1.ReadLine();
            this.Invoke(new EventHandler(displayData_event));
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (serialPort1.IsOpen) serialPort1.Close();    
        }

        private void displayData_event(object sender, EventArgs e)
        {
            lb_recievedata.Items.Add(veri);
            try
            {
                const string sPath = "log.txt";  //dosya olusturmak
                System.IO.StreamWriter SaveFile = new System.IO.StreamWriter(sPath);

                foreach (var item in lb_recievedata.Items)
                {
                    SaveFile.WriteLine(item);  // yazdirmak
                }
                SaveFile.Close();      
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex + "Hata");
            }

        }

        private void btn_baglan_Click(object sender, EventArgs e)
        {
            serialPort1.BaudRate = 9600;
            try
            {
                serialPort1.PortName = cb_port.Text;
                if (!serialPort1.IsOpen)
                {
                    serialPort1.Open();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message + "Hata");
            }
        }

        private void btn_senddata_Click(object sender, EventArgs e)
        {
            serialPort1.Write(tb_sendData.Text);
        }

        private void btn_baglantikes_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }


    }
}