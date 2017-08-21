/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of
every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com,
Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.

Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied.
Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), 
underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above,
underscores are acceptable.
e. Email length must be less than or equal to 254 characters.

(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>


int isValidEmail(char *email)
{
	// variable email is in form of "name something@domain.server"
	if (!email)
		return 0;
	int i = 0, j = 0, errorr = 0, name_start = 0, name_end = 0, space_count = 0, at_rate = 0, dot_before = 0, dot_after = 0, email_start = 0, email_end = 0;
	//space before name checker
	while (email[i] == ' ')
	{
		i++;
	}
	//name seprator
	name_start = i;
	while (email[i] != ' ')
	{
		i++;
		if (email[i] == '\0')
			return 0;
	}
	name_end = i;
	//space cheker
		while (email[i] == ' ')
		{
			i++;
		}
	
	email_start = i;
	//email id verification
	//starting character
	//printf("%d", i);
	if (email[i] == '\0' || email[i] == '-' || email[i] == '_' || email[i] == '.' || email[i] == '0' || email[i] == '1' || email[i] == '2' || email[i] == '3' || email[i] == '4' || email[i] == '5' || email[i] == '6' || email[i] == '7' || email[i] == '8' || email[i] == '9')
		return 0;
	while (email[i] != '\0')
	{
		//spaces in between email
		if (email[i] == ' ')
		{
			int z = i;
			while (email[z] != '\0')
			{
				if (email[z] != ' ')
					return 0;
				z++;
			}

		}
		printf("\n %d", i);
		//only alphanumeric characters
		if ((int(email[i]) < 65 || int(email[i]) > 91) && (int(email[i]) < 97 || int(email[i]) > 123) && (int(email[i]) != 32) && (int(email[i]) != 46) && (int(email[i]) != 64) && (int(email[i]) != 45) && (int(email[i]) != 95))
			return 0;
		
		if (int(email[i]) == 64)
			at_rate++;
		if (int(email[i]) == 46)
		{
			if (at_rate == 0)
				dot_before++;
			else
				dot_after++;
		}
		i++;
	}
	email_end = i;
	if (i > 254)
		return 0;
	if (at_rate == 0|| at_rate>1)
		return 0;
	
	if (email[email_end - 1] == '.')
		return 0;
	int count = 0;
	int k = 0, name = 0;
	for (i = name_start, j = email_start; i < name_end, j < email_end; j++)
	{
		if ((email[i] == email[j]) || (int(email[i]) - 32) == int(email[j]) || (int(email[i]) + 32) == int(email[j]) || (int(email[j])-32) == int(email[i]) || int(email[j]+32) == int(email[i]))
		{

			count++;
			i++;
			if (count == name_end)
			{
				if (email[j + 1] == '@'||email[j-count]==' ')
				return 2;
			}
		}
		else
		{
			j = j - i;
			i = name_start;
			count = 0;
		}
	}
	
	if (count!=name_end)
	  return 1;

	  return 0;
}