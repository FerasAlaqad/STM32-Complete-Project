
namespace SeriPortApp2
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btn_baglan = new System.Windows.Forms.Button();
            this.labelPort = new System.Windows.Forms.Label();
            this.cb_port = new System.Windows.Forms.ComboBox();
            this.labelGelenVeri = new System.Windows.Forms.Label();
            this.labelGidecekVeri = new System.Windows.Forms.Label();
            this.btn_senddata = new System.Windows.Forms.Button();
            this.tb_sendData = new System.Windows.Forms.TextBox();
            this.lb_recievedata = new System.Windows.Forms.ListBox();
            this.btn_baglantikes = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.SuspendLayout();
            // 
            // btn_baglan
            // 
            this.btn_baglan.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btn_baglan.Location = new System.Drawing.Point(314, 330);
            this.btn_baglan.Margin = new System.Windows.Forms.Padding(4);
            this.btn_baglan.Name = "btn_baglan";
            this.btn_baglan.Size = new System.Drawing.Size(148, 42);
            this.btn_baglan.TabIndex = 19;
            this.btn_baglan.Text = "Baglan";
            this.btn_baglan.UseVisualStyleBackColor = true;
            this.btn_baglan.Click += new System.EventHandler(this.btn_baglan_Click);
            // 
            // labelPort
            // 
            this.labelPort.AutoSize = true;
            this.labelPort.Font = new System.Drawing.Font("Arial Rounded MT Bold", 8F);
            this.labelPort.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.labelPort.Location = new System.Drawing.Point(35, 52);
            this.labelPort.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelPort.Name = "labelPort";
            this.labelPort.Size = new System.Drawing.Size(36, 16);
            this.labelPort.TabIndex = 21;
            this.labelPort.Text = "Port";
            // 
            // cb_port
            // 
            this.cb_port.FormattingEnabled = true;
            this.cb_port.Location = new System.Drawing.Point(110, 47);
            this.cb_port.Margin = new System.Windows.Forms.Padding(4);
            this.cb_port.Name = "cb_port";
            this.cb_port.Size = new System.Drawing.Size(135, 24);
            this.cb_port.TabIndex = 20;
            // 
            // labelGelenVeri
            // 
            this.labelGelenVeri.AutoSize = true;
            this.labelGelenVeri.Font = new System.Drawing.Font("Arial Rounded MT Bold", 8F);
            this.labelGelenVeri.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.labelGelenVeri.Location = new System.Drawing.Point(22, 161);
            this.labelGelenVeri.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelGelenVeri.Name = "labelGelenVeri";
            this.labelGelenVeri.Size = new System.Drawing.Size(79, 16);
            this.labelGelenVeri.TabIndex = 34;
            this.labelGelenVeri.Text = "Gelen Veri";
            // 
            // labelGidecekVeri
            // 
            this.labelGidecekVeri.AutoSize = true;
            this.labelGidecekVeri.Font = new System.Drawing.Font("Arial Rounded MT Bold", 8F);
            this.labelGidecekVeri.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.labelGidecekVeri.Location = new System.Drawing.Point(22, 99);
            this.labelGidecekVeri.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelGidecekVeri.Name = "labelGidecekVeri";
            this.labelGidecekVeri.Size = new System.Drawing.Size(80, 16);
            this.labelGidecekVeri.TabIndex = 33;
            this.labelGidecekVeri.Text = "Giden Veri";
            // 
            // btn_senddata
            // 
            this.btn_senddata.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btn_senddata.Location = new System.Drawing.Point(314, 89);
            this.btn_senddata.Margin = new System.Windows.Forms.Padding(4);
            this.btn_senddata.Name = "btn_senddata";
            this.btn_senddata.Size = new System.Drawing.Size(148, 34);
            this.btn_senddata.TabIndex = 32;
            this.btn_senddata.Text = "Veri Gonder";
            this.btn_senddata.UseVisualStyleBackColor = true;
            this.btn_senddata.Click += new System.EventHandler(this.btn_senddata_Click);
            // 
            // tb_sendData
            // 
            this.tb_sendData.Location = new System.Drawing.Point(110, 93);
            this.tb_sendData.Margin = new System.Windows.Forms.Padding(4);
            this.tb_sendData.Name = "tb_sendData";
            this.tb_sendData.Size = new System.Drawing.Size(176, 22);
            this.tb_sendData.TabIndex = 31;
            // 
            // lb_recievedata
            // 
            this.lb_recievedata.FormattingEnabled = true;
            this.lb_recievedata.ItemHeight = 16;
            this.lb_recievedata.Location = new System.Drawing.Point(110, 147);
            this.lb_recievedata.Margin = new System.Windows.Forms.Padding(4);
            this.lb_recievedata.Name = "lb_recievedata";
            this.lb_recievedata.Size = new System.Drawing.Size(352, 164);
            this.lb_recievedata.TabIndex = 30;
            // 
            // btn_baglantikes
            // 
            this.btn_baglantikes.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.btn_baglantikes.Location = new System.Drawing.Point(144, 330);
            this.btn_baglantikes.Margin = new System.Windows.Forms.Padding(4);
            this.btn_baglantikes.Name = "btn_baglantikes";
            this.btn_baglantikes.Size = new System.Drawing.Size(148, 42);
            this.btn_baglantikes.TabIndex = 29;
            this.btn_baglantikes.Text = "Baglantı Kes";
            this.btn_baglantikes.UseVisualStyleBackColor = true;
            this.btn_baglantikes.Click += new System.EventHandler(this.btn_baglantikes_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(485, 414);
            this.Controls.Add(this.labelGelenVeri);
            this.Controls.Add(this.labelGidecekVeri);
            this.Controls.Add(this.btn_senddata);
            this.Controls.Add(this.tb_sendData);
            this.Controls.Add(this.lb_recievedata);
            this.Controls.Add(this.btn_baglantikes);
            this.Controls.Add(this.btn_baglan);
            this.Controls.Add(this.labelPort);
            this.Controls.Add(this.cb_port);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_baglan;
        private System.Windows.Forms.Label labelPort;
        private System.Windows.Forms.ComboBox cb_port;
        private System.Windows.Forms.Label labelGelenVeri;
        private System.Windows.Forms.Label labelGidecekVeri;
        private System.Windows.Forms.Button btn_senddata;
        private System.Windows.Forms.TextBox tb_sendData;
        private System.Windows.Forms.ListBox lb_recievedata;
        private System.Windows.Forms.Button btn_baglantikes;
        private System.IO.Ports.SerialPort serialPort1;
    }
}

