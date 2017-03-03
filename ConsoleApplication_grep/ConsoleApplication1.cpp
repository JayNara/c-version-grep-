// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAXLINE 1000

int getline(char line[],int max);
int strindex(char source[],char searchfor[]);

char pattern[MAXLINE];
/*find all line matching pattern */
int main(char argc,char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	memset(pattern,'\0',MAXLINE);
	getline(pattern,MAXLINE);
	while (getline(line,MAXLINE)>0)
	{
		if (strindex(line, pattern) >= 0) 
		{
			printf("%s",line);
			found++;
		}
	}
    return found;
}

/*getline: get line into s,return length*/
int getline(char s[], int lim)
{
	int c, i=0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	if (i == 1)
	{
		i--;
		return i;
	}
	return i;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] == s[j] && t[k] != '\0'; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}