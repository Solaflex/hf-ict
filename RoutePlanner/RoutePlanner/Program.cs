

using RoutePlanner.Core;
using RoutePlanner.Core.Domain;
using RoutePlanner.Core.Repository;
using RoutePlanner.Properties;

namespace RoutePlanner
{
    class Program
    {
        static void PrintWayPoint(WayPoint position)
        {
            System.Console.WriteLine(position);
        }
        static void PrintDistance()
        {
            WayPoint bern = new WayPoint("Bern", 46.95, 7.44);
            WayPoint berlin = new WayPoint("Berlin", 52.52, 13.38);
            System.Console.WriteLine("Distanz {0} -> {1}: {2} km",
                bern.Name, berlin.Name, bern.Distance(berlin));
        }
        static void PrintNeighbours(ICityRepository cityRepos,
            WayPoint w)
        {
            foreach (City n in cityRepos.FindNeighbours(w, 60))
            {
                System.Console.WriteLine(n);
            }

        }
        static void PrintLinkNeighbours(ILinkRepository linkRepos,
            City c)
        {
            foreach (City n in linkRepos.FindNeighbours(c,
                      Link.TransportModeEnum.Rail))
            {
                System.Console.WriteLine(n);
            }
        }
        static void Main(string[] args)
        {
            WayPoint pratteln = new WayPoint("Pratteln",
               47.5167, 7.6833);
            //PrintWayPoint(pratteln);
            //PrintDistance();

            ICityRepository cityRepos =
                new CityRepositoryFile(Settings.Default.Cities);
            System.Console.WriteLine("Total Cities "+ cityRepos.Count);
            // PrintNeighbours(cityRepos, pratteln);
            ILinkRepository linkRepos = 
                new LinkRepositoryFile(
                Settings.Default.Links, cityRepos);
            System.Console.WriteLine("Total Links " + linkRepos.Count);
            //City basel = cityRepos.FindByName("Basel");
            // PrintLinkNeighbours(linkRepos, basel);
            RouteManager routeManager = new RouteManager(cityRepos, linkRepos);
            foreach(Link l in routeManager.FindShortestRouteBetween(
                "Basel", "Lyon",
                Link.TransportModeEnum.Rail)){
                System.Console.WriteLine(l);
            }
           System.Console.ReadKey();
        }
    }
}
