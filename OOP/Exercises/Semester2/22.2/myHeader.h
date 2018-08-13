class MyRectangle
{
	public:
		MyRectangle(double x, double y);
		MyRectangle(const MyRectangle &M);
		void calculateArea();
		double getArea();
		
	private:
		double _a;
		double _b;
		double _area;	
};