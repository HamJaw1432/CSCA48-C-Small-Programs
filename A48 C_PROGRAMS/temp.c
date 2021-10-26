#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAXSTRINGLEN 1024

/* void swap(char *first, char *second)

{
	int lenFirst = 0;
	while (*(first + lenFirst) != '\0')
	{
		lenFirst ++;
	}
	int lenSecond = 0;
	while (*(second + lenSecond) != '\0')
	{
		lenSecond ++;
	}
	int len = fmax(lenFirst,lenSecond);
	printf("%d %d %d\n", len, lenFirst, lenSecond);
	char temp;
	for (int i=0; i<len; i++)
	{
		temp = *(first + i);
		*(first + i) = *(second + i);
		*(second + i) = temp;
	}
}

char occur(char str)
{
	int len = 0;
	while (*(str + len) != '\0')
	{
		len ++;
	}
	
	char maxStr = '';
	int maxNum = 0;
	
	for (int i = 0; i < len; i++)
	{
		
	}
}

int main()
{
	char first[1024] = "short";
	char second[1024] = "some long string";
	
	swap(&first[0], &second[0]);
	
	printf("first is now = %s\nsecond is now = %s\n", first, second);
	
	return 0;
} */
/* typedef struct res_info
{
	char name[MAXSTRINGLEN];
	float rate;	
	
}resturant;

void add_input(resturant *input_loc, char input_name[MAXSTRINGLEN], float input_rate) // why does not having [MAXSTRINGLEN] break it
{
	strcpy(input_loc -> name, input_name);
	input_loc -> rate = input_rate;
	
}


int  main()
{
	resturant res_list_info[100];
		
	char con ='Y';
	char input_res_name[MAXSTRINGLEN];
	float input_res_rate;
	int i = 0;
	
	while(con == 'Y' && i < 100){
	
		printf("Input the resturant name:\n");
		fgets(input_res_name, MAXSTRINGLEN, stdin);
		
		printf("Input resturant rating:\n");
		scanf("%f", &input_res_rate);
		getchar();
		
		printf("Do you want to continue: (Y/N)\n");
		scanf("%c", &con);
		getchar();
		
		
		
		add_input(&res_list_info[i],input_res_name,input_res_rate);
		
		
		i++;
	
	}
	
	for(int j = 0; j < i; j++)
	{
		printf("\n%s%f\n", res_list_info[j].name, res_list_info[j].rate);
	}
	
} */




