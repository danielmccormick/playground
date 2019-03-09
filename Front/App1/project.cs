using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

public class Form1 : Form
{
    public  Form1() {
        
        Application.EnableVisualStyles();

        this.WindowState = FormWindowState.Maximized;
        this.TopMost = true;
        this.BackColor = Color.FromArgb(15, 15, 80);

        button1 = new Button();
        button1.Size = new Size(40, 40);
        button1.Location = new Point(30, 30);
        button1.Text = "Click me";
        this.Controls.Add(button1);
 q
    }
    private void button1_Click(object sender, EventArgs e)
    {
        MessageBox.Show("Hello World");
    }


    public static void setProps(ref Form f) {
        f.WindowState = FormWindowState.Maximized;
        f.TopMost = true;
        f.BackColor = Color.FromArgb(22, 22, 9); // The colour is Eigengrau
    }

    [STAThread]
    public static void Main()
    {

        Application.Run(new Form1());
    }

    public Button button1;
}