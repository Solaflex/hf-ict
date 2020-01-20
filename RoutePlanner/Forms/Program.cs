using RoutePlanner.Core.Repository;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using RoutePlanner.Properties;
using RoutePlanner.Core;

namespace Forms
{
    static class Program
    {
        /// <summary>
        /// Der Haupteinstiegspunkt für die Anwendung.
        /// </summary>
        [STAThread]
        static void Main()
        {
            ICityRepository cityRepos =
               new CityRepositoryFile(
                   "data/cities.txt");
            ILinkRepository linkRepos =
                new LinkRepositoryFile("data/links.txt", cityRepos);
            RouteManager routeManager = new RouteManager(cityRepos, linkRepos);

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm(routeManager));
        }
    }

    internal class Settings
    {
    }
}
