/*
Faça um programa que cadastre o sobrenome e as idades de famílias de 3 membros cada (idade do pai, da mãe e do filho). Os dados devem ser lidos em um arranjo alocado dinamicamente, inicialmente com tamanho 3. A leitura deve ser encerrada quando for lida a palavra FIM como nome da familia. Após o término da leitura dos dados, identifique os casais que possuem filhos de mesma idade e armazene os sobrenomes das famílias envolvidas na igualdade. Caso não haja correspondentes, deve ser impressa a mensagem NENHUM.

Restrições adicionais:
! As idades dos membros de uma família devem ser armazenadas em um registro.
! O tamanho inicial do vetor a ser utilizado é 3 e devem ser acrescentadas 3 posições a cada redimensionamento.

Entradas:

Conjunto de sobrenomes e idades das famílias
Saídas:

Tamanho do vetor a cada redimensionamento do vetor de entrada.
Sobrenome das famílias com filhos de mesma idade.
Entradas:
Silva 44 41 17
Araujo 54 49 19
Pires 25 30 4
Correia 29 27 19
Paulino 60 65 19
Moreira 29 28 4
Matos 42 41 14
FIM

Saídas:
6
9
Araujo
Correia
Paulino
Pires
Moreira

Entradas:

Castro 44 41 17
Gomes 38 36 15
Perez 44 49 19
FIM

Saídas:
NENHUM


Entradas:
Xavier 50 41 10
Salles 58 56 20
Geraldi 44 49 10
Torres 44 49 20
FIM

Saídas:
6
Xavier
Geraldi
Salles
Torres
*/

#include <iostream>
#include <vector>

using namespace std;

struct Familia
{
  string nome;
  int idadePai;
  int idadeMae;
  int idadeFilho;
};

void alocacaoFamilia(int i, int &tamanho, Familia *&familia, int *&tamanhos, int &contTamanhos)
{

  if (i == tamanho)
  {
    int novoTamanho = tamanho + 3;
    Familia *novaFamilia = new Familia[novoTamanho];

    if (tamanho != novoTamanho)
    {
      tamanhos[contTamanhos] = novoTamanho;
    }

    for (int j = 0; j < tamanho; j++)
    {
      novaFamilia[j] = familia[j];
    }

    delete[] familia;
    delete[] tamanhos;

    familia = novaFamilia;
    tamanho = novoTamanho;

    contTamanhos++;
  }
}

int main()
{
  int tamanho = 3;
  Familia *familia = new Familia[tamanho];
  int *tamanhos = new int[tamanho];

  int i = 0;
  int contTamanhos = 0;
  bool fim = false;
  while (!fim)
  {
    string tentativaFim;
    cin >> tentativaFim;

    if (tentativaFim != "FIM")
    {
      alocacaoFamilia(i, tamanho, familia, tamanhos, contTamanhos);
      familia[i].nome = tentativaFim;
      cin >> familia[i].idadePai;
      cin >> familia[i].idadeMae;
      cin >> familia[i].idadeFilho;
      i++;
    }
    else
    {
      fim = true;
    }
  }

  vector<string> mesmaIdade;

  int *idadesFilhos = new int[i];
  int contIdadesFilhos = 0;
  for (int j = 0; j < i; j++)
  {
    bool repetido = false;
    for (int k = 0; k < contIdadesFilhos; k++)
    {
      if (familia[j].idadeFilho == idadesFilhos[k])
      {
        repetido = true;
      }
    }

    if (!repetido)
    {
      idadesFilhos[contIdadesFilhos] = familia[j].idadeFilho;
      contIdadesFilhos++;
    }
  }

  for (int j = 0; j < contIdadesFilhos; j++)
  {
    int cont = 0;
    for (int k = 0; k < i; k++)
    {
      if (idadesFilhos[j] == familia[k].idadeFilho)
      {
        cont++;
      }
    }

    if (cont > 1)
    {
      for (int k = 0; k < i; k++)
      {
        if (idadesFilhos[j] == familia[k].idadeFilho)
        {
          mesmaIdade.push_back(familia[k].nome);
        }
      }
    }
  }

  for (int j = 0; j < contTamanhos; j++)
  {
    cout << tamanhos[j] << endl;
  }

  if (mesmaIdade.size() == 0)
  {
    cout << "NENHUM" << endl;
  }
  else
  {
    for (unsigned j = 0; j < mesmaIdade.size(); j++)
    {
      cout << mesmaIdade[j] << endl;
    }
  }
  delete[] familia;
  delete[] tamanhos;

  return 0;
}
