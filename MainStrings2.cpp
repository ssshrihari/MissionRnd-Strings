/*

Use Strings2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Strings-2 Lesson:

->Using malloc to create new strings
->New ways of Handling Strings

Solve CommonRoute , Concat4Strings keeping complexity in Mind , BruteForce solutions take
long time to pass ,and will eventually fail when we run on our side with Timeouts .

Make Sure The Each Individual Test cases for Large inputs dosent take more than
2Seconds. (ie Real20_CommonRoute TestCase in CommonRouteSpec)
*/

#include "FunctionHeadersStrings2.h"
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
int main(){

	//int actualAns = isValidEmail("surya    suriii@sun.com      ");
	//Test Consonants_Vowels
	char s1[100] = "a3e2";
	char s2[100] = "4ekl";
	int expectedAns = 1;
	int actualAns = isSTRMatched(s1, s2);
	//Test getFrequencyofWord
	/*int i = 0;
	char str1[100] = "1111";
	char str2[100] = "0101";
	char eans[100] = "0101";
	char * ans = performOperation(str1, str2, "AND");
	printf("\n");
	while (ans[i] != '\0')
	{
		printf("%c", *(ans + i));
		i++;
	}*/
	//Test getSubstring
	//char s1[100] = "10a10";
	//char s2[100] = "9ee9a";
	//int expectedAns = 1;
	//int actualAns = isSTRMatched(s1, s2);
	//Test getLastWord
	//char sentences[][100] = { "d ab   " };
	//char sentences[][100] = { "abc is a word", "he he", "   ", "d ab   ", "  x", "asd324", "", "a" };
	//char ans[][100] = { "word", "he", "", "ab", "x", "asd324", "", "a" };
	//int sc = 8;
	//int si = 0;
	//for (si = 0; si < sc; si++)
	//{
		//get_last_word(sentences[0]);
//	}
	//Test others
	getchar();
	return 0;
}