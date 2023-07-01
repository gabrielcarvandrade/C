/*Faça um programa que receba o tamanho N de um vetor e o preencha. Encontre o segundo menor e o segundo maior elementos, reduza o vetor em duas posições e preencha o novo vetor com os demais elementos, excluindo os dois elementos identificados. Imprima o novo vetor.

Entradas:

int n - Tamanho do vetor.
float vet[n] - Vetor que será preenchido.
Saídas:

Novo vetor, retirando o segundo menor e segundo maior elementos (float).

Exemplos de Entradas e Saídas:
Entradas:
4
3
1
6
5

Saídas:
1
6
*/
#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  float *vet = new float[n];

  for (int i = 0; i < n; i++)
  {
    cin >> vet[i];
  }

  int segundoMaior;
  int segundoMenor;
  for (int i = 0; i < n; i++)
  {
    int contMaior = 0;
    int contMenor = 0;
    for (int j = 0; j < n; j++)
    {
      if (vet[i] > vet[j])
        contMaior++;
      if (vet[i] < vet[j])
        contMenor++;
    }
    if (contMaior == (n - 2))
      segundoMaior = i;
    if (contMenor == (n - 2))
      segundoMenor = i;
  }

  float *vetSaida = new float[n];
  copy(vet, vet + n, vetSaida);
  copy(vet, vet + (n - 2), vet);

  for (int i = 0; i < n; i++)
  {
    if (i != segundoMaior and i != segundoMenor)
      cout << vetSaida[i] << endl;
  }

  delete[] vet;
  delete[] vetSaida;

  return 0;
}