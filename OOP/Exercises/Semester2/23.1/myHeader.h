class Point {
	public:
		Point(double x, double y);
		Point(const Point &P);
		void setPoint(double x, double y);
		void showPoint();
		double getX() const;
		double getY() const;
		void shiftAxis(double value);
	
	private:
		double _x;
		double _y;
};