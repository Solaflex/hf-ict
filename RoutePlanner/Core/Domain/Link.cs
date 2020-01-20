
namespace RoutePlanner.Core.Domain
{
    public class Link
    {
        public enum TransportModeEnum { Ship, Rail, Flight, Road};
        public City FromCity { get; private set; }
        public City ToCity { get; private set; }
        public TransportModeEnum TransportMode { get; private set; }
        public double Distance { get {
                return FromCity.Location.Distance(ToCity.Location); } }

        public Link(City from, City to, TransportModeEnum mode)
        {
            FromCity = from;
            ToCity = to;
            TransportMode = mode;
        }

        public override string ToString()
        {
            return string.Format("{0:-20} -- {1:-20} : {2,10:0.0}",
            FromCity.Name, ToCity.Name,
            FromCity.Location.Distance(ToCity.Location));
        }
    }
}
