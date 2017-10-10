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
		 void printMatrix() {
			const matrix& matr = getMatrix();
			for (auto row : matr) {
				PrintVectorValue(row, false);clog << endl;
			}
		}
		static void printSet(set X) {
			clog << "[";
			for (num xi : X) {
				clog << xi << ",";
			}
			clog << "]";
		}


		static void PrintVectorValue(const vector<value>&X, bool printIndex) {
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
