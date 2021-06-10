#include "TFigureArray.h"

template<class T>
TFigureArray<T>::~TFigureArray()
{
	for (unsigned long i = 0; i < m_figures.size(); i++) {
		delete m_figures[i];
	}
}

template<class T>
T& TFigureArray<T>::operator[](unsigned long index)
{
	if (index >= m_figures.size())
		throw ArrayException("Your index is " + to_string(index) + ", It's invalid index!");
	return m_figures[index];
}

template<class T>
void TFigureArray<T>::push(T figure)
{
	m_figures.push_back(figure);
}

template class TFigureArray<Circle*>;
template class TFigureArray<Square*>;