#include "matrix.hpp"

using namespace std;
int main() {
    // Cria duas matrizes para teste
  Matrix matrix1(2, 3);
  Matrix matrix2(3, 2);

  // Preenche as matrizes com alguns valores para teste
  for (int i = 0; i < matrix1.getRows(); ++i) {
    for (int j = 0; j < matrix1.getCols(); ++j) {
      matrix1.setElement(i, j, i * matrix1.getCols() + j);
    }
  }

  for (int i = 0; i < matrix2.getRows(); ++i) {
    for (int j = 0; j < matrix2.getCols(); ++j) {
      matrix2.setElement(i, j, i * matrix2.getCols() + j);
    }
  }

  // Imprime as matrizes originais
  cout << "Matrix 1:" << endl;
  matrix1.print();

  cout << "\nMatrix 2:" << endl;
  matrix2.print();

  // Multiplica as matrizes
  Matrix* result = matrix1 * (matrix2);

  // Imprime o resultado da multiplicação
  cout << "\nResultado da multiplicação:" << endl;
  result->print();
  delete result;
  return 0;
}