/*
Faça um programa que crie uma matriz de números reais. Leia os valores da matriz e depois multiplique todos elementos de cada linha pelo maior elemento em módulo da linha. Escreva o resultado.

O módulo (ou valor absoluto) de um número é o mesmo sem sinal.

Não é permitido criar qualquer vetor ou matriz sem usar alocação dinâmica.

Entradas:

Número de linhas da matriz e número de colunas da matriz.
Elementos da matriz (números reais).
Saídas:

Matriz após as operações.
Exemplo de entrada:

3 3
1.8  9  18
-50 10   5
 -4 -8 -16
Exemplo de saída:

 32.4  162  324
-2500  500  250
  -64 -128 -256
*/

#include <iostream>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  float **matriz = new float *[N];
  for (int i = 0; i < N; i++)
  {
    matriz[i] = new float[M];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> matriz[i][j];
    }
  }

  for (int i = 0; i < N; i++)
  {
    float maior = matriz[i][0];
    for (int j = 0; j < M; j++)
    {
      if (std::abs(matriz[i][j]) > maior) // tive que usar std:: para nao dar conflito com a funcao abs
      {
        maior = std::abs(matriz[i][j]);
      }
    }
    for (int j = 0; j < M; j++)
    {
      matriz[i][j] *= maior;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
