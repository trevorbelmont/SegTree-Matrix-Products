#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "matrix.hpp"

struct Node {
 public:
  Matrix* m;

  // Construtor:: Constrói nó com uma matriz identidade R2
  Node();
  // Constrói uma matriz identidade de ordem n (RN);
  Node(int n);
  Node(Matrix cp);
  ~Node();
  void print();
};

class SegmentTree {
 private:
  Node* tree;
  int size;

 public:
  // Constrói SegTree a partir de array de matrizes de tamanho numMatrices
  SegmentTree(Matrix* matrices, int numMatrices);
  // Constrói SegTree com "numMatrices" matrizes identidade nas folhas
  SegmentTree(int numMatrices);
  // Destrutor
  ~SegmentTree();
  // Construção da árvore
  void build(int node, int start, int end, const Matrix* matrices);
  // Método para modificar uma matriz nas folhas da árvore e refazer
  void update(int instant, const Matrix& newMatrix);
  // Método auxiliar para atualizar a árvore recursivamente
  void recursiveUpdate(int node, int start, int end, int instant, const Matrix& newMatrix);
  // Método para imprimir a árvore
  void print() const;
  // Método auxiliar para imprimir a árvore recursivamente
  void recursivePrint(int node, int start, int end) const;
  // Método para obter o produto do intervalo [l, r]
  Matrix* segProduct(int l, int r) const;
  // Método auxiliar para obter o produto do intervalo recursivamente
  Matrix* recursiveProduct(int node, int start, int end, int l, int r) const;
};

#endif