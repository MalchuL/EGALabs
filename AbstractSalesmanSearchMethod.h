#pragma once
#include "DispacementVector.h"
#include <vector>
namespace Salesman {
	typedef float value;
	typedef vector<vector<value> > matrix;
	typedef vector<num> set;
	class AbstractSalesmanSearchMethod
	{
		const matrix data;
	public:
		const matrix getMatrix() {
			return data;
		}
		value getDistance(int i, int j) {
			return data[i][j];
		}
		AbstractSalesmanSearchMethod(const matrix& data) :data(data) {

		}
		virtual DispacementVector find() = 0;
	};

}
