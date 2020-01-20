using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using RoutePlanner.Core.Domain;

namespace RoutePlanner.Core.Repository
{
    public class LinkRepositoryFile : ILinkRepository
    {
        List<Link> links = new List<Link>();
        public LinkRepositoryFile(string filename,
            ICityRepository cityRepository)
        {
            using (StreamReader reader = new StreamReader(filename))
            {
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    string[] cells = line.Split('\t');
                    try
                    {
                        City from = cityRepository.FindByName(
                            cells[0].Trim());
                        City to = cityRepository.FindByName(
                            cells[1].Trim());
                        Link link = new Link(from, to,
                            Link.TransportModeEnum.Rail);
                        links.Add(link);
                    }catch(Exception ex)
                    {
                        System.Console.WriteLine(
                            "ConversionError {0} {1}", ex, line);
                    }
                }
            }
        }
        public int Count { get { return links.Count; } }

        public Link FindLink(City from, City to, Link.TransportModeEnum t)
        {
            return links.Find(l =>
            (l.FromCity.Equals(from) &&
            l.ToCity.Equals(to) ||
            l.FromCity.Equals(to) &&
            l.ToCity.Equals(from)) && l.TransportMode==t);
        }

        public List<City> FindNeighbours(City
            c, Link.TransportModeEnum t)
        {
            return (from l in links
                    where l.FromCity.Equals(c)
                    select l.ToCity).Union(
                from l in links
                where l.ToCity.Equals(c)
                select l.FromCity).ToList();
        }
    }
}
