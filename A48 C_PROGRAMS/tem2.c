#include<stdio.h>
#include<string.h>

char start_a_story(char input_string[1014])
{
	char little_story[2048];
	strcpy(little_story,"Once upon a time...");
	strcat(little_story,input_string);
	return little_story;
}
void main()
{
	char *story;
	story=start_a_story("there was a blue rhinoceros named Randolph.");
	printf("%s\n",story);
}