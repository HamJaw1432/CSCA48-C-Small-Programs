#include<stdio.h>
#include<math.h>

int main()
{
	double pi;
	int i;
	pi = 3.14159265;
	printf("%1.0f\n", (ceil(pi*10))/10);
	printf("%.1f\n", (ceil(pi*100))/100);
	printf("%.2f\n", (ceil(pi*1000))/1000);
	printf("%.3f\n", (ceil(pi*10000))/10000);
	printf("%.4f\n", (ceil(pi*100000))/100000);
	printf("%.5f\n", (ceil(pi*1000000))/1000000);
	printf("%.6f\n", (ceil(pi*10000000))/10000000);
	printf("%.7f\n", (ceil(pi*100000000))/100000000);
	printf("%.8f\n", pi);
	
	return 0;
}