/*
Luthor irá mais uma vez tentar algo contra o Super-Homem. Dessa vez, ele irá tentar o plano XTPO-3000-PlusAzul. Para isso, ele fez uma lista com os materiais necessários e verificou que alguns itens estavam em falta. Ele tem uma relação em computador dos itens que precisa para a invenção e uma lista dos itens que tem em posse na sua fábrica (alguns dos quais não serão necessários no plano, inclusive). Assim, ele precisa verificar quais itens da primeira lista não constam na segunda lista para poder ir buscá-los em seu estoque no subsolo.

Para ajudá-lo, você irá implementar um algoritmo que recebe duas listas de materiais (dois vetores de strings) e imprime todos os itens que constam na primeira lista mas não constam na segunda lista. Os vetores devem ser implementados utilizando alocação dinâmica. A impressão deverá ser feita seguindo a ordem da primeira lista. Considere que os itens das listas não possuem espaço, cada lista contém o número de materiais no topo e que nenhuma lista possui itens repetidos na própria lista. Caso todos os itens da primeira lista estejam presentes na segunda, imprima NADA (todo em maiúsculo).

Entradas:

Número de ingredientes da primeira lista.
ingredientes (strings) da primeira lista, separados por espaço.
Número de ingredientes da segunda lista.
ingredientes (strings) da segunda lista, separados por espaço.
Saídas:

Elementos da lista resultante.
Exemplo de Entrada:

5
rubi_axial
kriptonita_rosa
xisto
cesio137
uranio_enriquecido
6
uranio_enriquecido
sulfato_de_titanio
bateria_18650
kriptonita_rosa
xisto
virus_simancol
Exemplo de Saída:

rubi_axial
cesio137
Exemplo de Entrada:

5
rubi_axial
kriptonita_rosa
xisto
cesio137
uranio_enriquecido
6
rubi_axial
kriptonita_rosa
xisto
cesio137
uranio_enriquecido
bateria_18650
Exemplo de Saída:

NADA
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int N1;
  cin >> N1;
  string *lista1 = new string[N1];
  for (int i = 0; i < N1; i++)
  {
    cin >> lista1[i];
  }

  int N2;
  cin >> N2;
  string *lista2 = new string[N2];
  for (int i = 0; i < N2; i++)
  {
    cin >> lista2[i];
  }

  int contIguais = 0;
  bool achou = false;
  for (int i = 0; i < N1; i++)
  {
    achou = false;
    for (int j = 0; j < N2; j++)
    {
      if (lista1[i] == lista2[j])
      {
        achou = true;
        contIguais++;
      }
    }
    if (!achou)
    {
      cout << lista1[i] << endl;
    }
  }

  if (contIguais == N1)
  {
    cout << "NADA" << endl;
  }

  return 0;
}
