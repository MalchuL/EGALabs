#pragma once
#include "AbstractSalesmanSearchMethod.h"
#include <algorithm>
namespace Salesman {
	
	class NeighborsSearchMethod :
		public AbstractSalesmanSearchMethod
	{
		const int size;

		num getNeighbor(num city, set X, const matrix& data, value* ref_distance);
	public:
		
		NeighborsSearchMethod(matrix data, int randomSeed);
		DispacementVector find();

		
	};

	
}