#include "../include/constexpr_invert.h"


int main()
{
	double result2[2][2];
	double result3[3][3];
	double result5[5][5];

	
	/*
	   0,4  -0,33333   0,1 

	  -0,2   0         0,2 

	   0,2  -0,33333  -0,2 
    */
	double A[3][3] = {{2,-3,-2},{0,-3,-3},{2,2,-2}};
	invertMatrix<3>(A, result3);
	printMatrix<3,3>(result3);
	
	/*
		-0,33333   0,4   0,1 

		0        -0,2   0,2 

		-0,33333   0,2  -0,2 
	*/
	double B[3][3] = {{0,-3,-3},{2,-3,-2},{2,2,-2}};
	invertMatrix<3>(B, result3);
	printMatrix<3,3>(result3);
	

	/*
	
	  -0,26316   0,21053 

	  -0,05263  -0,15789 
	*/
	double C[2][2] = {{-3,-4},{1,-5}};
	invertMatrix<2>(C, result2);
	printMatrix<2,2>(result2);


	/*
	   0,53774  -1,11321   0,03774   0,53774  -0,49057 

	  -0,03145   0,09434  -0,03145   0,13522   0,24214 

	  -0,09434   0,28302  -0,09434  -0,09434   0,22642 

	   0,01258  -0,03774   0,01258  -0,15409   0,00314 

	   0,77673  -0,83019   0,27673   0,61006  -0,43082 
	*/

	double D[5][5] = {{0,-3,7,1,2},{-1,-3,3,-4,1},{-3,5,-10,4,1},{0,1,-1,-5,0},{0,5,-1,5,0}};
	invertMatrix<5>(D, result5);
	printMatrix<5,5>(result5);


	std::cin.get();

	return 0;
}