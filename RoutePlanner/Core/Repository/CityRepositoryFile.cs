using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using RoutePlanner.Core.Domain;

namespace RoutePlanner.Core.Repository
{
    public class CityRepositoryFile : ICityRepository
    {
        List<City> cities = new List<City>();
        public CityRepositoryFile(string filename)
        {
            using (StreamReader reader = new StreamReader(filename))
            {
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    string[] cells = line.Split('\t');
                    double lat = double.Parse(cells[3], 
                        CultureInfo.InvariantCulture); // verhindert Konvertierungsproblem mit Dezimaltrennzeichen
                    double lon = double.Parse(cells[4],
                        CultureInfo.InvariantCulture);
                    int pop = int.Parse(cells[2]);
                    string name = cells[0].Trim();
                    string country = cells[1].Trim();
                    City c = new City(name, lat, lon, pop, country);
                    cities.Add(c);
                }
            }
        }

        public City FindByName(string name)
        {
            return cities.FindLast(c => c.Name.Equals(name));
        }

        public IEnumerable<City> FindNeighbours(WayPoint position, double maxdist)
        {
            List<City> neighbours = new List<City>();
            foreach (City c in cities)
            {
                if (c.Location.Distance(position) < maxdist)
                {
                    neighbours.Add(c);
                }
            }
            return neighbours;
        }

        public IEnumerable<City> FindNeighboursDelegate(WayPoint position,
            double maxdist)
        {
            return cities.FindAll(delegate (City city)
            {
                return city.Location.Distance(position) < maxdist;
            }
            );
        }
        public IEnumerable<City> FindNeighboursLambda(WayPoint position,
             double maxdist)
        {
            return cities.FindAll(
                city => city.Location.Distance(position) < maxdist);
        }
        public IEnumerable<City> FindNeighboursLinq(WayPoint position,
             double maxdist)
        {
            return from c in cities
                   where c.Location.Distance(position) < maxdist
                   select c;
        }

        public List<City> FindCitiesBetween(City source, City target)
        {
            double minLat = Math.Min(source.Location.Latitude,
                target.Location.Latitude);
            double maxLat = Math.Max(source.Location.Latitude,
                target.Location.Latitude);
            double minLon = Math.Min(source.Location.Longitude,
                target.Location.Longitude);
            double maxLon = Math.Max(source.Location.Longitude,
                target.Location.Longitude);
            double delta = Math.Max(0.5 * (maxLat - minLat),
                0.5 * (maxLon - minLon));
            return cities.FindAll(c =>
           c.Location.Latitude > minLat - delta &&
           c.Location.Latitude < maxLat + delta &&
           c.Location.Longitude > minLon - delta &&
           c.Location.Longitude < maxLon + delta);
        }

        public int Count { get { return cities.Count; } }
    }
}