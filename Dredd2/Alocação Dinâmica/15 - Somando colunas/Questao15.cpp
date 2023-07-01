/*
Escreva uma função que receba como parâmetro uma matriz A 5 x 5 de inteiros. A função deve retornar o ponteiro para um vetor B de tamanho 5 alocado dinamicamente, em que cada posição de B é a soma dos números da coluna correspondente da matriz A.

Entradas:

Os elementos da matriz A
Saídas:

Os elementos do vetor B
Exemplo de Entrada:

1 2 3 4 5
5 4 3 2 1
1 1 1 1 1
2 2 2 2 2
9 8 7 6 5
Exemplo de Saída:

18 17 16 15 14
*/

#include <iostream>

using namespace std;

int *somaColunas(int **matriz, int N)
{
  int *vetor = new int[N];
  for (int i = 0; i < N; i++)
  {
    vetor[i] = 0;
    for (int j = 0; j < N; j++)
    {
      vetor[i] += matriz[j][i];
    }
  }

  return vetor;
}

int main()
{
  int N = 5;
  int **matriz = new int *[N];
  for (int i = 0; i < N; i++)
  {
    matriz[i] = new int[N];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> matriz[i][j];
    }
  }

  int *vetor = somaColunas(matriz, N);

  for (int i = 0; i < N; i++)
  {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}