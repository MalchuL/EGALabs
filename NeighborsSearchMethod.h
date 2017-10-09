#pragma once
#include "AbstractSalesmanSearchMethod.h"
#include <algorithm>
namespace Salesman {
	
	class NeighborsSearchMethod :
		public AbstractSalesmanSearchMethod
	{
		const int size;

		num getNeighbor(num city, set X, const matrix& data,value* ref_distance) {
			//numset neighbors;
			num neighbor = X[0];
			value min = data[city - 1][neighbor - 1];
			clog << "distance for city " << city << ": "; PrintVectorValue(data[city - 1],true);clog << endl;
			for (num xk : X) {
				value distance = data[city - 1][xk - 1];
				if (distance < min) {
					min = distance;
					neighbor = xk;
				}
			}
			if (ref_distance != nullptr)*ref_distance = min;
			//clog << "------" << min << "-------";
			clog << "neighbor city:" << neighbor<<": distance "<<min<<endl;
			return neighbor;
		}
	public:
		void printMatrix() {
			const matrix& matr = getMatrix();
			for(auto row:matr){
				PrintVectorValue(row,false);clog << endl;
			}
		}
		NeighborsSearchMethod(matrix data) :AbstractSalesmanSearchMethod(data), size(data.size()) {}
		DispacementVector find() {
			printMatrix();
			DispacementVector returnedvector(size);
			set X;
			srand(10);
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
				xi = getNeighbor(si, X, getMatrix(),&ref_distance);
				distancev += ref_distance;
				//clog << "+++" << distancev << "+++";
				X.erase(std::find(X.begin(), X.end(), xi));
				si = xi;
				returnedvector.setNum(i, si);
				clog << "Iter"<< i <<" si:" << si << endl;
				
			}
			cout << "from " << si << " to " << first_x << ":" << getMatrix()[si - 1][first_x - 1]<<endl;
			distancev += getMatrix()[si-1][first_x-1];
			clog << returnedvector << ":" << distancev<<endl;
			return returnedvector;
		}

		void printSet(set X) {
			clog << "[";
			for (num xi : X) {
				clog << xi << ",";
			}
			clog << "]";
		}


		static void PrintVectorValue(const vector<value>&X,bool printIndex) {
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
	};

	
}