#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Figures.h"
#include "Exception.h"

using namespace std;

template<class T> class TFigureArray;

template<class T>
class TFigureArray {
private:
	vector<T> m_figures;
public:
	TFigureArray() = default;

	~TFigureArray();

	T& operator[](unsigned long index);

	void push(T figure);

	friend ostream& operator<<(ostream& os, const TFigureArray<T>& figures) {
		if (figures.m_figures.empty()) os << "\nNo items! Try to add one!\n";
		else {
			for (unsigned long i = 0; i < figures.m_figures.size(); i++) {
				os << *(figures.m_figures[i]);
			}
		}
		return os;
	}
};