using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
//using Compiler_code_logic_thing

namespace WF_compiladorUI
{
    public partial class Main_box : Form
    {
        private string currentFilename;
        Compiler_code_logic_thing.Manager compiler;
        

        public Main_box()
        {
            InitializeComponent();

            currentFilename = "";
            compiler = new Compiler_code_logic_thing.Manager();
        }

        private void saveCodeFast() {

            string str_code = code_box.Text.Trim();
            StreamWriter outWriter = new StreamWriter(currentFilename, false);
            outWriter.Write(str_code);
            outWriter.Flush();
            outWriter.Close();
        }

        /// <summary>
        /// 
        /// </summary>
        private void saveCode()
        {
            SaveFileDialog saveDialog = new SaveFileDialog();
            saveDialog.Filter = "Text file|*.txt";
            saveDialog.Title = "Save code";
            saveDialog.ShowDialog();

            if (saveDialog.FileName != "")
            {
                currentFilename = saveDialog.FileName;
                saveCodeFast();
            }
        }

        private void new_event_click_Click(object sender, EventArgs e)
        {
            if(code_box.Text.Trim() != "")
            {
                DialogResult answer = MessageBox.Show("Save current data?", "Save?", MessageBoxButtons.YesNoCancel);
                if(answer == DialogResult.Yes)
                {
                    saveCode();
                    code_box.Clear();
                }
                if (answer == DialogResult.No)
                {
                    code_box.Clear();
                }
            }
        }

        private void save_event_click_Click(object sender, EventArgs e)
        {
            if(currentFilename == "")
            {
                saveCode();
            }
            else
            {
                saveCodeFast();
            }
        }

        private void saveas_event_click_Click(object sender, EventArgs e)
        {
            saveCode();
        }

        private void open_event_click_Click(object sender, EventArgs e)
        {
            if(currentFilename != "")
            {
                saveCodeFast();
            }
            else
            {
                new_event_click_Click(sender, e);
            }

            OpenFileDialog openDialog = new OpenFileDialog();
            openDialog.Filter = "Text file|*.txt";
            openDialog.Title = "Load code";
            openDialog.CheckFileExists = true;
            openDialog.ShowDialog();

            if (openDialog.FileName != "") {
                
                StreamReader inWriter = new StreamReader(openDialog.FileName);
                string contents = inWriter.ReadToEnd();
                inWriter.Close();
                code_box.Text = contents;
            }
        }

        private void complie_event_click_Click(object sender, EventArgs e)
        {
            string[] details = compiler.compile(code_box.Text);
            err_box.Lines = details;
            string[] tokens = compiler.getAllTokens();
            lex_out_box.Lines = tokens;
        }
    }
}
