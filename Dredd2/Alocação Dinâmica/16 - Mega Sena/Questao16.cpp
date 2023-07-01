/*
Declare um registro para armazenar um resultado de um sorteio da mega sena. Faça um programa que receba do usuário uma quantidade de sorteios e as dezenas sorteadas, armazenando-as em um vetor alocado dinamicamente. Faça então um subprograma que receba esse vetor e retorne um ponteiro para o registro que tenha a maior soma de dezenas sorteadas. Por fim, exiba os dados do registro retornado.

Entrada:

Um número indicando a quantidade de sorteios.
As dezenas sorteadas em cada sorteio (vetor alocado dinamicamente).
Saída:

As dezenas do registro que tem a maior soma de dezenas sorteadas.
Exemplo de entrada:

3
41 44 48 50 54 57
02 17 22 24 48 51
14 34 46 47 56 57
Exemplo de saída:

41 44 48 50 54 57
*/

#include <iostream>

using namespace std;

struct MegaSena
{
  int dezenas[6];
  int soma;
};

MegaSena *maiorSoma(int *vetor, int N)
{
  MegaSena *maior = new MegaSena;
  maior->soma = 0;
  for (int i = 0; i < N; i++)
  {
    int soma = 0;
    for (int j = 0; j < 6; j++)
    {
      soma += vetor[i * 6 + j];
    }
    if (soma > maior->soma)
    {
      maior->soma = soma;
      for (int j = 0; j < 6; j++)
      {
        maior->dezenas[j] = vetor[i * 6 + j];
      }
    }
  }
  return maior;
}

int main()
{
  int N;
  cin >> N;
  int *vetor = new int[N * 6];
  for (int i = 0; i < N * 6; i++)
  {
    cin >> vetor[i];
  }

  MegaSena *maior = maiorSoma(vetor, N);

  for (int i = 0; i < 6; i++)
  {
    cout << maior->dezenas[i] << " ";
  }
  cout << endl;

  return 0;
}