/*iterative fibo, bottom up 2 term memo */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  // gettimeofday

int callOrder=0;

void indent(int n) {
  for (int i=0;i<n;i++) {
    putchar('\t');
  }
}

long int memo1, memo2;

long int fiboi(long int n, int nivel) {
	//indent(nivel);
	//printf ("%02d - Entrou no cálculo de F(%ld). \n", ++callOrder, n);
	long int f;
	memo1=1;
	memo2=1;
	for (int i=3;i<=n;i++) {
		f=memo1+memo2;
		memo2=memo1;
		memo1=f;
	}
	return f;
}

void main (void) {
    long int f, f1;

    struct timeval begin, end;
    gettimeofday(&begin, 0);

    printf ("%ld \n", fiboi(5, 0));

    gettimeofday(&end, 0);

    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long elapsed = seconds*1e6 + microseconds;
    printf("%ld\t ", elapsed);
}
