#include <iostream>
#include "LazyChemist.hpp"

int main()
{
	double aaa[4][7] =
	{
	2,4,0,1,0,0,0,
	0,0,2,0,1,0,0,
	1,0,2,0,0,1,0,
	0,2,1,0,0,0,1
	};
	
	double aab[6][11] = 
	{
	1,0,0,0, 1,1,0,0,0,0,0,
	0,2,7,0,-2,0,1,0,0,0,0,
	6,0,1,2, 0,0,0,1,0,0,0,
	0,1,0,0, 3,0,0,0,1,0,0,
	0,0,2,1, 0,0,0,0,0,1,0,
	2,0,1,0, 0,0,0,0,0,0,1
	};
	
	lazychemist::printArray(aaa);
	
	lazychemist::rref(aaa);
	
	lazychemist::printArray(aaa);
	
	lazychemist::printArray(aab);
	
	lazychemist::rref(aab);
	
	lazychemist::printArray(aab);
	
	
	return 0;
}





















