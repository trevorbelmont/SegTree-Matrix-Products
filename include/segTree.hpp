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

  // Método para imprimir a árvore
  void print() const {
    printTree(1, 0, size - 1);
  }

  // Método auxiliar para imprimir a árvore recursivamente
  void printTree(int node, int start, int end) const {
    if (start == end) {
      cout << "Node [" << node << "].print()" << endl;
      tree[node].print();
    } else {
      cout << "Node Interno [" << node << "].print()" << endl;
      tree[node].print();
      int mid = (start + end) / 2;
      printTree(2 * node, start, mid);
      printTree(2 * node + 1, mid + 1, end);

      // Imprimir informações do nó (se necessário)
      // tree[node].print();
    }
  }
};
