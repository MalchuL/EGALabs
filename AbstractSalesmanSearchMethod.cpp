#include "stdafx.h"
#include "AbstractSalesmanSearchMethod.h"
using namespace Salesman;
void Salesman::AbstractSalesmanSearchMethod::printMatrix() {
	const matrix& matr = getMatrix();
	for (auto row : matr) {
		PrintVectorValue(row, false);clog << endl;
	}
}

void Salesman::AbstractSalesmanSearchMethod::printSet(set X) {
	clog << "[";
	for (num xi : X) {
		clog << xi << ",";
	}
	clog << "]";
}

void Salesman::AbstractSalesmanSearchMethod::PrintVectorValue(const vector<value>& X, bool printIndex) {
	clog << "[";
	int i = 0;
	for (num xi : X) {
		i++;
		if (printIndex)
		{
			clog << i << ":" << xi << ",";
		}
		else
		{
			clog << xi << ",";
		}
	}
	clog << "]";
}

inline const matrix Salesman::AbstractSalesmanSearchMethod::getMatrix() {
	return data;
}

value Salesman::AbstractSalesmanSearchMethod::getDistance(int i, int j) {
	return data[i][j];
}

Salesman::AbstractSalesmanSearchMethod::AbstractSalesmanSearchMethod(const matrix & data) :data(data) {

}
