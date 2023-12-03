#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>

using namespace std;

class Matrix {
 private:
  int rows;
  int cols;
  int** data;

 public:
  // Construtor que inicializa a matriz com o número de linhas e colunas especificado
  Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    // Aloca dinamicamente memória para as linhas
    data = new int*[rows];

    // Aloca dinamicamente memória para cada coluna em cada linha
    for (int i = 0; i < rows; ++i) {
      data[i] = new int[cols];
    }
  }

  // Destrutor que libera a memória alocada
  ~Matrix() {
    // Libera a memória de cada coluna em cada linha
    for (int i = 0; i < rows; ++i) {
      delete[] data[i];
    }

    // Libera a memória das linhas
    delete[] data;
  }

  // Retorna o número de linhas
  int getRows() const {
    return rows;
  }

  // Retorna o número de colunas
  int getCols() const {
    return cols;
  }

  // Define o valor de uma entrada na matriz
  void setElement(int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
      data[row][col] = value;
    } else {
      cout << "Índices de matriz inválidos." << endl;
    }
  }

  // Obtém o valor de uma entrada na matriz
  int getElement(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
      return data[row][col];
    } else {
      cout << "Índices de matriz inválidos." << endl;
      return -1;  // Valor de retorno padrão em caso de índices inválidos
    }
  }

  void print() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
  }

  Matrix* operator*(Matrix& other) {
    // Verifica se as matrizes podem ser multiplicadas
    if (cols != other.rows) {
      std::cerr << "Não é possível multiplicar as matrizes. Número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz." << std::endl;
      Matrix* nulla = new Matrix(0, 0);
      return nulla;  // Retorna uma matriz vazia em caso de erro
    }

    // Cria uma nova matriz para armazenar o resultado
    Matrix* result = new Matrix(rows, other.cols);

    // Realiza a multiplicação de matrizes
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < other.cols; ++j) {
        int sum = 0;
        for (int k = 0; k < other.rows; ++k) {
          sum += data[i][k] * other.data[k][j];
        }

        result->setElement(i, j, sum);
      }
    }

    return result;
  }
};


#endif