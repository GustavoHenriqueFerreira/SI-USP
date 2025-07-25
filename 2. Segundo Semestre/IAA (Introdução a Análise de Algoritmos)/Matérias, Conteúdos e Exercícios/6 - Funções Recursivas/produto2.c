#include <stdio.h>
#include <stdlib.h>

int produto (int a, int b) {
  if (b<=0) {
	  puts ("produto (a,b): Por favor desprezar resultado - b precisa ser inteiro e positivo.");
	  return 0;
  }
  if (b==1) return a;
  return 2*produto(a,b/2)+((b%2)?a:0);
}
 
void main (void) {
  int a=5, b=6;
  printf ("%d", produto(a,b));
}
