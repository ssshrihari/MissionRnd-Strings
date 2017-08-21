/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
#include<stdio.h>
char * get_last_word(char * str)
{
	int i = 0, j = 0,k=0;
	if (str == NULL)
		return NULL;
	char *ans = (char*)malloc(10*sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{	
			
			j = 0;
		}
		else
		{
			ans[j] = str[i];
			j++;
		    k = j;
		}
		i++;
	}	
	ans[k] = '\0';
	return ans;
}