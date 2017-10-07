#pragma once
#include "ByteVector.h"
#include <map>
#include <vector>
#include <algorithm>
#include "Logger.h"
typedef float funcvalue;
typedef vector<ByteVector*> set;
typedef map<ByteVector*, funcvalue> func;
using namespace std;
namespace MethodSearching {
	class AbstractMethodSearching
	{
	private:
		vector<ByteVector*>* reorderednums;
	protected:
		func* elements;
		
		vector<ByteVector*>* getReorderedNums() {
			if (reorderednums == nullptr)addReorderedNums();
			if (reorderednums == nullptr)throw 1;
			return reorderednums;
		}

		

		
		void printreorderednums() {
		clog << endl;
		clog << "Input Data"<<endl;
		for (auto it = reorderednums->begin(); it != reorderednums->end(); it++)
		{
		clog << **it<<" "<<elements->at(*it)<<endl;
		}
		clog << endl;
		}
		static void printset(set* const printedset) {
			clog << "{ ";
			for (auto i = printedset->begin(); i != printedset->end(); i++)
			{
				clog << **i << ", ";
			}
			clog << "}";
		}
		static void printset(set* const printedset, func* const function) {
			clog << "{ ";
			for (auto i = printedset->begin(); i != printedset->end(); i++)
			{
				clog << **i << ":" << function->at(*i) << ", ";
			}
			clog << "}" << endl;
		}
	public:
		void addReorderedNums() {
			if (reorderednums == nullptr) {
				reorderednums = new vector<ByteVector*>();
				for (func::iterator it = elements->begin(); it != elements->end(); ++it) {
					reorderednums->push_back(it->first);

				}
			}
			random_shuffle(reorderednums->begin(), reorderednums->end());
		}

		virtual ByteVector find() = 0;
		AbstractMethodSearching(ByteVector vectors[], funcvalue values[],int size) {

			elements = new func();
			reorderednums = new vector<ByteVector*>();
			for (size_t i = 0; i <size; i++)
			{
				ByteVector* n_vector = new ByteVector(vectors[i]);
				elements->insert(pair<ByteVector*, funcvalue>(n_vector, values[i]));
				reorderednums->push_back(n_vector);
			}
			
		}
		AbstractMethodSearching( const vector<ByteVector>& vectors,const vector<funcvalue>& values) {
			int size = vectors.size() > values.size() ? values.size() : vectors.size();
			elements = new func();
			reorderednums = new vector<ByteVector*>();
			for (size_t i = 0; i <size; i++)
			{
				ByteVector* n_vector = new ByteVector(vectors[i]);
				elements->insert(pair<ByteVector*, funcvalue>(n_vector, values[i]));
				reorderednums->push_back(n_vector);
			}

		
		}
		~AbstractMethodSearching() {
			delete reorderednums;
			for (func::iterator it = elements->begin(); it != elements->end(); ++it) {
				delete it->first;

			}
			delete elements;

		}
	};


}