#include "stdafx.h"
#include "DispacementVector.h"

ostream& operator<<(ostream& a, const DispacementVector&vect) {
	a << "(";
	for (int i = 1; i <= vect.getSize(); i++)
	{
		
		a << vect.getNum(i)<<',';
	}
	a << ")";
	return a;
}