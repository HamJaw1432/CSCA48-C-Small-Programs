#include<stdio.h>

int main()
{
	int i,j;
	for(i=1;i<=100;i=i+1){
		for (j=1;j<=10;j=j+1){
			if (j*j == i) {
				printf("%d = %d * %d\n", i, j,j);
			}
		}
	}
	return 0;
}