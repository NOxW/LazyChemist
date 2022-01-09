
/*


██████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████
███████╔╗██╔═══╦════╦╗██╔╦═══╦╗█╔╦═══╦═╗╔═╦══╦═══╦════╗███████
███████║║██║╔═╗╠══╗═║╚╗╔╝║╔═╗║║█║║╔══╣║╚╝║╠╣╠╣╔═╗║╔╗╔╗║███████
███████║║██║║█║║█╔╝╔╩╗╚╝╔╣║█╚╣╚═╝║╚══╣╔╗╔╗║║║║╚══╬╝║║╚╝███████
███████║║█╔╣╚═╝║╔╝╔╝█╚╗╔╝║║█╔╣╔═╗║╔══╣║║║║║║║╚══╗║█║║█████████
███████║╚═╝║╔═╗╠╝═╚═╗█║║█║╚═╝║║█║║╚══╣║║║║╠╣╠╣╚═╝║█║║█████████
███████╚═══╩╝█╚╩════╝█╚╝█╚═══╩╝█╚╩═══╩╝╚╝╚╩══╩═══╝█╚╝█████████
██████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████


Filename LazyChemist.hpp
Programmed by Ivan Penyak
Date: 09 Jan 2022


*/


#ifndef LAZY_CHEMIST_HPP
#define LAZY_CHEMIST_HPP

#include <iostream>
#include <iomanip>

namespace lazychemist
{

int set_w = 6;

template<typename T, std::size_t N,std::size_t M>
void rref(T (&arr)[N][M])
{
	int lead = 0;
	int rowCount = sizeof(arr)/sizeof(arr)[0];
	int columnCount = sizeof(arr[0])/sizeof(double);
	
	std::cout << " row:" <<rowCount << " col: " << columnCount << std::endl;
	
	for (int r = 0; r < rowCount; r++)
	{
        	if (columnCount <= lead)
        	{
        		break;
        	}
		int i = r;
                while (arr[i][lead] == 0)
                {
                    i++;
                    if (i == rowCount)
                    {
                        i = r;
                        lead++;
                        if (columnCount == lead)
                        {
                        	break;
                        }
                    }
                }
                for (int j = 0; j < columnCount; j++)
                {
                    double temp = arr[r][j];
                    arr[r][j] = arr[i][j];
                    arr[i][j] = temp;
                }
                double div = arr[r][lead];
                if(div != 0)
                    for (int j = 0; j < columnCount; j++) 
                    {
                    arr[r][j] /= div;
                    }                
                for (int j = 0; j < rowCount; j++)
                {
                    if (j != r)
                    {
                        double sub = arr[j][lead];
                        for (int k = 0; k < columnCount; k++) 
                        {
                        arr[j][k] -= (sub * arr[r][k]);
                        }
                    }
		}
	lead++;
	}
}

template<typename T,std::size_t N,std::size_t M>
void printArray(T (&arr)[N][M])
{
	for (auto & i : arr)
	{
		std::cout << " [ ";
		for (double j : i) {
			std::cout << std::setw(set_w) << j << ", ";
	}
	std::cout << "]" << std::endl;
	}
}



} /* namespace lazychemist */


#endif /* LAZY_CHEMIST_HPP */