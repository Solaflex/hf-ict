using RoutePlanner.Core.Domain;
using System.Collections.Generic;

namespace RoutePlanner.Core.Repository
{
    public interface ILinkRepository
    {
        int Count { get; }
        Link FindLink(City from, City to, Link.TransportModeEnum t);
        List<City> FindNeighbours(City c, Link.TransportModeEnum t);
    }
}