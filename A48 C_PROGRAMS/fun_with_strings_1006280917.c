#include<stdio.h>
#include<ctype.h>

int lengthfind(char string[])
{
	int z = 0;
	for(int i=0;string[i] != '\0'; i++)
	{	
		z = i+1;
	}
	return z;
}
void pidgin(char string[], int length)
{	
	char tempchar = ' ';
	for(int i=0; i<= length - 1;i = i + 2)
	{
		if (i+1 <= length-1)
		{
			tempchar = string[i];
			string[i] = string[i+1];
			string[i+1] = tempchar;
		}
	}
}
void vowel_caser(char string[], int length)
{
	for(int i = 0; i <= length-1; i++)
	{
		if (string[i] == 'a' || string[i] == 'A' || string[i] == 'e' || string[i] == 'E' || 
		string[i] == 'i' || string[i] == 'I' || string[i] == 'o' || string[i] == 'O' || string[i] == 'u' || string[i] == 'U')
		{
			if(islower(string[i]))
			{
				string[i] = toupper(string[i]);
			}else if (isupper(string[i]))
			{
				string[i] = tolower(string[i]);
			}
		}
	}
}
int main()
{
	int length;
	char my_string[] = "A strIng is jUst a bunch Of chArs sittIng togEthEr in A row!";
	//char my_string[] = "This Is an exAmple";
	printf("%s\n", my_string);
	
	length = lengthfind(my_string);
	
	pidgin(my_string, length);
	printf("%s\n", my_string);
	
	vowel_caser(my_string, length);
	printf("%s\n", my_string);
	
	return 0;
}