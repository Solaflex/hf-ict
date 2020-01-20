using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoutePlanner.Core.Domain 
{
    public class City : IEquatable<City>
    {
        public WayPoint Location { get; private set; }
        public string Name { get; private set; }
        public int Population { get; private set; }
        public string Country { get; private set; }

        public City(string name, double lat, double lon, int pop, string country)
        {
            Name = name;
            Location = new WayPoint(name, lat, lon);
            Population = pop;
            Country = country;
        }
        public override string ToString()
        {
            return System.String.Format("City: {0}", Name);
        }
        public bool Equals(City other)
        {
            return other != null &&
                   Name == other.Name &&
                   Country == other.Country;
        }

        public override int GetHashCode()
        {
            var hashCode = 622225511;
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Name);
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Country);
            return hashCode;
        }
    }
}
