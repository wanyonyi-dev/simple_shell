#include "shell.h"

/**
 * _mjexit - exits the simple  shell
 * @info: Structure containing potential arguments.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */

int _mjexit(info_t *info)
{
int exitchecker;
if (info->argv[1])
{
exitchecker = _erratoi(info->argv[1]);
if (exitchecker == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_fputs(info->argv[1]);
_fputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * _mjcd - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */

int _mjcd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;

y = getcwd(buffer, 1024);
if (!y)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "HOME=");
if (!dir)
chdir_ret =
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(y);
_putchar('\n');
return (1);
		}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_fputs(info->argv[1]), _fputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _mjhlp - changes the current directory of the process
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _mjhlp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array);
return (0);
}
