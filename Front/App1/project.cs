// A Hello World! program in C#.
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

public class Form1 : Form
{
    public  Form1() {
        //this = new Form1();
        Application.EnableVisualStyles();
        button1 = new Button();
        button1.Size = new Size(40, 40);
        button1.Location = new Point(30, 30);
        button1.Text = "Click me";
        this.Controls.Add(button1);
        //button1.Click += new EventHandler(button1_Click);
    }

    public static void setProps(ref Form f) {
        f.WindowState = FormWindowState.Maximized;
        f.TopMost = true;
        f.BackColor = Color.FromArgb(15, 15, 80);
    }

    [STAThread]
    public static void Main()
    {
        Form myForm = new Form();
        setProps(ref myForm);
        Application.Run(myForm);
        //FormBorderStyle = System.Windows.Forms.FormBorderStyle.Sizable;
    }

    public Button button1;
}