#include<stdio.h>

void reverse(char *s)
{
	char temp;
	int len = 0;
	while (*(s+len) != '\0')
	{
		len ++;
	}
	len = len -1;
	for (int i = 0; i < len/2; i++)
	{
		temp = *(s+i);
		*(s+i) = *(s+len-i);
		*(s+len-i) = temp;
	}
}


int main()
{
	char str[] = "Hello this is a str";
	char str2[] = "temp";
		
	reverse(&str[0]);
	
	printf("%s, %s", str, str2);
	
	return 0;
}