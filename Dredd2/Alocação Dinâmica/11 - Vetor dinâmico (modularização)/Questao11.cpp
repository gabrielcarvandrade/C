/*
Faça um programa que guarda números num vetor dinâmico. Não se sabe quantos números deverão ser armazenados até que se saiba quais são os números.

A estratégia de alocação de memória deve ser a seguinte:

o vetor é criado inicialmente com capacidade 5,
conforme é feito o armazenamento de números no vetor, novos espaços de memória vão sendo alocados, sempre com 5 elementos a mais do que antes. Ou seja, um novo vetor com capacidade anterior mais 5 será alocado; os elementos devem ser copiados para o novo vetor e o antigo deve ser desalocado. Use subprogramas.
O programa deverá ler números inteiros positivos da entrada padrão. O último número na entrada de dados será um número não positivo, indicando o fim dos números. Considera-se que o zero não é positivo, conforme pode ser visto no exemplo de entrada.

Ao final da entrada de dados, o programa deverá:

Escrever todos os números (não negativos) armazenados.
Escrever qual a capacidade atual do vetor.
Escrever o número de transformações (realocações na memória) necessárias.
Exemplo de Entrada:

10 18 15 71 42 41 20 18 35 14 13 0
Exemplo de Saída:

10 18 15 71 42 41 20 18 35 14 13
15
2
*/

#include <iostream>

using namespace std;

int verificacaoTamanho(int i, int &tamanho, int *vet, int &transformacoes)
{
  if (i == tamanho)
  {
    int *vetNovo = new int[tamanho + 5];
    copy(vet, vet + tamanho, vetNovo);

    vet = vetNovo;

    tamanho += 5;

    transformacoes++;
  }

  return 0;
}

int main()
{

  int tamanho = 5;
  int *vet = new int[tamanho];

  int transformacoes = 0;

  int numero;
  cin >> numero;
  int i = 0;

  while (numero > 0)
  {
    vet[i] = numero;

    verificacaoTamanho(i, tamanho, vet, transformacoes);

    i++;

    cin >> numero;
  }

  for (int j = 0; j < i; j++)
  {
    cout << vet[j] << " ";
  }

  cout << endl
       << tamanho << endl
       << transformacoes << endl;

  return 0;
}
