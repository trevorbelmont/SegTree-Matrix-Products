

Este programa aplica transformações lineares em um vetor coluna através da implementação de uma árvore de segmentação cujas folhas são matrizes de ordem RN e os nós internos são os produtos do nós filhos.

A primeira linha lida pela entrada padrão deve conter dois inteiros positvos separados por um espaço - respectivamente o número de matrizes nas folhas da árvore e o número de operações a serem executadas até o fim do programa.

O programa suporta dois tipos de operações:

  Atualização (u): esta operação atualiza  os valores das entradas de uma certa matriz na base da árvore e propaga a atualização dos produtos até a raíz.

  Consulta (q): esta operação, dado um intervalo de matrizes nas folhas e um vetor, retorna o resultado das transformações lineares do vetor pelas matrizes no intervalo selecionado.

Utilização do Makefile:

    make / make all: compila todos os objetos na pasta "obj" e o executável na pasta "bin". Essas pasta devem ser criadas de antemão.

    make clean: remove tanto o executável quanto os objs gerados durante o processo de compilação.

    make run: compila, se necessário, e executa o programa - lendo da entrada padrão.

    make test: compila, se necessário, e executa o programa com um caso de teste através do desvio da entrada padrão para o arquivo "input.in" na pasta Miscelânea

 
