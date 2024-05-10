#ifndef MATRIXADJACENCY_H
#define MATRIXADJACENCY_H

#include <iostream>
using namespace std;

/*
What functions should be implemented?
- addEdge(int i, int j): add an edge between vertex i and vertex j
- removeEdge(int i, int j): remove the edge between vertex i and vertex j
- printMatrix(): print the adjacency matrix
*/

/*
How it works?
- The matrix is a 2D array of integers
- The size of the matrix is the number of vertices
- The matrix is initialized with 0s
- If there is an edge between vertex i and vertex j, then matrix[i][j] = 1
- If there is no edge between vertex i and vertex j, then matrix[i][j] = 0

Example:
- Let's say we have 4 vertices
- The matrix is a 4x4 2D array of integers
- The matrix is initialized with 0s
- If there is an edge between vertex 0 and vertex 1, then matrix[0][1] = 1
- If there is no edge between vertex 0 and vertex 1, then matrix[0][1] = 0
- If there is an edge between vertex 1 and vertex 2, then matrix[1][2] = 1
- If there is no edge between vertex 1 and vertex 2, then matrix[1][2] = 0
- If there is an edge between vertex 2 and vertex 3, then matrix[2][3] = 1
- If there is no edge between vertex 2 and vertex 3, then matrix[2][3] = 0
- If there is an edge between vertex 3 and vertex 0, then matrix[3][0] = 1
- If there is no edge between vertex 3 and vertex 0, then matrix[3][0] = 0
- The adjacency matrix is:
  0 1 0 0
  0 0 1 0
  0 0 0 1
  1 0 0 0


  And what should I do do get weight of edge?
  - You can use the matrix[i][j] to get the weight of the edge between vertex i and vertex j
  okay but what if I want to get the weight of the edge between vertex 1 and vertex 2?

  And how to change density of the graph?
  - You can change the density of the graph by changing the values of the matrix
  - If you want to increase the density of the graph, then you can change the values of the matrix to 1s

  What else can I do?
  - You can remove the edge between two vertices by setting the value of the matrix to 0
  - You can add the edge between two vertices by setting the value of the matrix to 1
  - You can print the adjacency matrix
  - You can get the weight of the edge between two vertices
  - You can change the density of the graph
*/

class MatrixAdjacency {
private:
	int** matrix;
	int size;
public:
	MatrixAdjacency(int size);
	~MatrixAdjacency();
	void addEdge(int i, int j, int w);
	void removeEdge(int i, int j);
	int getWeight(int i, int j);
	void printMatrix();
};

#endif // MATRIXADJACENCY_H
