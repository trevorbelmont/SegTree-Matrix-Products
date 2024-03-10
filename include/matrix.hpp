#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

using namespace std;

class Matrix {
 private:
  int rows;
  int cols;
  long unsigned int** data;

 public:
  // Construtores
  Matrix();
  Matrix(int numRows, int numCols);
  Matrix(int n);

  // Destrutor
  ~Matrix();

  // Métodos de acesso
  int getRows() const;
  int getCols() const;
  void setElement(int row, int col, long unsigned int value);
  long unsigned int getElement(int row, int col) const;

  // Métodos de impressão
  void print();
  void printTransposed();

  // Operações de matriz
  void multiply(Matrix A, Matrix B);
  Matrix* multiply(Matrix other);
  Matrix* operator*(Matrix& other);
};

#endif
