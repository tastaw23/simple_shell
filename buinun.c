#include "shell.h"

/**
 * _monhist - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _monhist(info_t *info)
{
	print_list(info->histoire);
	return (0);
}

/**
 * desactivationalias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int desactivationalias(info_t *info, char *str)
{
	char *poi, cxw;
	int ret;

	poi = _strchr(str, '=');
	if (!poi)
		return (1);
	cxw = *poi;
	*poi = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*poi = cxw;
	return (ret);
}

/**
 * actifalias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int actifalias(info_t *info, char *str)
{
	char *poi;

	poi = _strchr(str, '=');
	if (!poi)
		return (1);
	if (!*++poi)
		return (desactivationalias(info, str));

	desactivationalias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * affalias - afficher un alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int affalias(list_t *node)
{
	char *poi = NULL, *aqw = NULL;

	if (node)
	{
		poi = _strchr(node->str, '=');
		for (aqw = node->str; aqw <= poi; aqw++)
		_putchar(*aqw);
		_putchar('\'');
		_puts(poi + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * monalias - imite les alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int monalias(info_t *info)
{
	int in = 0;
	char *poi = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			affalias(node);
			node = node->next;
		}
		return (0);
	}
	for (in = 1; info->argv[in]; in++)
	{
		poi = _strchr(info->argv[in], '=');
		if (poi)
			actifalias(info, info->argv[in]);
		else
			affalias(node_starts_with(info->alias, info->argv[in], '='));
	}

	return (0);
}

