#include "stdafx.h"
#include "AbstractMethodSearching.h"

vector<ByteVector>* MethodSearching::AbstractMethodSearching::getReorderedNums() {
	if (reorderednums == nullptr)addReorderedNums();
	if (reorderednums == nullptr)throw 1;
	return reorderednums;
}

void MethodSearching::AbstractMethodSearching::printReorderedNums() {
	clog << endl;
	clog << "Input Data" << endl;
	for (auto it = reorderednums->begin(); it != reorderednums->end(); it++)
	{
		clog << *it << " " << elements->at(*it) << endl;
	}
	clog << endl;
}

void MethodSearching::AbstractMethodSearching::printSet(set * const printedset) {
	clog << "{ ";
	for (auto i = printedset->begin(); i != printedset->end(); i++)
	{
		clog << *i << ", ";
	}
	clog << "}";
}

void MethodSearching::AbstractMethodSearching::printSet(set * const printedset, func * const function) {
	clog << "{ ";
	for (auto i = printedset->begin(); i != printedset->end(); i++)
	{
		clog << *i << ":" << function->at(*i) << ", ";
	}
	clog << "}" << endl;
}

void MethodSearching::AbstractMethodSearching::addReorderedNums() {
	if (reorderednums == nullptr) {
		reorderednums = new vector<ByteVector>();
		for (func::iterator it = elements->begin(); it != elements->end(); ++it) {
			reorderednums->push_back(it->first);

		}
	}
	random_shuffle(reorderednums->begin(), reorderednums->end());
}

MethodSearching::AbstractMethodSearching::AbstractMethodSearching(ByteVector vectors[], funcvalue values[], int size) {

	elements = new func();
	reorderednums = nullptr;
	for (size_t i = 0; i <size; i++)
	{
		ByteVector n_vector = ByteVector(vectors[i]);
		elements->insert(pair<ByteVector, funcvalue>(n_vector, values[i]));
		//reorderednums->push_back(n_vector);
	}

}

MethodSearching::AbstractMethodSearching::AbstractMethodSearching(const vector<ByteVector>& vectors, const vector<funcvalue>& values) {
	int size = vectors.size() > values.size() ? values.size() : vectors.size();
	elements = new func();
	reorderednums = nullptr;
	for (size_t i = 0; i <size; i++)
	{
		ByteVector n_vector = ByteVector(vectors[i]);
		elements->insert(pair<ByteVector, funcvalue>(n_vector, values[i]));
		//reorderednums->push_back(n_vector);
	}


}

MethodSearching::AbstractMethodSearching::~AbstractMethodSearching() {
	delete reorderednums;
	/*	for (func::iterator it = elements->begin(); it != elements->end(); ++it) {
	delete it->first;

	}*/
	delete elements;

}
