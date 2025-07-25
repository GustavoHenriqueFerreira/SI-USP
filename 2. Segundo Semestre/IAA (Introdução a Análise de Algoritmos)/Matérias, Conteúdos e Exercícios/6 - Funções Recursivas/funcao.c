/* funcao.c - vamos aproveitar que variáveis são criadas e destruidas para satisfazer o escopo de funcoes para saber se estamos no escopo de uma função ou não */

#include <stdio.h>

#if 0
/* mostra que a passagem de parâmetro de tipo array de inteiro é a cópia do valor que a variável contém para o parâmetro (note que os endereços de memória da variável e do parâmetro são diferentes, o que caracteriza que são variáveis diferentes. */
void funcao (int a) {
	printf ("%d, %p\n", a, &a);
}

void main () {
	int a=5;
	funcao (a);
	printf ("%d, %p\n", a, &a);
}
#endif

#if 0
/* mostra que a passagem de parâmetro de tipo array de inteiro é a cópia do valor que a variável contém para o parâmetro (note que os endereços de memória da variável e do parâmetro são diferentes. MAS como o valor (conteúdo) da variável e o valor do parâmetro são iguais, eles correspondem ao mesmo endereço (de memória), permitindo modificar, de dentro da função, o conteúdo do array declarado fora da função. */
void funcao (int *a) {
	printf ("%d, %p, %p\n", a[0], a, &a);
	a[0]=42;
}

void main () {
	int a[]={-5, -4, -3, -2, -1};
	printf ("%d, %p, %p\n", a[0], a, &a);
	funcao (a);
	printf ("%d, %p, %p\n", a[0], a, &a);
}
#endif

#if 0
/* mostra a organização das mensagens que serão usadas para relacionar execução de função e criação de variável local de maneira que a criação e o endereço da variável indiquem que uma função está com escopo ativo. 

O produto é calculado por indução fraca. */

void funcao () {
	int a=67;
	printf ("a variável local funcao.a foi criada e está para ser destruída: %d, %p\n", a, &a);
}

void main () {
	int a=22;
	printf ("a variável local main.a foi criada: %d, %p\n", a, &a);
	funcao (a);
	printf ("a variável local main.a está para ser destruída: %d, %p\n", a, &a);
}
#endif

#if 0
int produto (int a, int b) {
  if (b<=0) {
	  puts ("produto (a,b): Por favor desprezar resultado - b precisa ser inteiro e positivo.");
	  return 0;
  }
  if (b==1) return a;
  int resultado=0;
  printf ("a variável local produto.resultado foi criada: %d, %p\n", resultado, &resultado);
  resultado=a+produto(a,b-1);
  printf ("a variável local produto.resultado está para ser destruída: %d, %p\n", resultado, &resultado);
  return resultado;
}
 
void main (void) {
  int a=5, b=10;
  printf ("%d", produto(a,b));
}

#endif

#if 0
/* indentar para ficar mais fácil de entender... o produto continua sendo feito por indução fraca. */
#include <stdlib.h>
#include <string.h>

int produto (int a, int b, int h) {
  char *indent=(char *) malloc (sizeof(char)*(h+1));
  memset (indent, ' ', h);
  indent[h]=0;  // end of string
  if (b<=0) {
	  puts ("produto (a,b): Por favor desprezar resultado - b precisa ser inteiro e positivo.");
	  return 0;
  }
  if (b==1) return a;
  int resultado=0;
  printf ("%sa variável local produto.resultado foi criada: %d, %p\n", indent, resultado, &resultado);
  resultado=a+produto(a,b-1, h+1);
  printf ("%sa variável local produto.resultado está para ser destruída: %d, %p\n", indent, resultado, &resultado);
  free(indent);
  return resultado;
}
 
void main (void) {
  int a=5, b=10;
  printf ("%d", produto(a,b,0));
}

#endif

#if 1
/* indentar para ficar mais fácil de entender... o produto é feito por indução forte, mas é calculado duas vezes. */
#include <stdlib.h>
#include <string.h>

int produto (int a, int b, int h) {
  char *indent=(char *) malloc (sizeof(char)*(h+1));
  memset (indent, ' ', h);
  indent[h]=0;  // end of string
  if (b<=0) {
	  puts ("produto (a,b): Por favor desprezar resultado - b precisa ser inteiro e positivo.");
	  return 0;
  }
  if (b==1) return a;
  int resultado=0;
  printf ("%sa variável local produto.resultado foi criada: %d, %p\n", indent, resultado, &resultado);
  resultado=produto(a,b/2, h+1)+produto(a,b/2, h+1)+((b%2)?a:0);
  printf ("%sa variável local produto.resultado está para ser destruída: %d, %p\n", indent, resultado, &resultado);
  free(indent);
  return resultado;
}
 
void main (void) {
  int a=5, b=10;
  printf ("%d", produto(a,b,0));
}

#endif

#if 0
/* indentar para ficar mais fácil de entender... o produto é feito por indução forte, é calculado só uma vez. */
#include <stdlib.h>
#include <string.h>

int produto (int a, int b, int h) {
  char *indent=(char *) malloc (sizeof(char)*(h+1));
  memset (indent, ' ', h);
  indent[h]=0;  // end of string
  if (b<=0) {
	  puts ("produto (a,b): Por favor desprezar resultado - b precisa ser inteiro e positivo.");
	  return 0;
  }
  if (b==1) return a;
  int resultado=0;
  printf ("%sa variável local produto.resultado foi criada: %d, %p\n", indent, resultado, &resultado);
  int aux=produto(a,b/2, h+1);
  resultado=aux+aux+((b%2)?a:0);
  printf ("%sa variável local produto.resultado está para ser destruída: %d, %p\n", indent, resultado, &resultado);
  free(indent);
  return resultado;
}
 
void main (void) {
  int a=5, b=10;
  printf ("%d", produto(a,b,0));
}

#endif
