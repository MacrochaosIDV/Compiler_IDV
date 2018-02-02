namespace WF_compiladorUI
{
    partial class Main_box
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.code_box = new System.Windows.Forms.TextBox();
            this.err_box = new System.Windows.Forms.TextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.new_event_click = new System.Windows.Forms.ToolStripMenuItem();
            this.open_event_click = new System.Windows.Forms.ToolStripMenuItem();
            this.save_event_click = new System.Windows.Forms.ToolStripMenuItem();
            this.saveas_event_click = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.compileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.complie_event_click = new System.Windows.Forms.ToolStripMenuItem();
            this.lex_out_box = new System.Windows.Forms.TextBox();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // code_box
            // 
            this.code_box.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.code_box.Location = new System.Drawing.Point(12, 67);
            this.code_box.Multiline = true;
            this.code_box.Name = "code_box";
            this.code_box.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.code_box.Size = new System.Drawing.Size(1133, 366);
            this.code_box.TabIndex = 0;
            // 
            // err_box
            // 
            this.err_box.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.err_box.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.err_box.Location = new System.Drawing.Point(12, 542);
            this.err_box.Multiline = true;
            this.err_box.Name = "err_box";
            this.err_box.ReadOnly = true;
            this.err_box.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.err_box.Size = new System.Drawing.Size(1133, 97);
            this.err_box.TabIndex = 1;
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.editToolStripMenuItem,
            this.compileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1157, 28);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.new_event_click,
            this.open_event_click,
            this.save_event_click,
            this.saveas_event_click,
            this.toolStripMenuItem1,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "&File";
            // 
            // new_event_click
            // 
            this.new_event_click.Name = "new_event_click";
            this.new_event_click.Size = new System.Drawing.Size(142, 26);
            this.new_event_click.Text = "&New";
            this.new_event_click.Click += new System.EventHandler(this.new_event_click_Click);
            // 
            // open_event_click
            // 
            this.open_event_click.Name = "open_event_click";
            this.open_event_click.Size = new System.Drawing.Size(142, 26);
            this.open_event_click.Text = "&Open";
            this.open_event_click.Click += new System.EventHandler(this.open_event_click_Click);
            // 
            // save_event_click
            // 
            this.save_event_click.Name = "save_event_click";
            this.save_event_click.Size = new System.Drawing.Size(142, 26);
            this.save_event_click.Text = "&Save";
            this.save_event_click.Click += new System.EventHandler(this.save_event_click_Click);
            // 
            // saveas_event_click
            // 
            this.saveas_event_click.Name = "saveas_event_click";
            this.saveas_event_click.Size = new System.Drawing.Size(142, 26);
            this.saveas_event_click.Text = "Save as...";
            this.saveas_event_click.Click += new System.EventHandler(this.saveas_event_click_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(139, 6);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(142, 26);
            this.exitToolStripMenuItem.Text = "&Exit";
            // 
            // editToolStripMenuItem
            // 
            this.editToolStripMenuItem.Name = "editToolStripMenuItem";
            this.editToolStripMenuItem.Size = new System.Drawing.Size(47, 24);
            this.editToolStripMenuItem.Text = "Edit";
            // 
            // compileToolStripMenuItem
            // 
            this.compileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.complie_event_click});
            this.compileToolStripMenuItem.Name = "compileToolStripMenuItem";
            this.compileToolStripMenuItem.Size = new System.Drawing.Size(77, 24);
            this.compileToolStripMenuItem.Text = "Compile";
            // 
            // complie_event_click
            // 
            this.complie_event_click.Name = "complie_event_click";
            this.complie_event_click.Size = new System.Drawing.Size(140, 26);
            this.complie_event_click.Text = "&Compile";
            this.complie_event_click.Click += new System.EventHandler(this.complie_event_click_Click);
            // 
            // lex_out_box
            // 
            this.lex_out_box.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.lex_out_box.Font = new System.Drawing.Font("Arial", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lex_out_box.Location = new System.Drawing.Point(12, 439);
            this.lex_out_box.Multiline = true;
            this.lex_out_box.Name = "lex_out_box";
            this.lex_out_box.ReadOnly = true;
            this.lex_out_box.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.lex_out_box.Size = new System.Drawing.Size(1133, 97);
            this.lex_out_box.TabIndex = 3;
            // 
            // Main_box
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1157, 651);
            this.Controls.Add(this.lex_out_box);
            this.Controls.Add(this.err_box);
            this.Controls.Add(this.code_box);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Main_box";
            this.Text = "Compiler IDV";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox code_box;
        private System.Windows.Forms.TextBox err_box;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem new_event_click;
        private System.Windows.Forms.ToolStripMenuItem open_event_click;
        private System.Windows.Forms.ToolStripMenuItem save_event_click;
        private System.Windows.Forms.ToolStripMenuItem saveas_event_click;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem compileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem complie_event_click;
        private System.Windows.Forms.ToolStripMenuItem editToolStripMenuItem;
        private System.Windows.Forms.TextBox lex_out_box;
    }
}

