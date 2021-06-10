#include "Figures.h"

/* Circle Definition */
Circle::Circle(Point midPoint, double radius)
{
	m_midPoint = midPoint;
	m_radius = radius;
	calcPerimeter();
	calcArea();
	if (m_perimeter > m_maxPerimeter) 
		throw ReachedMaxPerimeterException("Perimeter of your figure - " + to_string(m_perimeter) + " is reached the limit - " + to_string(m_maxPerimeter));
}

Circle::Circle(const Circle& circle)
{
	m_perimeter = circle.m_perimeter;
	m_area = circle.m_area;
	m_midPoint = circle.m_midPoint;
	m_radius = circle.m_radius;
}

Circle::~Circle()
{
	cout << "\nCircle was deleted\n";
}

void Circle::calcPerimeter()
{
	m_perimeter = m_pi * m_radius;
}

void Circle::calcArea()
{
	m_area = m_pi * m_radius * m_radius;
}

/* Square Definition */
Square::Square(Point pt1, Point pt2, Point pt3, Point pt4)
{
	m_point1 = pt1;
	m_point2 = pt2;
	m_point3 = pt3;
	m_point4 = pt4;
	if (!isSquare(pt1, pt2, pt3, pt4)) 
		throw NotSquareException("Your four points don't form a square!");
	else {
		m_side = sqrt(pow(m_point1.x - m_point2.x, 2) + pow(m_point1.y - m_point2.y, 2));
		calcPerimeter();
		calcArea();
		if (m_perimeter > m_maxPerimeter) 
			throw ReachedMaxPerimeterException("Perimeter of your figure - " + to_string(m_perimeter) + " is reached the limit - " + to_string(m_maxPerimeter));
	}
}

Square::Square(const Square& square)
{
	m_perimeter = square.m_perimeter;
	m_area = square.m_area;
	m_point1 = square.m_point1;
	m_point2 = square.m_point2;
	m_point3 = square.m_point3;
	m_point4 = square.m_point4;
	m_side = square.m_side;
}

Square::~Square()
{
	cout << "\nSquare was deleted\n";
}

int Square::distSq(Point p, Point q) {
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool Square::isSquare(Point p1, Point p2, Point p3, Point p4) {

    int d2 = distSq(p1, p2); // from p1 to p2
    int d3 = distSq(p1, p3); // from p1 to p3
    int d4 = distSq(p1, p4); // from p1 to p4
 
    if (d2 == 0 || d3 == 0 || d4 == 0)   
        return false;
 
    // If lengths if (p1, p2) and (p1, p3) are same, then
    // following conditions must met to form a square.
    // 1) Square of length of (p1, p4) is same as twice
    // the square of (p1, p2)
    // 2) Square of length of (p2, p3) is same
    // as twice the square of (p2, p4)
 
    if (d2 == d3 && 2 * d2 == d4
        && 2 * distSq(p2, p4) == distSq(p2, p3)) {
        return true;
    }
 
    // The below two cases are similar to above case
    if (d3 == d4 && 2 * d3 == d2
        && 2 * distSq(p3, p2) == distSq(p3, p4)) {
        return true;
    }
    if (d2 == d4 && 2 * d2 == d3
        && 2 * distSq(p2, p3) == distSq(p2, p4)) {
        return true;
    }
 
    return false;
}

void Square::calcPerimeter()
{
	m_perimeter = m_side * 4;
}

void Square::calcArea()
{
	m_area = pow(m_side, 2);
}

ostream& operator<<(ostream& os, const Point& point)
{
	os << "(" << point.x << "," << point.y << ")";
	return os;
}

ostream& operator<<(ostream& os, const Circle& circle)
{
	os << "\nCircle, mid point: " << circle.m_midPoint << ", radius: " << circle.m_radius << ", perimeter: " << circle.m_perimeter << ", area: " << circle.m_area << endl;
	return os;
}

ostream& operator<<(ostream& os, const Square& square)
{
	os << "\nSquare, side: " << square.m_side << ", perimeter: " << square.m_perimeter << ", area: " << square.m_area << endl;
	return os;
}