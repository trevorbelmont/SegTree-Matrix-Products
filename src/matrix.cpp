#include "matrix.hpp"

using namespace std;

// Construtor padrão. Útil para alocação dinâmica
Matrix::Matrix() {
  rows = -1;
  cols = -1;
}

// Construtor que inicializa a matriz com o número de linhas e colunas especificado
Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
  // Aloca dinamicamente memória para as linhas
  data = new long unsigned int*[rows];

  // Aloca dinamicamente memória para cada coluna em cada linha
  for (int i = 0; i < rows; ++i) {
    data[i] = new long unsigned int[cols];
  }
}
// Cria matriz Identidade de Ordem n.
Matrix::Matrix(int n) {
  rows = cols = n;
  data = new long unsigned int*[n];

  // Aloca dinamicamente memória para cada coluna em cada linha
  for (int i = 0; i < n; ++i) {
    data[i] = new long unsigned int[n];
  }
  for (int i = 0; i < n * n; i++) {
    // Se o número da linha é igual ao número da coluna, entrada recebe 1. Se não, zero.
    unsigned long int k = (i / n == i % n) ? 1 : 0;
    data[i / n][i % n] = k;
  }
}

// Destrutor que libera a memória alocada
Matrix::~Matrix() {
  // Libera a memória de cada coluna em cada linha
  // for (int i = 0; i < rows; ++i) {
  // delete[] data[i];
  //}

  // Libera a memória das linhas
  // delete[] data;
}

// Retorna o número de linhas
int Matrix::getRows() const {
  return rows;
}

// Retorna o número de colunas
int Matrix::getCols() const {
  return cols;
}

// Define o valor de uma entrada na matriz
void Matrix::setElement(int row, int col, long unsigned int value) {
  if (row >= 0 && row < rows && col >= 0 && col < cols) {
    data[row][col] = value;
  } else {
    cout << "Matrix::setElement : Entrada/Ìndices inválidos!" << endl;
  }
}

// Obtém o valor de uma entrada na matriz
long unsigned Matrix::getElement(int row, int col) const {
  if (row >= 0 && row < rows && col >= 0 && col < cols) {
    return data[row][col];
  } else {
    cout << "Matrix::getElement : Índices (entrada) Inválido!" << endl;
    return -1;  // Valor de retorno padrão em caso de índices inválidos
  }
}

void Matrix::print() {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

void Matrix::printTransposed() {
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j) {
      cout << data[j][i] << " ";
    }
    cout << endl;
  }
}

// Atribui o produto das Matrizes A x B a matriz atual (que chama o método).
void Matrix::multiply(Matrix A, Matrix B) {
  // Verifica se as matrizes podem ser multiplicadas
  if (A.cols != B.rows) {  // Tem que checar se this.dimensions bate ¬¬
    cout << "Matrix::multiply (void): Dimensões das matrizes não satisfazem a operação de multiplicação!" << endl;
    return;  // Retorna uma matriz vazia em caso de erro
  }

  // Cria uma nova matriz para armazenar o resultado
  Matrix* result = new Matrix(A.rows, B.cols);

  // Realiza a multiplicação de matrizes
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < B.cols; ++j) {
      long unsigned int sum = 0;
      for (int k = 0; k < A.cols; ++k) {
        sum += A.data[i][k] * B.data[k][j];
      }

      result->setElement(i, j, sum % 100000000);
    }
  }

  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < B.cols; ++j) {
      this->setElement(i, j, result->getElement(i, j));
    }
  }
}

// ------ Sobrecarregamentos de métodos de multiplicação ---------  //
Matrix* Matrix::multiply(Matrix other) {
  Matrix* r;
  r->multiply(*(this), other);

  return r;
}

Matrix* Matrix::operator*(Matrix& other) {
  Matrix* r;
  r->multiply(*(this), other);

  return r;
}
