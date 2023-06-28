/*Faça um programa que receba a quantidade de números que o usuário digitará e em seguida preencha um vetor com os números inteiros, calcule e mostre: os números múltiplos de 2; os números múltiplos de 3; e os números múltiplos de 2 e 3. Os números múltiplos de 2 e 3 podem aparecer nos casos isolados. Caso não exista nenhum número em cada caso, o programa deve retornar 0 na respectiva saída.

Observação: o vetor deverá ser alocado dinamicamente

Entradas:

Quantidade de números a serem inseridos pelo usuário/li>
Sequência de números inteiros
Saídas:

Números que são múltiplos de 2;
Números que são múltiplos de 3;
Números que são múltiplos de 2 e 3 simultaneamente.
Exemplo de entrada:

7
4 6 3 9 7 10 13
Exemplo de saída:

4 6 10
6 3 9
6
*/
#include <iostream>

using namespace std;

int main()
{
  int qtNumeros;
  cin >> qtNumeros;

  int *numeros = new int[qtNumeros];

  for (int i = 0; i < qtNumeros; i++)
  {
    cin >> numeros[i];
  }

  int *multiplosDois = new int[qtNumeros];
  int *multiplosTres = new int[qtNumeros];
  int *multiplosDoisTres = new int[qtNumeros];

  int contDois = 0;
  int contTres = 0;
  int contDoisTres = 0;

  for (int i = 0; i < qtNumeros; i++)
  {
    if (numeros[i] % 2 == 0)
    {
      multiplosDois[contDois] = numeros[i];
      contDois++;
    }

    if (numeros[i] % 3 == 0)
    {
      multiplosTres[contTres] = numeros[i];
      contTres++;
    }

    if (numeros[i] % 2 == 0 and numeros[i] % 3 == 0)
    {
      multiplosDoisTres[contDoisTres] = numeros[i];
      contDoisTres++;
    }
  }

  if (contDois == 0)
    cout << "0";
  else
  {
    for (int i = 0; i < contDois; i++)
    {
      cout << multiplosDois[i] << " ";
    }
  }
  cout << endl;

  if (contTres == 0)
    cout << "0";
  else
  {
    for (int i = 0; i < contTres; i++)
    {
      cout << multiplosTres[i] << " ";
    }
  }
  cout << endl;

  if (contDoisTres == 0)
    cout << "0";
  else
  {
    for (int i = 0; i < contDoisTres; i++)
    {
      cout << multiplosDoisTres[i] << " ";
    }
  }
  cout << endl;

  delete[] numeros;
  delete[] multiplosDois;
  delete[] multiplosTres;
  delete[] multiplosDoisTres;

  return 0;
}
