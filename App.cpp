#include <iostream>
#include <string>
#include <algorithm>
#include "Exception.h"
#include "Figures.h"
#include "TFigureArray.h"

using namespace std;

void add_circle(TFigureArray<Circle*>&);
void add_square(TFigureArray<Square*>&);
void menu(TFigureArray<Circle*>&, TFigureArray<Square*>&);

int main() {
	TFigureArray<Circle*> circles;
	TFigureArray<Square*> squares;

	menu(circles, squares);

	return 0;
}

void menu(TFigureArray<Circle*>& circles, TFigureArray<Square*>& squares) {
	try {
		int choice = 0;

		//cout << circles[100]->getArea();

		while (choice != 5) {
			cout << "\n1)Add new circle" << endl;
			cout << "2)Show all circles" << endl;
			cout << "3)Add new square" << endl;
			cout << "4)Show all squares" << endl;
			cout << "5)Quit" << endl;
			cout << "Select: ";
			cin >> choice;

			if (cin.fail())
				throw InvalidChoice("Invalid Choice! Only Numbers! Try Again!");

			switch (choice) {
				case 1:
					add_circle(circles);
					break;
				case 2:
					cout << circles;
					break;
				case 3:
					add_square(squares);
					break;
				case 4:
					cout << squares;
					break;
				case 5:
					cout << "\nGoodbye! Have a nice day!" << endl;
					break;
				default:
					cout << "\nThere is no such choice! Try Again!\n";
					break;
			}
		}
	}
	catch (InvalidChoice& ex) {
		cout <<"\n" << ex.getDescription() << "\n";
		ex.outputToLogFile();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menu(circles, squares);
	}
	catch (ArrayException& ex) {
		cout << "\n" << ex.getDescription() << "\n";
		ex.outputToLogFile();
	}
	catch(NotSquareException& ex) {
		cout <<"\n" << ex.getDescription() << "\n";
		ex.outputToLogFile();
		menu(circles, squares);
	}
	catch(ReachedMaxPerimeterException& ex) {
		cout <<"\n" << ex.getDescription() << "\n";
		ex.outputToLogFile();
		menu(circles, squares);
	}
}

void add_circle(TFigureArray<Circle*>& circles) {
	Point pt;
	double radius;
	cout << "\nEnter the coordinates(x,y) of mid point by whitespace: ";
	cin >> pt.x >> pt.y;
	cout << "Enter the radius: ";
	cin >> radius;
	circles.push(new Circle(pt, radius));
}

void add_square(TFigureArray<Square*>& squares) {
	Point pt1, pt2, pt3, pt4;
	cout << "\nEnter the coordinates(x,y) of first point by whitespace: ";
	cin >> pt1.x >> pt1.y;
	cout << "\nEnter the coordinates(x,y) of second point by whitespace: ";
	cin >> pt2.x >> pt2.y;
	cout << "\nEnter the coordinates(x,y) of third point by whitespace: ";
	cin >> pt3.x >> pt3.y;
	cout << "\nEnter the coordinates(x,y) of fourth point by whitespace: ";
	cin >> pt4.x >> pt4.y;
	squares.push(new Square(pt1, pt2, pt3, pt4));
}