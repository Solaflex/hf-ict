using RoutePlanner.Core;
using RoutePlanner.Core.Domain;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Forms
{
    public partial class MainForm : Form
    {
        RouteManager routeManager;
        public MainForm(RouteManager routeManager)
        {
            this.routeManager = routeManager;
            InitializeComponent();
        }

        private void find_btn_Click(object sender, EventArgs e)
        {
            foreach (Link l in routeManager.FindShortestRouteBetween(
                from_tb.Text, to_tb.Text,
                Link.TransportModeEnum.Rail))
            {
                ListViewItem lvi = new ListViewItem(l.FromCity.Name);
                lvi.SubItems.Add(l.ToCity.Name);
                lvi.SubItems.Add(String.Format("{0,10:#.#}",
                    l.Distance));
                route_lv.Items.Add(lvi);
            }
        }

        private void to_tb_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
