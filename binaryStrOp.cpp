/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified 
operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better .
[Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is
same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>


char *performOperation(char *str1, char *str2, char *operation)
{

	int i = 0, j = 0,x=0;
	char *output = (char*)calloc(100, sizeof(char));
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0')
		j++;
	//printf("%d,%d",i,j);
	if (i > j)
	{
		x = i - j;
		for (j=j-1; j>=0; j--)
		{
			str2[j + x] = str2[j];
		}
		for (i = 0; i < x; i++)
		{
			str2[i] = '0';
		}
		//printf("\n%s\n", str2);

	}
	if (j>i)
	{

		x = j - i;
		for (i=i-1; i >= 0; i--)
		{
			str1[i + x] = str1[i];
		}
		for (i = 0; i < x; i++)
		{
			str1[i] = '0';
		}
		//printf("\n%s\n", str1);

	}
	i = 0;

	if (operation[1] == 'R')
	{
		while (str1[i] != '\0')
		{
			if (str1[i] == '1' || str2[i] == '1')
			{
				output[i] ='1';
			
			}
			else
			{
				output[i] = '0';
			}
			i++;
		}
		output[i] = '\0';
		printf("%s", output);
	}
	if (operation[2] == 'D')
	{
		while (str1[i] != '\0')
		{
			if (str1[i] == '1' && str2[i] == '1')
			{
				output[i] = '1';

			}
			else
			{
				output[i] = '0';
			}
			i++;
		}
		output[i] = '\0';
		printf("%s", output);

	}

	if (operation[0] == 'N')
	{
		while (str1[i] != '\0')
		{
			if (str1[i] == '1' || str2[i] == '1')
			{
				output[i] = '0';

			}
			else
			{
				output[i] = '1';
			}
			i++;
		}
		output[i] = '\0';
		printf("%s", output);
	}

	if (operation[0] == 'X')
	{
		while (str1[i] != '\0')
		{
			if ((str1[i] == '1' && str2[i] == '1') || (str1[i] == '0' && str2[i] == '0'))
			{
				output[i] = '0';

			}
			else
			{
				output[i] = '1';
			}
			i++;
		}
		output[i] = '\0';
		printf("%s", output);
	}

	return output;
}








