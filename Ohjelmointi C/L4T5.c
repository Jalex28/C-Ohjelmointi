#include<stdio.h>

int laskentaohjelma (int n)
{
  if (n == 0)
    {
      return 0;
    }
  else if (n == 1)
    {
      return 1;
    }
  else
    {
      return (laskentaohjelma (n - 1) + laskentaohjelma (n - 2));
    }
}

int main ()
{
  int n, tulos;
  printf ("Anna luku, jolle lasketaan Fibonaccin luku: ");
  scanf ("%d", &n);
  tulos = laskentaohjelma (n);
  printf ("Luvun %d Fibonaccin luku on %d.\n", n, tulos);
  return 0;
}