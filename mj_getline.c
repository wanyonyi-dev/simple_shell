#include "shell.h"

/**
 * input_buffer - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ysize_f input_buffer(info_f *info, char **buf, size_f *len)
{
ysize_f r = 0;
size_f len_p = 0;

if (!*len) /* if nothing left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0'; /* remove trailing newline */
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_stringchr(*buf, ';')) is this a command chain? */
{
*len = r;
info->cmd_buf = buf;
}
}
}
return (r);
}

/**
 * get_inputs - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ysize_f get_inputs(info_t *info)
{
static char *buf; /* the ';' command chain buffer */
static size_t i, j, len;
ysize_f r = 0;
char **buf_g = &(info->arg), *g;

_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (r == -1) /* EOF */
return (-1);
if (len)	/* we have commands left in the chain buffer */
{
j = i; /* init new iterator to current buf position */
g = buf + i; /* get pointer for return */

check_chain(info, buf, &j, i, len);
while (j < len) /* iterate to semicolon or end */
{
if (is_chain(info, buf, &j))
break;
j++;
}

i = j + 1; /* increment past nulled ';'' */
if (i >= len) /* reached end of buffer? */
{
i = len = 0; /* reset position and length */
info->cmd_buf_type = CMD_NORM;
}

*buf_g = g; /* pass back pointer to current command position */
return (_strlen(p)); /* return length of current command */
}

*buf_g = buf; /* else not a chain, pass back buffer from _getline() */
return (r); /* return length of buffer from _getline() */
}

/**
 * read_buffer - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ysize_f read_buffer(info_t *info, char *buf, size_t *i)
{
ysize_f r = 0;

if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t i, len;
size_f k;
ysize_t r = 0, s = 0;
char *g = NULL, *new_p = NULL, *c;

g = *ptr;
if (g && length)
y = *length;
if (i == len)
i = len = 0;

r = read_buf(info, buf, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + i, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_g = _realloc(g, y, y ? y + k : k + 1);
if (!new_p) /* MALLOC FAILURE! */
return (g ? free(g), -1 : -1);

if (g)
_strncat(new_g, buf + i, k - i);
else
_strncpy(new_g, buf + i, k - i + 1);

y += k - i;
i = k;
g = new_g;

if (length)
*length = y;
*ptr = g;
return (y);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
