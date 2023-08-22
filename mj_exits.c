#include "shell.h"

/**
 **_stringcopy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_stringcopy(char *dest, char *src, int n)
{
int i, j;
char *y = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
	{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (y);
}

/**
 **_stringconcat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_stringconcat(char *dest, char *src, int n)
{
int i, j;
char *y = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (y);
}

/**
 **_stringchr - locates a character in a string
 *@y: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_stringchr(char *y, char c)
{
do {
if (*y == c)
return (y);
} while (*y++ != '\0');

return (NULL);
}





