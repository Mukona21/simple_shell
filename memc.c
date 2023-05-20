#include "main.h"

/**
* _memorycpy - copies memory area
* @des: Destination memory area
* @source: Source memory area
* @num: Amount of memory bytes to copy
*
* Return: a pointer to destination
*/
char *_memorycpy(char *des, char *source, unsigned int num)
{
for (unsigned int i = 0; i < num; i++)
des[i] = source[i];

return (des);
}

/**
* _memoryset - fills a memory with constant byte
* @r: pointer to memory area
* @num: number of bytes to fill
* @bytes: constant byte
*
* Return: a pointer to the filled memory area
*/
char *_memoryset(char *r, char bytes, unsigned int num)
{
for (unsigned int i = 0; i < num; i++)
r[i] = bytes;

return (r);
}

/**
* _realloc - reallocates memory block
* @poi: pointer to the previous memory
* @old_s: the old size
* @new_s: the new size
*
* Return: a pointer to the newly allocated memory, or NULL on failure
*/
void *_realloc(void *poi, unsigned int old_s, unsigned int new_s)
{
if (new_s == old_s)
return (poi);

if (new_s == 0 && poi)
{
free(poi);
return (NULL);
}

void *result = malloc(new_s);
if (result == NULL)
return (NULL);

if (poi != NULL)
{
unsigned int copy_s = (old_s < new_s) ? old_s : new_s;
_memcpy(result, poi, copy_s);
}

free(poi);
return (result);
}

/**
* freedata - frees the data
* @data: the data structure
*
* Return: always 0
*/
int freedata(sh_t *data)
{
free(data->line);

data->line = NULL;

free(data->args);

data->args = NULL;

free(data->cmd);

data->cmd = NULL;

free(data->error_message);

data->error_message = NULL;

return (0);
}
