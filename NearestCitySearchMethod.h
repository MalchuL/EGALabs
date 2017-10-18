#pragma once
#include "AbstractSalesmanSearchMethod.h"
#include <algorithm>
#include <tuple>
using namespace std;
namespace Salesman {
	class NearestCitySearchMethod :
		public AbstractSalesmanSearchMethod
	{
		const int size;

		num getNeighbor(num city, set X, const matrix& data, value* ref_distance);
		//Первый аргумент возвращаемого значения - позиция, а второй - какой надо вставить
		tuple<num, num> getNearestNeighbor(set cities, set X, const matrix& data);
		void printDisplacementPart(DispacementVector&vector, int from, int to);
	public:
		NearestCitySearchMethod(matrix data, int randomSeed);

		DispacementVector find();
		value calculateDistance(matrix data, DispacementVector path);
		
	};
}

