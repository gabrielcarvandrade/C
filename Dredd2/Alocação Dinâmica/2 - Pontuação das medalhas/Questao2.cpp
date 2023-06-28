/*O Comitê Olímpico Internacional (COI) resolveu criar uma tabela de pontuação das Olimpíadas para ser usada no lugar do Quadro de Medalhas. A ideia é que cada tipo de medalha (ouro, prata e bronze) tenha uma pontuação diferente. Assim, a pontuação de um time seria baseada na quantidade de medalhas recebidas e nessa pontuação.

O COI precisa definir qual será a pontuação de cada tipo de medalha e, para testar isso, pediu a você para fazer um programa que receba quantos pontos valem cada tipo de medalha e a quantidade de medalhas de um determinado país. Seu programa deverá então exibir a pontuação daquele país nessa tabela de pontuação proposta.

Para isso seu programa deve:

Guardar os pontos de cada tipo de medalha em memória alocada dinamicamente.
Criar um registro para guardar as quantidades de medalhas do país.
Usar alocação dinâmica para guardar o registro acima.
Entradas:

Três números inteiros representando quantos pontos valem os tipos de medalha (ouro, prata e bronze, nessa ordem).
Três números inteiros representando a quantidade de medalhas recebida por um determinado país (de ouro, de prata e de bronze, nessa ordem).
Saídas:

A pontuação do país na tabela proposta pelo COI.
Exemplo de Entrada:

10 5 1
2 2 2
Exemplo de Saída:

32
*/

#include <iostream>

using namespace std;

struct Medalhas
{
  int ouro;
  int prata;
  int bronze;
};

int calculoPontuacao(Medalhas *medalhas, int *pontos)
{
  int pontuacao = (medalhas->ouro * pontos[0]) + (medalhas->prata * pontos[1]) + (medalhas->bronze * pontos[2]);

  return pontuacao;
}

int main()
{
  int *pontos = new int[3];
  Medalhas *medalhas = new Medalhas;

  for (int i = 0; i < 3; i++)
  {
    cin >> pontos[i];
  }

  cin >> medalhas->ouro;
  cin >> medalhas->prata;
  cin >> medalhas->bronze;

  int pontuacao = calculoPontuacao(medalhas, pontos);

  cout << pontuacao << endl;
  return 0;
}