#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pattern(char [],char []); //fucntion for detecting given pattern in strings
main ()
{
char p[50];
char in_name[800];
    FILE *in_file;
    char word[50];

//---------------
 printf("Enter file name:\n");
    scanf("%s", in_name);

    in_file = fopen(in_name, "r");
   
    printf ("enter the pattern :\n");
	scanf (" %s", p);
   
    if (in_file == NULL)
        printf("Can't open %s for reading.\n", in_name);
    else
    {
    	printf("Your matching strings are :\n");
    while (fscanf(in_file, "%s", word) != EOF)
        {
            pattern(word,p);
        }
        fclose(in_file);
    }
    return 0;
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
      	  	printf("%s\n",s);
          	break; /*to stop further checking in the string
			 if the pattern is detected in it*/
        	}

      		else
        	flag = -1;
	}
}
