/*Um hidrocarboneto é um composto químico formado por átomos de carbono e hidrogênio. Faça um programa que crie um registro chamado Hidrocarboneto contendo os campos inteiros C e H usados para guardar a quantidade de carbonos e hidrogênios, respectivamente, de um hidrocarboneto. No subprograma principal aloque dinamicamente um registro Hidrocarboneto e peça ao usuário as quantidades de carbono e hidrogênio do mesmo. Sabendo que massa molecular do carbono é 12 e do hidrogênio é 1, seu programa deverá calcular e exibir a massa molecular do composto.

Entradas:

Quantidade de carbonos do hidrocarboneto.
Quantidade de hidrogênios do hidrocarboneto.
Saídas:

Massa molecular do hidrocarboneto.
Exemplo de Entrada:

1 4
Exemplo de Saída:

16
*/

#include <iostream>

using namespace std;

struct Hidrocarboneto
{
  int C;
  int H;
};

int calculoMassaMolecular(Hidrocarboneto *hidrocarboneto)
{
  int massaMolecular = (hidrocarboneto->C * 12) + (hidrocarboneto->H);
  return massaMolecular;
}

int main()
{

  Hidrocarboneto *hidrocarboneto = new Hidrocarboneto;

  cin >> hidrocarboneto->C;
  cin >> hidrocarboneto->H;

  int massaMolecular;
  massaMolecular = calculoMassaMolecular(hidrocarboneto);

  cout << massaMolecular << endl;

  return 0;
}