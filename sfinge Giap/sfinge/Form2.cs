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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            cbFC.SelectedIndex = 1;
            cbVC.SelectedIndex = 0;
        }

        private void Form2_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            Form3 frm = new Form3();
            frm.Show();
            frm.SetBounds(this.Location.X, this.Location.Y, this.Width, this.Height);
            this.Hide();
        }

    }
}
