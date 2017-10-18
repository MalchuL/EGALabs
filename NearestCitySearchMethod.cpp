#include "stdafx.h"
#include "NearestCitySearchMethod.h"
using namespace Salesman;
num Salesman::NearestCitySearchMethod::getNeighbor(num city, set X, const matrix & data, value * ref_distance) {
	//numset neighbors;
	num neighbor = X[0];
	value min = data[city - 1][neighbor - 1];
	for (num xk : X) {
		value distance = data[city - 1][xk - 1];
		if (distance < min) {
			min = distance;
			neighbor = xk;
		}
	}
	if (ref_distance != nullptr)*ref_distance = min;
	return neighbor;
}

//������ �������� ������������� �������� - �������, � ������ - ����� ���� ��������

tuple<num, num> Salesman::NearestCitySearchMethod::getNearestNeighbor(set cities, set X, const matrix & data) {

	clog << "cities:";
	printSet(cities);
	clog << endl;
	clog << "X:";
	printSet(X);
	clog << endl;
	value min = 0;
	num neighbor = getNeighbor(cities[0], X, data, &min);


	tuple<num, num> min_tuple(cities[0], neighbor);
	clog << "min distances:[";
	for (num city : cities) {


		value temp_min = 0;
		neighbor = getNeighbor(city, X, data, &temp_min);
		if (temp_min < min) {
			min = temp_min;
			min_tuple = tuple<num, num>(city, neighbor);
		}
		clog << "from " << city << " to " << neighbor << " distance: " << temp_min << "," << endl;
	}
	clog << "]" << endl;
	//clog << "------" << min << "-------";
	clog << "nearest neighbor ";
	clog << "from:" << get<0>(min_tuple) << " to:" << get<1>(min_tuple) << ": distance " << min << endl;
	return min_tuple;
}

void Salesman::NearestCitySearchMethod::printDisplacementPart(DispacementVector & vector, int from, int to) {
	clog << "(";
	for (size_t i = from; i <= to; i++)
	{
		clog << vector.getNum(i) << ",";
	}
	clog << ")";
}

Salesman::NearestCitySearchMethod::NearestCitySearchMethod(matrix data, int randomSeed) :AbstractSalesmanSearchMethod(data), size(data.size()) { srand(randomSeed); }

DispacementVector Salesman::NearestCitySearchMethod::find() {
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
	int iteration = 1;
	clog << "Iteration " << iteration << endl;
	returnedvector.setNum(iteration, si);
	set usedCities;
	usedCities.push_back(si);
	clog << "si:";
	printDisplacementPart(returnedvector, 1, iteration);
	clog << endl;
	while (X.size() > 0)
	{
		iteration++;

		clog << "Iteration " << iteration << endl;
		//��������� �� ������ ������ �� ������ ����������� �������
		tuple<num, num> nearestCity = getNearestNeighbor(usedCities, X, getMatrix());
		num fromCity = get<0>(nearestCity);
		num toCity = get<1>(nearestCity);
		//
		//������ ����� ������������ ��� �����
		clog << "si before:";
		printDisplacementPart(returnedvector, 1, iteration - 1);
		clog << endl;
		for (int city = 1; city < iteration; city++)
		{
			if (returnedvector.getNum(city) == fromCity) {
				returnedvector.InsertWithRightOffset(city + 1, toCity);
				break;
			}
		}


		usedCities.push_back(toCity);
		X.erase(std::find(X.begin(), X.end(), toCity));
		si = toCity;
		clog << "si after:";
		printDisplacementPart(returnedvector, 1, iteration);
		clog << endl << endl;


	}

	cout << "from " << si << " to " << first_x << ":" << getMatrix()[si - 1][first_x - 1] << endl;
	value distancev = calculateDistance(getMatrix(), returnedvector);
	clog << returnedvector << ":" << distancev << endl;
	return returnedvector;

}

value Salesman::NearestCitySearchMethod::calculateDistance(matrix data, DispacementVector path) {
	value distance = 0;
	for (size_t city = 1; city <= path.getSize(); city++)
	{
		num from = path.getNum(city);

		num to = path.getNum((city + 1)>path.getSize() ? 1 : city + 1);
		//	clog << from <<" "<< to <<" "<<data[from-1][to-1] <<endl;
		//	clog << from<< " " << to <<" "<< data[from - 1][to-1] << " "<<endl;
		distance += data[from - 1][(path.getNum((city) % (path.getSize()) + 1)) - 1];
	}
	clog << endl;
	return distance;
}
