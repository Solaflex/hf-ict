using RoutePlanner.Core.Domain;
using System.Collections.Generic;

namespace RoutePlanner.Core.Repository
{
    public interface ICityRepository
    {
        int Count { get; }

        City FindByName(string name);
        IEnumerable<City> FindNeighbours(WayPoint position, double maxdist);
        List<City> FindCitiesBetween(City source, City target);
    }
}