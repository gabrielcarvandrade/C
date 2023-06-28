/*Dois vetores são considerados iguais se ambos contiverem o mesmo conjunto de elementos, embora as permutações de elementos possam ser diferentes.

Faça um programa para receba o tamanho N de dois vetores A e B de igual tamanho e descobra se os vetores são iguais ou não.

Se forem iguais imprima "IGUAIS", caso contrário imprima "DIFERENTES".

Observação: não haverá elementos repetidos em cada vetor.

Exemplo de Entrada:

5
1 2 3 4 5
5 4 3 2 1
Exemplo de Saída:

IGUAIS
Exemplo de Entrada:

5
1 2 3 6 5
5 4 3 2 1
Exemplo de Saída:

DIFERENTES
*/
#include <iostream>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int *numeros = new int[N];

  for (int i = 0; i < N; i++)
  {
    cin >> numeros[i];
  }

  int *numerosOutros = new int[N];

  for (int i = 0; i < N; i++)
  {
    cin >> numerosOutros[i];
  }

  int contIguais = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (numeros[i] == numerosOutros[j])
        contIguais++;
    }
    if (contIguais == N)
      i = N;
  }

  if (contIguais == N)
    cout << "IGUAIS" << endl;
  else
    cout << "DIFERENTES" << endl;

  return 0;
}