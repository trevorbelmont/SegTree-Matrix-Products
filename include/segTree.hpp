#include "matrix.hpp"

struct Node {
 public:
  Matrix* m;

  // Construtor:: Constrói nó com uma matriz identidade R2
  Node() {
    m = new Matrix(2, 2);
    m->setElement(0, 0, 1);
    m->setElement(0, 1, 0);
    m->setElement(1, 0, 0);
    m->setElement(1, 1, 1);
  }
  Node(Matrix cp) {
    m = new Matrix(cp.getRows(), cp.getCols());
    for (int i = 0; i < cp.getRows(); ++i) {
      for (int j = 0; j < cp.getCols(); ++j) {
        m->setElement(i, j, cp.getElement(i, j));
      }
    }

    // ¬ Fazer cópia
  }
  /* ~Node() {
    //delete m;
  } */
  void print() {
    m->print();
  }
};

class SegmentTree {
 private:
  Node* tree;
  int size;

 public:
  // Construtor
  SegmentTree(const Matrix* matrices, int numMatrices) {
    size = numMatrices;
    tree = new Node[4 * size];  // Usando 4 * size para garantir espaço suficiente

    // Construir a árvore recursivamente
    build(1, 0, size - 1, matrices);
  }

  // Destrutor
  ~SegmentTree() {
    delete[] tree;
  }

  // Construção da árvore
  void build(int node, int start, int end, const Matrix* matrices) {
    if (start == end) {
      tree[node] = Node(matrices[start]);

    } else {
      int mid = (start + end) / 2;
      build(2 * node, start, mid, matrices);
      build(2 * node + 1, mid + 1, end, matrices);

      cout << node << endl;
      tree[node].m->multiplica(*tree[2 * node].m, *tree[2 * node + 1].m);

      /* Matrix* combine = tree[2 * node].m->multiply(*(tree[2 * node + 1].m));


      for (int i = 0; i < combine->getRows(); ++i) {
        for (int j = 0; j < combine->getCols(); ++j) {
         tree[node].m->setElement(i, j, combine->getElement(i, j));
        }
      }
      delete combine; */
      // combine = (tree[2 * node].m)->multiply( &tree[2 * node + 1].m);

      // Combine as informações dos filhos
      // tree[node].m = (tree[2 * node].m)->multiply( tree[2 * node + 1].m);
    }
  }
  // Método para modificar uma matriz nas folhas da árvore e refazer
  void update(int instant, const Matrix& newMatrix) {
    recursiveUpdate(1, 0, size - 1, instant, newMatrix);
  }

  // Método auxiliar para atualizar a árvore recursivamente
  void recursiveUpdate(int node, int start, int end, int instant, const Matrix& newMatrix) {
    if (start == end) {
      // Atualiza a matriz na folha
      delete tree[node].m;
      tree[node].m = new Matrix(newMatrix.getRows(), newMatrix.getCols());

      for (int i = 0; i < newMatrix.getRows(); i++) {
        for (int j = 0; j < newMatrix.getCols(); j++) {
          tree[node].m->setElement(i, j, newMatrix.getElement(i, j));
        }
      }
    } else {
      int mid = (start + end) / 2;
      if (instant <= mid) {
        // Se o índice está na subárvore esquerda
        recursiveUpdate(2 * node, start, mid, instant, newMatrix);
      } else {
        // Se o índice está na subárvore direita
        recursiveUpdate(2 * node + 1, mid + 1, end, instant, newMatrix);
      }

      // Combine as informações dos filhos
      tree[node].m->multiplica(*tree[2 * node].m, *tree[2 * node + 1].m);
    }
  }
  // Método para imprimir a árvore
  void print() const {
    recursivePrint(1, 0, size - 1);
  }

  // Método auxiliar para imprimir a árvore recursivamente
  void recursivePrint(int node, int start, int end) const {
    if (start == end) {
      cout << "Node [" << node << "].print()" << endl;
      tree[node].print();
    } else {
      cout << "Node Interno [" << node << "].print()" << endl;
      tree[node].print();
      int mid = (start + end) / 2;
      recursivePrint(2 * node, start, mid);
      recursivePrint(2 * node + 1, mid + 1, end);

      // Imprimir informações do nó (se necessário)
      // tree[node].print();
    }
  }

  // Método para obter o produto do intervalo [l, r]
  Matrix* segProduct(int l, int r) const {
    return recursiveProduct(1, 0, size - 1, l, r);
  }

  // Método auxiliar para obter o produto do intervalo recursivamente
  Matrix* recursiveProduct(int node, int start, int end, int l, int r) const {
    // Caso 0: O intervalo [l, r] está completamente fora do intervalo [start, end]
    if (start > r || end < l) {
      // Retorna uma matriz nula
      Matrix* nulla = new Matrix(0, 0);
      return nulla;
    }

    // Caso 1: O intervalo [start, end] está completamente dentro do intervalo [l, r]
    if (start >= l && end <= r) {
      return (tree[node].m);
    }

    // Caso 2: O intervalo [l, r] e [start, end] se sobrepõem parcialmente
    int mid = (start + end) / 2;
    Matrix* leftResult = recursiveProduct(2 * node, start, mid, l, r);
    Matrix* rightResult = recursiveProduct(2 * node + 1, mid + 1, end, l, r);


 // Combina as informações dos filhos
    if (leftResult->getCols() > 0 && rightResult->getRows() > 0) {
      Matrix* finalResult = new Matrix(leftResult->getCols(), rightResult->getRows());
      finalResult->multiplica(*leftResult, *rightResult);
      return finalResult;
    }
    // Um dos segmentos (leftResult or rightResult) pode ser uma matriz degenerada nula.
    // Neste caso apenas o segmento não nulo é retornado na recursão.
     else if (leftResult->getCols() > 0) {
      return leftResult;
    } else if (rightResult->getRows() > 0) {
      return rightResult;
    }
  }
};
