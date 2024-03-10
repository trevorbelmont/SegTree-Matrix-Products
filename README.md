# Árvore de Segmentação de Produto de Matrizes

Este programa aplica transformações lineares em um vetor coluna através da implementação de uma árvore de segmentação cujas folhas são matrizes de ordem RN e os nós internos são os produtos dos nós filhos. 
Este programa foi desenvolvido como um trabalho da disciplina de Estrutura de Dados da UFMG e mais detalhes sobre a especificação podem ser encontrados no arquivo PDF "TP3 Especificação.pdf" na pasta Miscelânea.

## As operações suportadas
O programa suporta dois tipos de operações:
* **Atualização (u):** esta operação atualiza os valores das entradas da matriz especificada linha a linha. A alterção é propagada até a raiz,  atualizando os produtos de matrizes armazenados nos nodos ancestrais da folha alterada - mantendo assim a árvore de segmentação sempre atualizada.
* **Consulta (q):** esta operação, dado um intervalo de matrizes nas folhas e um vetor, retorna o resultado das transformações lineares do vetor pelas matrizes no intervalo selecionado.

### Comandos do Makefile:

* `make / make all`: compila todos os objetos na pasta "obj" e o executável na pasta "bin". Essas pasta devem ser criadas de antemão.
* `make clean`: remove tanto o executável quanto os objs gerados durante o processo de compilação.
* `make run`: compila, se necessário, e executa o programa trabalhando com matrizes no R² - lendo da entrada padrão.
* `make test`: compila, se necessário, e executa o programa rodando um caso de teste - através do desvio da entrada padrão para o arquivo "input.in" na pasta Miscelânea.

# Sintaxe de Execução do binário

Por padrão o program é executado trabalhando com matrizes quadradas 2x2 (espaço R²), conforme requisitado na especificação. No entanto ele foi implementado para suportar matrizes NxN (espaço RN) e suas operações for desenvolvidas de forma adaptável. Ou seja, as operações suportam qualquer RN que tenha sido estabelecido na execução do programa. Também por padrão o porgrama é executado de maneira silenciosa (sem mensagens informativas). Essas configurações podem ser alteradas quando se executa o binário diretamente (sem utilizar o makefile) alterando os argumentos do programa. 

O programa admite 2 argumentos opcionais: o primeiro é a ordem das matrizes quadradas; o segundo define a execução no modo "verbose". Para executar no modo "verbose" o segundo argumento deve ser necessariamente 'v' e é necessário definir a ordem das matrizes no primeiro argumento. Ex: `./tp3.out <ordem> v`.

## Execução do programa

* **Preparação:** A primeira linha lida pela entrada padrão deve conter dois **inteiros positvos** separados por um espaço, `a b`.** Onde é **a** é o número de matrizes nas folhas da árvore de segmentação e **b** é número de operações a serem executadas até o fim do programa - conforme a especificação. Uma árvore com **a** folhas será carregada, sendo que todas os nós serão inicialmente matrizes identidades.
* **Atualização (u):** `u x`. Onde **x** indica qual folha da árvore será atualizada. Em seguida deve-se colocar linha a linha o valor das novas entradas da matriz. As entradas devem ser separadas por um espaço e as linhas separadas por uma quebra de linha (ENTER). Apenas inteiros não negativos são aceitos por valores de entrada.
* **Consulta (q):** `q a b x y`. Onde **a** e **b** definem o intervalo de segmentação e **x** e **y** definem as entradas do vetor coluna ao qual se aplicarão as transformações lineares definidas no intervalo de segmentação. O resultado será impresso como um vetor coluna transposto (ou seja: em uma linha).



 
