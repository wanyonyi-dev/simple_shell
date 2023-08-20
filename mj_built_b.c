#include "shell.h"

/**
 * _mjhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mjhistory(info_f *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_f *info, char *str)
{
char *g, d;
int ret;

g = _strchr(str, '=');
if (!g)
return (1);
d = *g;
*g = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*g = d;
return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_f *info, char *str)
{
char *g;

g = _strchr(str, '=');
if (!g)
return (1);
if (!*++g)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_f *node)
{
char *g = NULL, *a = NULL;

if (node)
{
g = _strchr(node->str, '=');
for (a = node->str; a <= g; a++)
_putchar(*a);
_putchar('\'');
_puts(g + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * _mjalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */

int _mjalias(info_f *info)
{
int i = 0;
char *g = NULL;
list_f *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (g)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}
return (0);
}
