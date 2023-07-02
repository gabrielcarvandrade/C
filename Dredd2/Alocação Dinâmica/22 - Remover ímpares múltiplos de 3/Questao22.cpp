/*
Faça um programa que armazene, em um vetor alocado dinamicamente, um conjunto N de números inteiros. Em seguida, identifique e remova os números ímpares que sejam múltiplos de 3. O vetor deve ser redimensionado de modo a armazenar todos os números pares e apenas os ímpares não múltiplos de 3. Ao final, deve ser impresso na saída padrão o tamanho e os elementos do vetor resultante.

Entradas:

Quantidade N de números inteiros.
Números armazenados.
Saídas:

Tamanho do vetor resultante.
Elementos do vetor resultante.
Exemplo de Entrada:

10
1 2 3 4 5 6 7 8 9 10
Exemplo de Saída:

8
1 2 4 5 6 7 8 10
*/

#include <iostream>

using namespace std;

int *removerImparesMultiplosDe3(int *vetor, int N, int &tamanho)
{
  int *vetorNovo = new int[N];
  int j = 0;
  for (int i = 0; i < N; i++)
  {
    if (vetor[i] % 2 == 0 || vetor[i] % 3 != 0)
    {
      vetorNovo[j] = vetor[i];
      j++;
    }
  }
  tamanho = j;
  return vetorNovo;
}

int main()
{
  int N;
  cin >> N;
  int *vetor = new int[N];
  for (int i = 0; i < N; i++)
  {
    cin >> vetor[i];
  }

  int tamanho = N;
  vetor = removerImparesMultiplosDe3(vetor, N, tamanho);

  cout << tamanho << endl;
  for (int i = 0; i < tamanho; i++)
  {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}