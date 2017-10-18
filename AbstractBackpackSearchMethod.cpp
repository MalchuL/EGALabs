#include "stdafx.h"
#include "AbstractBackpackSearchMethod.h"

void BackpackSearchMethod::AbstractBackpackSearchMethod::printList(list & printedList) {
	for (object i : printedList) {
		clog << "i:" << get<INDEX>(i) << " w:" << get<WEIGHT>(i) << " c:" << get<COST>(i) << endl;
	}
}

BackpackSearchMethod::AbstractBackpackSearchMethod::AbstractBackpackSearchMethod(vector<weightvalue> weights, vector<costvalue> costs, weightvalue maxWeight) {
	this->maxWeight = maxWeight;
	this->objects = new list();
	int size = (weights.size() < costs.size()) ? weights.size() : costs.size();
	for (size_t i = 0; i < size; i++)
	{
		clog << i;
		objects->push_back(object(i, weights[i], costs[i]));
	}
}

BackpackSearchMethod::AbstractBackpackSearchMethod::~AbstractBackpackSearchMethod() {
	delete objects;
}
