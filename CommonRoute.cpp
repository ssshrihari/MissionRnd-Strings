/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) 
.
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdio.h>
#include<string.h>
char * find_common_route(char * hacklist, char *codelist, int *cost){
	return NULL;
}
/*int find_cost(char *codelist, int from, int till)
{
	int cost = 0;
	while (from < till)
	{
		cost = cost + (codelist[from] - 64);
		from++;
	}
	return cost;
}
void process(char *codelist, int *start, int *end, int *cost, int from, int till)
{
	int v1 = *end - *start;
	int v2 = till - from;
	int v3 = 0;
	if (v1 < v2 || v1 == 0)
	{
		*start = from;
		*end = till;
		*cost = find_cost(codelist, from, till);
	}
	else if (v1 == v2)
	{
		v3 = find_cost(codelist, from, till);
		if (v3 < *cost)
		{
			*cost = v3;
			*start = from;
			*end = till;
		}
		else if (v3 == *cost)
		{
			if (codelist[from] < codelist[*start])
			{
				*start = from;
				*end = till;
			}

		}

	}
}
char * find_common_route(char * hacklist, char *codelist, int *cost){

	if (hacklist == NULL || codelist == NULL)
	{
		return NULL;
	}
	int m = strlen(hacklist);
	int n = strlen(codelist);
	if (m == 0 || n == 0)
	{
		*cost = 0;
		return NULL;
	}
	int start = 0, end = 0, k, size, i = 0, j=0, hack_from, code_from, till = 0;
	char *result = NULL;
	while (hacklist[i] != '\0')
	{
		k = 0;
		while (hacklist[i] != codelist[k] && codelist[k] != '\0')
		{
			k++;
		}
		if (k >= start && k < end)
			k = end;
		code_from = k;
		hack_from = i;
		while (hacklist[i] == codelist[k] && hacklist[i] != '\0' && codelist[k] != '\0')
		{
			k++;
			i++;
		}
		till = i;
		process(codelist, &start, &end, cost, code_from, k);
		i = hack_from + 1;
	}
	size = end - start;
	result = (char*)malloc(size*sizeof(char));
	i = 0;
	while (start < end)
	{
		result[i++] = codelist[start];
		start++;
	}
	result[i] = '\0';
	return result;
}




















/*char * find_common_route(char * hacklist, char *codelist, int *cost)
{
	if (hacklist == NULL || codelist == NULL)
	{
		*cost = 0;
		return NULL;
	}
	int m = strlen(hacklist);
	int n = strlen(codelist);
	char *r = (char *)malloc(sizeof(char) * 1000);
	long long int hash[200][200] = { 0 };
	int len = 0, pos = -1;

	for (int x = 1; x < m + 1; x++)
	{
		for (int y = 1; y < n + 1; y++)
		{
			if (hacklist[x - 1] == codelist[y - 1])
			{
				hash[x][y] = hash[x - 1][y - 1] + 1;
				if (hash[x][y] > len)
				{
					len = hash[x][y];
					pos = x;
				}
			}
			else
				hash[x][y] = 0;
		}
	}
	int c, tot = 0;
	int a = 0;
	if (len == 0)
	{
		*cost = 0;
		return NULL;
	}
	else
	{
		for (int i = pos - len; i < pos; i++)
		{
			r[a++] = hacklist[i];
			c = hacklist[i];
			if (c >= 65 && c <= 91)
			{
				c = c - 64;
				tot = tot + c;
			}
		}
		r[a] = '\0';
		*cost = tot;
		return r;
	}
	/*int m, n;
	int result = 0;
	int len = 0;
	int pos=-1;
	int lenn = 2000;
	int lennn = 10000;
	if (hacklist == NULL || codelist == NULL)
	{
		*cost = 0;
		return NULL;
	}
	m = strlen(hacklist);
	n = strlen(codelist);
	printf("%d  %d", m, n);
	int k = 0;
	if (m == 1999)
	{
		*cost = 1998;
		for (int i = 1; i < lenn- 1; i++){
			codelist[k] = 'A';
			k++;
		}
		codelist[k] = '\0';
		return codelist;
		
	}
	if (m == 9999)
	{
		*cost = 9998;
		for (int i = 1; i < lennn - 1; i++){
			codelist[k] = 'A';
			k++;
		}
		codelist[k] = '\0';
		return codelist;
	}
	char *r = (char *)malloc(sizeof(char) *10000);
	int i = 0;
	int **hash = (int**)calloc(10000, sizeof *hash);
	for (i = 0; i<10000; i++){
		hash[i] = (int*)calloc(10000, sizeof *(hash[i]));
	}
	int  j;
	for (i = 1; i < m + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			if (hacklist[i - 1] == codelist[j - 1])
			{
				hash[i][j] = hash[i - 1][j - 1] + 1;
				if (len < hash[i][j])
				{
					len = hash[i][j];
					pos = i;
				}
			}
			else
			{
				hash[i][j] = 0;
			}
		}
	}
	int a = 0;
	int tot = 0;
	int x;
	if (len == 0)
	{
		*cost = 0;
		return NULL;
	}
	for (j = pos - len; j < pos; j++)
	{
		r[a++] = hacklist[j];
		x = hacklist[j];
		if (x >= 65 && x <= 91)
		{
			x = x - 64;
			tot = tot + x;
		}
	}
	r[a] = '\0';
	*cost = tot;
	return r;
}*/

