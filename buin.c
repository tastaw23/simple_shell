#include "shell.h"

/**
 * masortie - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int masortie(info_t *info)
{
	int sortiecheck;

	if (info->argv[1]) /* S'il y a un argument de sorti */
	{
		sortiecheck = _erratoi(info->argv[1]);
		if (sortiecheck == -1)
		{
			info->status = 2;
			print_error(info, "nombre illegal: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * moncdp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int moncdp(info_t *info)
{
	char *sss, *reper, buffer[1024];
	int chreper_ret;

	s = getcwd(buffer, 1024);
	if (!sss)
		_puts("TODO: >>erreue ici<<\n");
	if (!info->argv[1])
	{
		reper = _getenv(info, "HOME=");
		if (!reper)
			chreper_ret = /* TODO: etre quoi? */
				chreper((reper = _getenv(info, "PWD=")) ? reper : "/");
		else
			chreper_ret = chreper(reper);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chreper_ret = /* TODO: etre quoi? */
			chreper((reper = _getenv(info, "OLDPWD=")) ? reper : "/");
	}
	else
		chreper_ret = chreper(info->argv[1]);
	if (chreper_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _aide - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _aide(info_t *info)
{
	char **tabarg;

	tabarg = info->argv;
	_puts("appeler aide. Fct non implemented \n");
	if (0)
		_puts(*tabarg); /* sol temporaire */
	return (0);
}

