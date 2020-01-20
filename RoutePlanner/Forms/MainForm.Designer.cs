namespace Forms
{
    partial class MainForm
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
            this.route_lv = new System.Windows.Forms.ListView();
            this.from = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.to = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.distance = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.from_tb = new System.Windows.Forms.TextBox();
            this.find_btn = new System.Windows.Forms.Button();
            this.to_tb = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // route_lv
            // 
            this.route_lv.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.from,
            this.to,
            this.distance});
            this.route_lv.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.route_lv.Location = new System.Drawing.Point(3, 12);
            this.route_lv.Name = "route_lv";
            this.route_lv.Size = new System.Drawing.Size(511, 301);
            this.route_lv.TabIndex = 0;
            this.route_lv.UseCompatibleStateImageBehavior = false;
            this.route_lv.View = System.Windows.Forms.View.Details;
            // 
            // from
            // 
            this.from.Text = "From";
            this.from.Width = 138;
            // 
            // to
            // 
            this.to.Text = "To";
            this.to.Width = 166;
            // 
            // distance
            // 
            this.distance.Text = "Distance/km";
            this.distance.Width = 198;
            // 
            // from_tb
            // 
            this.from_tb.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.from_tb.Location = new System.Drawing.Point(12, 340);
            this.from_tb.Name = "from_tb";
            this.from_tb.Size = new System.Drawing.Size(199, 26);
            this.from_tb.TabIndex = 1;
            // 
            // find_btn
            // 
            this.find_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.find_btn.Location = new System.Drawing.Point(377, 405);
            this.find_btn.Name = "find_btn";
            this.find_btn.Size = new System.Drawing.Size(127, 33);
            this.find_btn.TabIndex = 2;
            this.find_btn.Text = "Find Route";
            this.find_btn.UseVisualStyleBackColor = true;
            this.find_btn.Click += new System.EventHandler(this.find_btn_Click);
            // 
            // to_tb
            // 
            this.to_tb.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.to_tb.Location = new System.Drawing.Point(243, 340);
            this.to_tb.Name = "to_tb";
            this.to_tb.Size = new System.Drawing.Size(219, 26);
            this.to_tb.TabIndex = 3;
            this.to_tb.TextChanged += new System.EventHandler(this.to_tb_TextChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(516, 450);
            this.Controls.Add(this.to_tb);
            this.Controls.Add(this.find_btn);
            this.Controls.Add(this.from_tb);
            this.Controls.Add(this.route_lv);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView route_lv;
        private System.Windows.Forms.TextBox from_tb;
        private System.Windows.Forms.Button find_btn;
        private System.Windows.Forms.ColumnHeader from;
        private System.Windows.Forms.ColumnHeader to;
        private System.Windows.Forms.ColumnHeader distance;
        private System.Windows.Forms.TextBox to_tb;
    }
}