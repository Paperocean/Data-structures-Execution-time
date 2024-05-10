#include "matrixAdjacency.h"

MatrixAdjacency::MatrixAdjacency(int size)
{
	/*
	How works this function?
	- The matrix is a 2D array of integers
	- The size of the matrix is the number of vertices
	- The matrix is initialized with 0s
	*/

	matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = -1;
		}
	}
	this->size = size;
}

MatrixAdjacency::~MatrixAdjacency()
{
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	/*
	How works this function?
	- Deallocate the memory of the matrix
	*/
}

void MatrixAdjacency::addEdge(int i, int j, int w)
{
	/*
			How works this function?
					- If there is an edge between vertex i and vertex j, then matrix[i][j] = 1
							*/
	if (i < size && j < size) {
		matrix[i][j] = w;
	}
}

void MatrixAdjacency::removeEdge(int i, int j)
{
	/*
			How works this function?
						- If there is no edge between vertex i and vertex j, then matrix[i][j] = 0
										*/
	if (i < size && j < size) {
		matrix[i][j] = -1;
	}
}

int MatrixAdjacency::getWeight(int i, int j) {
	return matrix[i][j];
}

void MatrixAdjacency::printMatrix()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}