#include "shell.h"

/**
 * _mjenvironment - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _mjenvironment(info_f *info)
{
print_list_str(info->environment);
return (0);
}

/**
 * _getenvironment - gets the value of an environ variable
 * @info: Structure containing potential arguments.
 * @identification: environment var identification
 * Return: the value
 */
char *_getenvironment(info_f *info, const char *identification)
{
list_f *node = info->environment;
char *g;

while (node)
{
g = starts_with(node->str, name);
if (g && *g)
return (g);
node = node->next;
}
return (NULL);
}

/**
 * _mjsetenvironment - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mjsetenvironment(info_f *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenvironment(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _mjunsetenvironment - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mjunsetenvironment(info_f *info)
{
int i;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenvironment(info, info->argv[i]);

return (0);
}

/**
 *mj_populate_environment_list - populates environment linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int mj_populate_environment_list(info_f *info)
{
list_f *node = NULL;
size_f i;

for (i = 0; environment[i]; i++)
add_node_end(&node, environment[i], 0);
info->environment = node;
return (0);
}
