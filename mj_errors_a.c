#include "shell.h"

/**
 *_fputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _fputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_fputchar(str[i]);
i++;
}
}

/**
 * _fputchar - writes the character c to stderror
 * @m: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _fputchar(char m)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (m == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (m != BUF_FLUSH)
buf[i++] = m;
return (1);
}

/**
 * _putfd - writes the character c to given file description
 * @m: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char m, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (m == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (m != BUF_FLUSH)
buf[i++] = m;
return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}
