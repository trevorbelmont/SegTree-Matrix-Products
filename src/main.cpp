#include "matrix.hpp"
#include "segTree.hpp"

using namespace std;

int TestMultiply() {
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
  Matrix m = *result;
  result->print();

  cout << "m" << endl;
  m.print();

  return 0;
}

int main() {
  // Criar um array de matrizes para teste
  Matrix matrices[] = {Matrix{2, 2}, Matrix{2, 2}, Matrix{2, 2}};  // Adicione suas próprias matrizes conforme necessário

  for (int i = 0; i < 3; i++) {
    matrices[i].setElement(0, 0, i + 1);
    matrices[i].setElement(1, 1, i + 1);
  }

  // Criar uma árvore de segmentação
  SegmentTree segTree(matrices, sizeof(matrices) / sizeof(matrices[0]));

  // Imprimir a árvore
  cout << "Árvore de Segmentação:" << endl;
  segTree.print();

  Matrix n(2, 2);
  n.setElement(0, 0, 9);
  n.setElement(1, 1, 9);

  segTree.update(2, n);

  segTree.print();

  cout << "query" << endl;
  segTree.segProduct(1, 2)->print();

  return 0;
}