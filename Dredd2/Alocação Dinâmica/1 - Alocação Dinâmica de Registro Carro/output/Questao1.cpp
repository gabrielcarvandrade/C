/*Faça um programa que crie um registro Carro com os campos: marca, ano, distância percorrida na última viagem (em quilômetros) e consumo de combustível na última viagem (em litros). Seu programa deverá alocar dinamicamente uma variável do tipo Carro e ler, a partir de um arquivo texto chamado "entrada.txt", as informações de um carro em particular. Em seguida, faça um subprograma que receba como entrada as informações lidas e retorne à função principal quantos quilômetros por litro o carro em questão realizou em sua última viagem. As informações da marca, ano do carro, consumo de combustível na última viagem (em litros) e o resultado obtido pela função, devem ser gravados em um outro arquivo chamado "saida.txt". Assuma que o carro sempre terá consumido alguma quantidade de combustível.

Entradas (conteúdo do arquivo):

Cadeia de caracteres representando a marca de um carro (sem espaços).
Inteiro indicando o ano de fabricação do carro.
Ponto flutuante indicando a distância percorrida pelo carro em sua última viagem.
Ponto flutuante indicando o consumo realizado pelo carro em sua última viagem.
Saída (conteúdo do arquivo):

Cadeia de caracteres representando a marca de um carro (sem espaços).
Inteiro indicando o ano de fabricação do carro.
Ponto flutuante indicando o consumo realizado pelo carro em sua última viagem.
Ponto flutuante indicando quantos quilômetros por litro o carro realizou em sua última viagem.
Exemplo de Entrada (conteúdo do arquivo):

palio
2008
62.5
5.3
Exemplo de Saída (conteúdo do arquivo):

palio
2008
5.3
11.79
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Carro
{
  string marca;
  int ano;
  float distanciaPercorridaKm;
  float consumoL;
};

float consumo(Carro *carro, float &consumoMedio)
{
  consumoMedio = (carro->distanciaPercorridaKm / carro->consumoL);

  return 0;
}

int main()
{

  Carro *carro = new Carro;

  ifstream arquivoIn("entrada.txt");
  ofstream arquivoOut("saida.txt");

  arquivoIn >> carro->marca;
  arquivoIn >> carro->ano;
  arquivoIn >> carro->distanciaPercorridaKm;
  arquivoIn >> carro->consumoL;

  float consumoMedio;

  consumo(carro, consumoMedio);

  arquivoOut << carro->marca << endl;
  arquivoOut << carro->ano << endl;
  arquivoOut << carro->consumoL << endl;
  arquivoOut << setprecision(2) << fixed << consumoMedio << endl;

  return 0;
}