#include "stdafx.h"
#include "NeighborsSearchMethod.h"

num Salesman::NeighborsSearchMethod::getNeighbor(num city, set X, const matrix & data, value * ref_distance) {
	//numset neighbors;
	num neighbor = X[0];
	value min = data[city - 1][neighbor - 1];
	clog << "distance for city " << city << ": "; PrintVectorValue(data[city - 1], true);clog << endl;
	for (num xk : X) {
		value distance = data[city - 1][xk - 1];
		if (distance < min) {
			min = distance;
			neighbor = xk;
		}
	}
	if (ref_distance != nullptr)*ref_distance = min;
	//clog << "------" << min << "-------";
	clog << "neighbor city:" << neighbor << ": distance " << min << endl;
	return neighbor;
}

Salesman::NeighborsSearchMethod::NeighborsSearchMethod(matrix data, int randomSeed) :AbstractSalesmanSearchMethod(data), size(data.size()) { srand(randomSeed); }

DispacementVector Salesman::NeighborsSearchMethod::find() {
	printMatrix();
	DispacementVector returnedvector(size);
	set X;
	for (size_t i = 1; i <= size; i++)
	{
		X.push_back(i);
	}
	random_shuffle(X.begin(), X.end());
	num xi = *X.begin();
	num first_x = xi;
	X.erase(X.begin());
	num si = xi;
	int i = 1;
	clog << "Iter1 si:" << si << endl;
	returnedvector.setNum(i, si);
	value distancev = 0;
	while (X.size() > 0)
	{
		i++;
		value ref_distance = 0;
		xi = getNeighbor(si, X, getMatrix(), &ref_distance);
		distancev += ref_distance;
		//clog << "+++" << distancev << "+++";
		X.erase(std::find(X.begin(), X.end(), xi));
		si = xi;
		returnedvector.setNum(i, si);
		clog << "Iter" << i << " si:" << si << endl;

	}
	cout << "from " << si << " to " << first_x << ":" << getMatrix()[si - 1][first_x - 1] << endl;
	distancev += getMatrix()[si - 1][first_x - 1];
	clog << returnedvector << ":" << distancev << endl;
	return returnedvector;
}
