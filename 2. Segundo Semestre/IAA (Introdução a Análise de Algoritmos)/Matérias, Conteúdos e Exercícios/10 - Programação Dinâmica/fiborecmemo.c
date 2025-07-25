/*memoized fibo, still recursive*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  // gettimeofday

int callOrder=0;

void indent(int n) {
  for (int i=0;i<n;i++) {
    putchar('\t');
  }
}

void fibonaccir(long int n, int nivel, long int *f, long int *f1) {
	//indent(nivel);
	//printf ("%02d - Entrou no cálculo de F(%ld). \n", ++callOrder, n);
	if(n <= 1) {
		*f=1;
		*f1=1;
		return;
	} else {
		long int g, g1;
		fibonaccir(n-1, nivel+1, &g, &g1);
		*f=g+g1;
		*f1=g;
		//indent(nivel);
		//printf ("%02d - Retornou ao cálculo de F(%ld). \n", ++callOrder, n);
		return;
	}
}

void main (void) {
    long int f, f1;

    struct timeval begin, end;
    gettimeofday(&begin, 0);

    fibonaccir(5,0, &f, &f1);
    printf ("%ld \n", f);

    gettimeofday(&end, 0);

    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long elapsed = seconds*1e6 + microseconds;
    printf("%ld\t ", elapsed);
}
