/*
Gargamel irá mais uma vez tentar algo contra os Smurfs. Dessa vez, ele irá tentar não apenas uma, mas duas poções mágicas de uma única vez. Para isso, ele fez uma lista com os ingredientes de cada poção, para poder comprá-los na Lojinha da Maga Patalógica. Como ele fez duas listas, uma para cada poção, ele precisa agora juntá-las, mas destacando os itens da primeira lista que não fazem parte da segunda.

Para ajudá-lo, você irá implementar um algoritmo que armazena os valores da primeira lista em um vetor alocado dinamicamente. Em seguida, irá receber, via dispositivo de entrada padrão, cada item da segunda lista. Caso o item lido ainda não esteja presente na lista armazenada, o vetor deve ser redimensionado com o aumento de uma posição e o valor armazenado. Caso contrário, um novo valor é lido. Considere que os itens das listas não possuem espaço e que nenhuma lista possui itens repetidos na própria lista. Ao final, imprima o tamanho resultante do vetor e os seus itens.

Entradas:

Quantidade de ingredientes da primeira lista.
Ingredientes (strings) da primeira lista.
Quantidade de ingredientes da segunda lista.
Ingredientes (strings) da segunda lista.
Saídas:

Tamanho do vetor resultante.
Elementos da lista resultante.
Exemplo de Entrada:

5
asa_de_aranha
pe_de_piranha
pelo_de_minhoca
olho_de_pedra
glitter_rosa
6
glitter_rosa
dente_de_rosa
piolho_de_peixe
pe_de_piranha
pelo_de_minhoca
bolor_laranja
Exemplo de Saída:

8
asa_de_aranha
pe_de_piranha
pelo_de_minhoca
olho_de_pedra
glitter_rosa
dente_de_rosa
piolho_de_peixe
bolor_laranja
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string *vetor = new string[N];
  for (int i = 0; i < N; i++)
  {
    cin >> vetor[i];
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; i++)
  {
    string ingrediente;
    cin >> ingrediente;
    bool repetido = false;
    for (int j = 0; j < N; j++)
    {
      if (ingrediente == vetor[j])
      {
        repetido = true;
      }
    }
    if (!repetido)
    {
      N++;
      string *vetorNovo = new string[N];
      for (int j = 0; j < N - 1; j++)
      {
        vetorNovo[j] = vetor[j];
      }
      vetorNovo[N - 1] = ingrediente;
      delete[] vetor;
      vetor = vetorNovo;
    }
  }

  cout << N << endl;
  for (int i = 0; i < N; i++)
  {
    cout << vetor[i] << endl;
  }

  delete[] vetor;
  return 0;
}