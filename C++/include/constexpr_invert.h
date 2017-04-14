#ifndef __INVERT_H__
#define __INVERT_H__

#include <iostream>


template <size_t N,size_t M>
void printMatrix(const double mat[N][M])
{
	for(size_t i = 0; i < N; ++i)
	{
		for(size_t j = 0; j < M; ++j)
			std::cout << mat[i][j] << " ";

		std::cout << std::endl;
	}
	std::cout << std::endl;
}


/*
	Vertauscht zwei Zeilen in einer NxM Matrix.

	line1, line2 - Index der Zeilen, die vertauscht werden sollten.

	return: false, falls line1 oder line2 nicht in der Matrix liegen.
*/
template <size_t N,size_t M>
bool swapLine(double mat[N][M], size_t line1, size_t line2)
{
	if(line1 >= N || line2 >= N)
		return false;

	for(size_t i = 0; i < M; ++i)
	{
		double t = mat[line1][i];
		mat[line1][i] = mat[line2][i];
		mat[line2][i] = t;
	}
	
	return true;
}

/*
	Invertiert eine NxN Matrix mit Hilfe des Gauß-Jordan-Algorithmus.

	mat - Matrix die Invertiert werden soll.
	inv - Die Inverse der Matrix mat.

	return: false, falls die Matrix nicht invertierbar ist.
*/
template <size_t N>
bool invertMatrix(const double mat[N][N], double inv[N][N])
{
	// Eine Nx2N Matrix für den Gauß-Jordan-Algorithmus aufbauen
	double A[N][2*N];
	for(size_t i = 0; i < N; ++i)
	{
		for(size_t j = 0; j < N; ++j)
			A[i][j] = mat[i][j];
		for(size_t j = N; j < 2*N; ++j)
			A[i][j] = (i==j-N) ? 1.0 : 0.0;
	}

	// Gauß-Algorithmus.
	for(size_t k = 0; k < N-1; ++k)
	{
		// Zeilen vertauschen, falls das Pivotelement eine Null ist
		if(A[k][k] == 0.0)
		{
			for(size_t i = k+1; i < N; ++i)
			{
				if(A[i][k] != 0.0)
				{
					swapLine<N, 2*N>(A,k,i);
					break;
				}
				else if(i==N-1)
					return false; // Es gibt kein Element != 0
			}
		}

		// Einträge unter dem Pivotelement eliminieren
		for(size_t i = k+1; i < N; ++i)
		{
			double p = A[i][k]/A[k][k];		
			for(size_t j = k; j < 2*N; ++j)
				A[i][j] -= A[k][j]*p;
		}
	}

	// Determinante der Matrix berechnen
	double det = 1.0;
	for(size_t k = 0; k < N; ++k)
		det *= A[k][k];

	if(det == 0.0)	// Determinante ist =0 -> Matrix nicht invertierbar
		return false;

	// Jordan-Teil des Algorithmus durchführen
	for(size_t k = N-1; k > 0; --k)
	{
		for(int i = k-1; i >= 0; --i)
		{
			double p = A[i][k]/A[k][k];
			for(size_t j = k; j < 2*N; ++j)
				A[i][j] -= A[k][j]*p;
		}
	}

	// Einträge in der linker Matrix auf 1 normieren und in inv schreiben
	for(size_t i = 0; i < N; ++i)
	{
		const double f = A[i][i];
		for(size_t j = N; j < 2*N; ++j)
			inv[i][j-N] = A[i][j]/f;
	}

	return true;
}

#endif