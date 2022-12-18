#include "monty.h"
/**
 * set_globals - initializes global structure
*/
void set_globals(char *path)
{
    globals.head = NULL;
    globals.line = 1;
    globals.file = get_file(path);
    globals.STRUCT_MODE = 0;
}
/**
 * get_file - returns descriptor to file at path
 * @path: path to file
 * Return: pointer to file
 *  exits otherwise
*/
FILE *get_file(char *path)
{
    struct stat sb;
    FILE *file;

    if (stat(path, &sb) == -1)
    {    
        free_all();
        fatal("Error: Can\'t open file %s\n", path);
    }
    file = fopen(path, "r");
    if (file == NULL)
    {    
        free_all();
        fatal("Error: Can\'t open file %s\n", path);
    }
    return (file);
}
/**
 * free_all - frees all dynamic memory in globals_t struct
*/
void free_all(void)
{
    if (globals.head != NULL)
    {    while (globals.head->next != NULL)
        {
            globals.head = globals.head->next;
            free(globals.head->prev);
        }
        free(globals.head);
    }
    if (globals.file != NULL)
        if (fclose(globals.file) != 0)
            perror("close");
}
/**
 * _isdigit - Clean all program mallocs
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
/**
 * _isascii - checks if int fits in the ascii table
 * @i: integer
*/
boolean _isascii(int i)
{
    if (i < 0 || i > 128)
        return (False);
    return (True);
}
/**
 * is_valid_int - checks if a given string is a valid integer
 * @str: string
 *
 * Return: 1 if str is a valid integer. 0 otherwise
 */
int is_int(char *str)
{
	unsigned int i;
	printf("%s\n", str);
	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '-' || i != 0)
				return (0);
		}
	}
	return (1);
}