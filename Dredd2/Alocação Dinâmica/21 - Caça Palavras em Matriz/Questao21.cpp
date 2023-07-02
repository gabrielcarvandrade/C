/*
Desenvolva um programa que receba uma matriz nxn (n fornecido pelo usuário) de caracteres (um caractere em cada posição da matriz). O usuário digitará m palavras (m informado na entrada). O programa deve procurar a ocorrência de cada palavra na matriz, imprimindo as coordenadas da primeira letra ou -1 -1 se a palavra não existir. A procura deve ser feita na horizontal (da esquerda para direita) e na vertical (de cima para baixo).

OBS: Letras maiúsculas e minúsculas são diferenciadas. A matriz deve ser alocada dinamicamente. A função strlen() retorna o tamanho de uma string tipo C (vetor de caracteres) e o método length() ou size() pode ser usado para pegar o tamanho de uma string do C++.

Entradas:

Tamanho do lado da matriz (n)
Matriz de caracteres (nxn)
Número de palavras (m)
Palavras sem espaços, uma em cada linha
Saídas:

Posição da letra inicial de cada palavra na matriz, na ordem em que as palavras foram lidas.
Exemplo de Entrada:

3
A B C
D E F
G H I
2
BE
FI
Exemplo de Saída:

0 1
1 2
*/

#include <iostream>
#include <string.h>

using namespace std;

int *buscaPalavra(char **matriz, int N, string palavra, int &tamanho)
{
  int *vetor = new int[2];
  vetor[0] = -1;
  vetor[1] = -1;
  for (int i = 0; i < N; i++)
  {
    for (unsigned j = 0; j < N - palavra.length() + 1; j++)
    {
      bool encontrou = true;
      for (unsigned k = 0; k < palavra.length(); k++)
      {
        if (matriz[i][j + k] != palavra[k])
        {
          encontrou = false;
        }
      }
      if (encontrou)
      {
        vetor[0] = i;
        vetor[1] = j;
        tamanho = palavra.length();
        return vetor;
      }
    }
  }
  for (unsigned i = 0; i < N - palavra.length() + 1; i++)
  {
    for (int j = 0; j < N; j++)
    {
      bool encontrou = true;
      for (unsigned k = 0; k < palavra.length(); k++)
      {
        if (matriz[i + k][j] != palavra[k])
        {
          encontrou = false;
        }
      }
      if (encontrou)
      {
        vetor[0] = i;
        vetor[1] = j;
        tamanho = palavra.length();
        return vetor;
      }
    }
  }
  return vetor;
}

int main()
{
  int N;
  cin >> N;
  char **matriz = new char *[N];
  for (int i = 0; i < N; i++)
  {
    matriz[i] = new char[N];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> matriz[i][j];
    }
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    string palavra;
    cin >> palavra;
    int tamanho;
    int *vetor = buscaPalavra(matriz, N, palavra, tamanho);
    cout << vetor[0] << " " << vetor[1] << endl;
  }

  return 0;
}