/*
Na matemática a união de dois conjuntos A e B é representada por A ∪ B e é formada por todos os elementos pertencentes a A ou B. Por exemplo, seja A = {1, 2, 3} e B = {4, 5}, então a união destes dois conjuntos será A ∪ B = {1, 2, 3, 4, 5}, porém caso um elemento esteja em ambos os conjuntos ele não irá aparecer duas vezes no conjunto união, por exemplo, seja A = {1, 2, 3} e B = {1, 2, 4}, assim a união será A ∪ B = {1, 2, 3, 4}.

Utilizando os conceitos de conjunto faça um programa que leia dois vetores A e B e determine a união. O tamanho de cada vetor será informado pelo usuário.

Obs.: Considere que não existirão vetores vazios.

Obs.2: Os vetores devem ser alocados dinamicamente.

Entradas:

Tamanho do vetor A.
Elementos do vetor A.
Tamanho do vetor B.
Elementos do vetor B.
Saídas:

Vetor C representado a união dos vetores A e B.
Exemplo de Entrada:

3
1 2 3
2
2 4
Exemplo de Saída:

1 2 3 4
*/

#include <iostream>

using namespace std;

int *uniao(int *vetor1, int *vetor2, int N1, int N2, int &tamanho)
{
  int *vetor = new int[N1 + N2];
  int j = 0;
  for (int i = 0; i < N1; i++)
  {
    vetor[j] = vetor1[i];
    j++;
  }
  for (int i = 0; i < N2; i++)
  {
    bool repetido = false;
    for (int k = 0; k < N1; k++)
    {
      if (vetor2[i] == vetor1[k])
      {
        repetido = true;
      }
    }
    if (!repetido)
    {
      vetor[j] = vetor2[i];
      j++;
    }
  }
  tamanho = j;
  return vetor;
}

int main()
{
  int N1;
  cin >> N1;
  int *vetor1 = new int[N1];
  for (int i = 0; i < N1; i++)
  {
    cin >> vetor1[i];
  }

  int N2;
  cin >> N2;
  int *vetor2 = new int[N2];
  for (int i = 0; i < N2; i++)
  {
    cin >> vetor2[i];
  }

  int tamanho = N1 + N2;
  int *vetor = uniao(vetor1, vetor2, N1, N2, tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    cout << vetor[i] << " ";
  }
  cout << endl;

  delete[] vetor1;
  delete[] vetor2;
  delete[] vetor;

  return 0;
}