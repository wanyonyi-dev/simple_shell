#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @y: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *y)
{
int i = 0;
unsigned long int result = 0;

if (*y == '+')
y++;  /* TODO: why does this make main return 255? */
for (i = 0;  y[i] != '\0'; i++)
{
if (y[i] >= '0' && y[i] <= '9')
{
result *= 10;
result += (y[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @mj: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *mj)
{
_fputs(info->fname);
_fputs(": ");
print_d(info->line_count, STDERR_FILENO);
_fputs(": ");
_fputs(info->argv[0]);
_fputs(": ");
_fputs(estr);
}

/**
 * print_decimal - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _fputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;

return (count);
}

/**
 * convert_no - converter function
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_no(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do	{
*--ptr = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @bufs: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *bufs)
{
int i;

for (i = 0; bufs[i] != '\0'; i++)
if (bufs[i] == '#' && (!i || bufs[i - 1] == ' '))
{
bufs[i] = '\0';
break;
}
}
