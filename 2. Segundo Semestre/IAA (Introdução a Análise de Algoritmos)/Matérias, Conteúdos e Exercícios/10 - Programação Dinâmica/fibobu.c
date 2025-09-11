/*memoized fibo, bottom up array memo */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  // gettimeofday

int callOrder=0;

void indent(int n) {
  for (int i=0;i<n;i++) {
    putchar('\t');
  }
}

long int *memo;

void fibobu(long int n, int nivel) {
    memo=(long int *) calloc (n+1, sizeof(long int));	
	//indent(nivel);
	//printf ("%02d - Entrou no cálculo de F(%ld). \n", ++callOrder, n);
	memo[1]=1;
	memo[2]=1;
	for (int i=3;i<=n;i++) memo[i]=memo[i-1]+memo[i-2];
	return;
}

void main (void) {
    long int f, f1;

    struct timeval begin, end;
    gettimeofday(&begin, 0);

    int ind=5;
    fibobu(ind,0);
    printf ("%ld \n", memo[ind]);

    gettimeofday(&end, 0);

    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long elapsed = seconds*1e6 + microseconds;
    printf("%ld\t ", elapsed);
}
