/*Faça um programa que lê um vetor de números inteiros e depois escreve todos os números entre dois marcadores de limite na ordem inversa. Os limites não farão parte da saída.

Os marcadores não precisam estar em ordem, ou seja, o primeiro marcador não necessariamente precisa vir antes do segundo. Observe os exemplos a seguir.

Obs: os vetores devem ser alocados dinamicamente.

Entradas:

Quantidade de elementos do vetor.
Linha contendo os números inteiros do vetor (separados entre si por espaço).
Linha contendo os dois números delimitadores (separados entre si por espaço).
Saídas:

Números do vetor entre os delimitadores, na ordem inversa da leitura.
Exemplo de entrada:

6
9 2 3 4 5 6
2 6
Exemplo de saída:

5 4 3
Exemplo de entrada:

7
8 -1 2 4 5 0 3
5 -1
Exemplo de saída:

4 2
*/
#include <iostream>

using namespace std;

int main()
{
  int qtElementos;
  cin >> qtElementos;

  int *numeros = new int[qtElementos];

  for (int i = 0; i < qtElementos; i++)
  {
    cin >> numeros[i];
  }

  int marcadorUm;
  int marcadorDois;

  cin >> marcadorUm >> marcadorDois;

  int inicio;

  for (int i = 0; i < qtElementos; i++)
  {
    if (numeros[i] == marcadorUm or numeros[i] == marcadorDois)
    {
      inicio = i;
      i = qtElementos;
    }
  }

  int *saidaNumeros = new int[qtElementos];

  int fim;

  for (int i = inicio + 1; i < qtElementos; i++)
  {
    if (numeros[i] == marcadorUm || numeros[i] == marcadorDois)
    {
      fim = i - 1;
      i = qtElementos;
    }
  }

  for (int i = fim; i > inicio; i--)
  {
    saidaNumeros[i] = numeros[i];
    cout << saidaNumeros[i] << " ";
  }

  return 0;
}