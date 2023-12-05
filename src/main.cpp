
#include <iostream>

#include "segTree.hpp"

using namespace std;

int testMultiply() {
  // Cria duas matrizes para teste
  Matrix matrix1(2, 2);
  Matrix matrix2(2, 2);

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
  Matrix* result = new Matrix(matrix1.getRows(), matrix2.getCols());
  result->multiply(matrix1, matrix2);

  // Imprime o resultado da multiplicação
  cout << "\nResultado da multiplicação:" << endl;
  Matrix m = *result;
  result->print();

  cout << "m" << endl;
  m.print();

  return 0;
}

int testSegTree() {
  // Criar um array de matrizes para teste
  Matrix matrices[] = {Matrix{2, 2}, Matrix{2, 2}, Matrix{2, 2}};  // Adicione suas próprias matrizes conforme necessário

  for (int i = 0; i < 3; i++) {
    matrices[i].setElement(0, 1, i);
    matrices[i].setElement(1, 0, i);
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
  Matrix* seg;
  seg = segTree.segProduct(1, 2);
  seg->print();

  Matrix v(1, 2);
  v.setElement(0, 0, 1);
  v.setElement(0, 1, 1);
  cout << "v.Before:   ";
  v.print();
  Matrix r(1, 2);
  r.multiply(v, *seg);
  r.print();

  cout << "=================== TEST MULTIPLY ====================" << endl;
  testMultiply();
  return 0;
}

int main(int argc, char* argv[]) {
  int R = (argc > 1) ? stoi(argv[1]) : 2;
  bool verbose = (argc > 2 && argv[2][0] == 'v');

  if (verbose) {
    cout << "Espaço R" << R << endl;
  }

  int treeSize = 0;
  int nOp = 0;
  cin >> treeSize;
  cin >> nOp;

  SegmentTree segTree(treeSize);

  for (int i = 0; i < nOp; i++) {
    char op;
    cin >> op;

    if (op == 'u') {
      int id;  //     ¬
      cin >> id;
      Matrix m(R, R);
      for (int i = 0; i < R * R; i++) {
        long unsigned int k;
        cin >> k;
        m.setElement(i / 2, i % 2, k);
      }
      segTree.update(id, m);
    } else if (op == 'q') {
      int from, to;
      cin >> from;
      cin >> to;
      Matrix* segment = segTree.segProduct(from, to);
      if (verbose) {
        cout << "segment Matrix [" << from << "," << to << "]" << endl;
        segment->print();
      }
      Matrix vector(R, 1);

      for (int i = 0; i < R; i++) {
        long int k;
        cin >> k;  // considerou-se reutilizar a variável "to" aqui para definir as entradas do vetor;
        // porém optou-se por não fazê-lo em razão da legibilidade e por não ser necessário ter um 'to' do tipo long;
        vector.setElement(i, 0, k);
      }
      if (verbose) {
        cout << "Vector BEFORE:" << endl;
        vector.print();
      }
      Matrix result(R, 1);
      result.multiply(*segment, vector);
      if (verbose) {
        cout << "Product Result:" << endl;
      }
      result.printTransposed();
    } else {
      cout << "Utilize apenas os comandos:" << endl;
      cout << "'u' (update): para atualizar uma folha da Árvore de Segmentação" << endl;
      cout << "'q' (query): para multiplicar o vetor informado pelo produtório do segmento (intervalo) especificado" << endl;
      cout << "Imprimindo estado atual da árvore:" << endl;
      cout << endl;
      cout << endl;
      segTree.print();
    }
  }
}
