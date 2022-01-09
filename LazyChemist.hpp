
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

template<typename data_type, std::size_t N_ROW,std::size_t N_COL>
void rref(data_type (&matrix)[N_ROW][N_COL])
{
	int lead = 0;
	int rowCount = sizeof(matrix)/sizeof(matrix)[0];
	int columnCount = sizeof(matrix[0])/sizeof(double);
	
	std::cout << " row:" <<rowCount << " col: " << columnCount << std::endl;
	
	for (int r = 0; r < rowCount; r++)
	{
        	if (columnCount <= lead)
        	{
        		break;
        	}
		int i = r;
                while (matrix[i][lead] == 0)
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
                    double temp = matrix[r][j];
                    matrix[r][j] = matrix[i][j];
                    matrix[i][j] = temp;
                }
                double div = matrix[r][lead];
                if(div != 0)
                    for (int j = 0; j < columnCount; j++) 
                    {
                    	matrix[r][j] /= div;
                    }                
                for (int j = 0; j < rowCount; j++)
                {
                    if (j != r)
                    {
                        double sub = matrix[j][lead];
                        for (int k = 0; k < columnCount; k++) 
                        {
                        	matrix[j][k] -= (sub * matrix[r][k]);
                        }
                    }
		}
	lead++;
	}
}

template<typename data_type,std::size_t N_ROW,std::size_t N_COL>
void printArray(data_type (&arr)[N_ROW][N_COL])
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