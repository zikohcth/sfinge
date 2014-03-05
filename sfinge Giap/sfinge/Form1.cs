using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace sfinge
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();


        }

        private void btnGenerate_Click(object sender, EventArgs e)
        {

        }

        private void frm1_Load(object sender, EventArgs e)
        {
            cbFinger.SelectedIndex = 1;
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            Form2 frm = new Form2();
            frm.Show();
            frm.SetBounds(this.Location.X, this.Location.Y, this.Width, this.Height);
            this.Hide();


      
            //frm.ShowDialog();
       





        }
    }
}
