#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_f *info)
{
if (!info->environ || info->environment_changed)
{
info->environ = list_to_strings(info->environment);
info->env_changed = 0;
}

return (info->environ);
}

/**
 * _mjunsetenvironment - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _mjunsetenvironment(info_t *info, char *var)
{
list_f *node = info->environment;
size_f i = 0;
char *g;

if (!node || !var)
return (0);

while (node)
{
g = starts_with(node->str, var);
if (g && *g == '=')
{
info->environment _changed = delete_node_at_index(&(info->environment), i);
i = 0;
node = info->environment;
continue;
}
node = node->next;
i++;
	}
return (info->environment _changed);
}

/**
 * _mjsetenvironment - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _mjsetenvironment(info_f *info, char *var, char *value)
{
char *buf = NULL;
list_f *node;
char *g;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->environment;
while (node)
{
g = starts_with(node->str, var);
if (g && *g == '=')
{
free(node->str);
node->str = buf;
info->environment _changed = 1;
return (0);
		}
node = node->next;
}
add_node_end(&(info->environment), buf, 0);
free(buf);
info->environment_changed = 1;
return (0);
}
