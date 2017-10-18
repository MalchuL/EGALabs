#pragma once
#include "DispacementVector.h"
#include <vector>
namespace Salesman {
	typedef float value;
	typedef vector<vector<value> > matrix;
	typedef vector<num> set;
	class AbstractSalesmanSearchMethod
	{
	private:
		const matrix data;
	protected:
		void printMatrix();
		static void printSet(set X);


		static void PrintVectorValue(const vector<value>&X, bool printIndex);
	public:
		const matrix getMatrix();
		value getDistance(int i, int j);
		AbstractSalesmanSearchMethod(const matrix& data);
		virtual DispacementVector find() = 0;
	};

}
