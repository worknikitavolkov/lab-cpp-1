#pragma once

#include <cmath>
#include <iostream>
#include "Exception.h"

using namespace std;

struct Point {
	double x;
	double y;
	friend ostream& operator<<(ostream& os, const Point& point);
};

class Figure {
	protected:
		const double m_maxPerimeter = 40;
		const double m_pi = 3.14;
		double m_perimeter;
		double m_area;
		virtual void calcPerimeter() = 0;
		virtual void calcArea() = 0;
	public:
		virtual ~Figure() = default;
		virtual inline double getPerimeter() = 0;
		virtual inline double getArea() = 0;
};

class Circle : public Figure {
	private:
		Point m_midPoint;
		double m_radius;
		void calcPerimeter() override;
		void calcArea() override;
	public:
		Circle(Point midPoint, double radius);
		Circle(const Circle& circle);
		~Circle();
		friend ostream& operator<<(ostream& os, const Circle& circle);
		inline double getPerimeter() { return m_perimeter; };
		inline double getArea() { return m_area; };
};

class Square : public Figure {
	private:
		Point m_point1, m_point2, m_point3, m_point4;
		double m_side;
		void calcPerimeter() override;
		void calcArea() override;
		int distSq(Point p, Point q);
		bool isSquare(Point p1, Point p2, Point p3, Point p4);
	public:
		Square(Point pt1, Point pt2, Point pt3, Point pt4);
		Square(const Square& square);
		~Square();
		friend ostream& operator<<(ostream& os, const Square& square);
		inline double getPerimeter() { return m_perimeter; };
		inline double getArea() { return m_area; };
};