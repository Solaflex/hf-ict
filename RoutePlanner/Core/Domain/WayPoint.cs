using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoutePlanner.Core.Domain
{
    public class WayPoint
    {
        public double Latitude { get; private set; }
        public double Longitude { get; private set; }
        public string Name { get; private set; }

        public WayPoint(string name, double lat, double lon)
        {
            Name = name;
            Latitude = lat;
            Longitude = lon;
        }
        public override string ToString()
        {
            double lonmin = (Longitude - (int)Longitude) * 60;
            double latmin = (Latitude - (int)Latitude) * 60;
            return System.String.Format(
                "WayPoint: {0} {1}° {2:##}' / {3}° {4:##}'", Name, 
                (int)Latitude, latmin,
                (int)Longitude, lonmin);
        }

        public double Distance(WayPoint other)
        {
            double R = 6371.0;
            double phia = Latitude * Math.PI / 180;
            double phib = other.Latitude * Math.PI / 180;
            double lama = Longitude * Math.PI / 180;
            double lamb = other.Longitude * Math.PI / 180;
            return R * Math.Acos(Math.Sin(phia) * Math.Sin(phib) +
                Math.Cos(phia) * Math.Cos(phib) * Math.Cos(lama - lamb));
        }
    }
}
