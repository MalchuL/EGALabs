#pragma once
#include "AbstractMethodSearching.h"
//using namespace MethodSearching;
class Logger
{
public:
	/*
	static void printset(set* const printedset) {
		clog << "{ ";
		for (auto i = printedset->begin(); i != printedset->end(); i++)
		{
			clog << **i << ", ";
		}
		clog << "}" << endl;
	}
	static void printset(set* const printedset, func* const function) {
		clog << "{ ";
		for (auto i = printedset->begin(); i != printedset->end(); i++)
		{
			clog << **i<<":"<<function->at(*i) << ", ";
		}
		clog << "}" << endl;
	}
	*/
	Logger();
	~Logger();
};

