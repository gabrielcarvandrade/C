
#include <iostream>

using namespace std;

int main()
{

  int x, y;
  cin >> x >> y;

  int area;
  cin >> area;

  char matriz[area][area];

  for (int i = 0; i < area; i++)
  {
    for (int j = 0; j < area; j++)
    {
      cin >> matriz[i][j];
    }
  }

  char numeroPadrao;
  numeroPadrao = matriz[x][y];

  int contNumero = 0;
  for (int i = 0; i < area; i++)
  {
    for (int j = 0; j < area; j++)
    {
      if (numeroPadrao == matriz[i][j])
      {
        contNumero++;
      }
    }
  }

  cout << contNumero;

  return 0;
}
