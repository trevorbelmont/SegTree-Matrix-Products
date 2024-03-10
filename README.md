Este programa aplica transformações lineares em um vetor através da implementação de uma árvore de segmentação cujas folhas são matrizes de ordem RN e os nós internos são os produtos do nós filhos.
A primeira linha lida pela entrada padrão deve conter dois inteiros positvos separados por um espaço - respectivamente o número de matrizes nas folhas da árvore e o número de operações a serem executadas até o fim do programa.
O programa suporta dois tipos de operações:
  Atualização (u): esta operação atualiza  os valores das entradas de uma certa matriz na base da árvore e propaga a atualização dos produtos até a raíz.
  Consulta (q): esta operação, dado um intervalo de matrizes nas folhas e um vetor, retorna o resultado das transformações lineares do vetor pelas matrizes no intervalo selecionado.

o comando "make test" compila e testa o programa através do desvio da entrada padrão para o arquivo "input.in" na pasta "_-_Miscelânea" que possui um caso de teste pronto. Outros casos de testes podem ser extraídos do PDF com a especificação do TP, na mesma pasta.
