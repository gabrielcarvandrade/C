/*
Faça um programa que armazene, em um vetor alocado dinamicamente, uma quantidade N de números inteiros. Em seguida, identifique e remova os elementos repetidos. O vetor deve ser redimensionado e passar a armazenar apenas elementos não repetidos. Ao fim, seu programa deve imprimir na saída padrão o tamanho atual do vetor e os elementos armazenados.

Entradas:

Quantidade N de números inteiros
Números armazenados no vetor.
Saídas:

Tamanho atual do vetor.
Elementos atuais do vetor.
Exemplo de Entrada:

10
3 5 12 55 3 78 22 55 34 10
Exemplo de Saída:

8
3 5 12 55 78 22 34 10
*/
#include <iostream>

using namespace std;

int *removerRepetidos(int *vetor, int N, int &tamanho)
{
  int *vetorNovo = new int[N];
  int j = 0;
  for (int i = 0; i < N; i++)
  {
    bool repetido = false;
    for (int k = 0; k < j; k++)
    {
      if (vetor[i] == vetorNovo[k])
      {
        repetido = true;
      }
    }
    if (!repetido)
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
  vetor = removerRepetidos(vetor, N, tamanho);

  cout << tamanho << endl;
  for (int i = 0; i < tamanho; i++)
  {
    cout << vetor[i] << " ";
  }
  cout << endl;

  return 0;
}
