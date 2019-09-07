/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

// Sample Input : 
1
jhghdjhsgfjhsvfjdsvfjhsvfjvsdfsd
slfgyedgflsdgfilydsgfipgdsipfgdsfgd

// Sample output: 
35

*******************************************************************************/
#include<stdio.h>

int
main ()
{
  // because given max String input will be 
  // 10000 not more than that 
  char s1[10000];
  char s2[10000];

  // no of test cases
  int n;
  scanf ("%d", &n);

  for (int i = 0; i < n; i++)
    {
      // taking first input as String 
      scanf ("%s\n", &s1);

      // taking second input as String 
      scanf ("%s\n", &s2);

      // verifying Input
      /*
         printf("Testing Input Start\n");
         printf("%s\n",s1);
         printf("%s\n",s2);
         printf("Testing Input End\n");
       */

      // get the length of String first and second 
      int l1 = strlen (s1);
      int l2 = strlen (s2);

      // String will be of lower case Characters 
      // hence max 26 alphabets will be there 
      int FrequencyofCharacterinS1[26];
      int FrequencyofCharacterinS2[26];
      // initialising to zero 
      // because initially array is assigned as 
      // garbage value 
      for (int i = 0; i < 26; i++)
	{
	  FrequencyofCharacterinS1[i] = 0;
	  FrequencyofCharacterinS2[i] = 0;
	}

      // count the frequency of all charcters 
      // in String 1 
      for (int i = 0; i < l1; i++)
	{
	  int index = s1[i] - 'a';
	  FrequencyofCharacterinS1[index]++;
	}

      // count the frequency of all charcters 
      // in String 2 
      for (int i = 0; i < l2; i++)
	{
	  int index = s2[i] - 'a';
	  FrequencyofCharacterinS2[index]++;
	}

      //take the difference of number of charcters 
      // will give number of charcters to be deleted 
      int charctertodelete = 0;
      for (int i = 0; i < 26; i++)
	{
	  charctertodelete +=
	    abs (FrequencyofCharacterinS1[i] - FrequencyofCharacterinS2[i]);
	}

      printf ("%d\n", charctertodelete);

    }

}
