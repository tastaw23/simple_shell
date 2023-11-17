#include "shell.h"

/**
 * monenvi - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int monenvi(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * recupvvv - recuperer la  value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *recupvvv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *poi;

	while (node)
	{
		poi = starts_par(node->str, name);
		if (poi && *poi)
			return (poi);
		node = node->next;
	}
	return (NULL);
}

/**
 * monive - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int monive(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect nombre des arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * monument - supprime unn environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int monument(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("peu arguements.\n");
		return (1);
	}
	for (in = 1; in <= info->argc; in++)
		monument(info, info->argv[in]);

	return (0);
}

/**
 * popenvlis - populer env chaine liste
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int popenvlis(info_t *info)
{
	list_t *node = NULL;
	size_t in;

	for (in = 0; environ[in]; in++)
		add_node_end(&node, env[in], 0);
	info->env = node;
	return (0);
}

