#include<stdio.h>
#include<math.h>

int main()
{
	float x = 0.225;
	float dx = 0.001;
	float m = 0.25;
	float dm = 0.001;
	float k = 10.888;
	
	printf("%f", sqrt(pow((dm/m),2)+pow((dx/x),2))*k);
	
}