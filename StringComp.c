#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pattern(char [],char []); //fucntion for detecting given pattern in strings
main ()
{
  char p[50], s[3][100];
  int i;
  printf ("enter the main strings \n");

	//taking strings input
	
	for(i=0;i<=2;i++)
	scanf("%s",&s[i]);
	
	//taking pattern string input
	
	printf ("enter the pattern \n");
	scanf (" %s", p);
	
	//calling pattern function for every string to detect pattern in it
	
	for(i=0;i<3;i++)
	pattern(s[i],p);
}

void pattern(char s[100],char p[10])
{
	int i,j,flag,ls,lp;

	ls = strlen(s); //length of string
	lp = strlen(p); //length of pattern string

	/*if the pattern exists in the given string,
	first charcter of the pattern will be 
	detected at max after ls-lp iterations
	hence the below loop iterates ls-lp times*/

	for (i = 0; i <= ls - lp; i++)
	{
		/*variable that will detect rest of the pattern
		  string after the first charcter is encountered 
		  at ith position*/
		j = 0;

      	while (j < lp && p[j] == s[i + j]) //loop for incrementing j
        j++;
		if (j == lp) /*j becomes equal to lp 
			       if the pattern exists in the string*/
        	{
          	flag = 0;
      	  	printf("string is %s\n",s);
          	break; /*to stop further checking in the string
			 if the pattern is detected in it*/
        	}

      		else
        	flag = -1;
	}
}
