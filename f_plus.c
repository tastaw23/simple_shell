#include "shell.h"

/**
 * verifierModeInteractif - returns true if shell is interactive mode
 * @datainfo: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int verifierModeInteractif(info_t *datainfo)
{
	return (isatty(STDIN_FILENO) && datainfo->descFichierLecture <= 2);
}

/**
 * CaractereSeparateur - checks if character is a delimeter
 * @caractere: the char to check
 * @chaineSeparateurs: the delimeter string
 * Return: 1 if true, 0 if false
 */
int CaractereSeparateur(char caractere, char *chaineSeparateurs)
{
	while (*chaineSeparateurs)
		if (*chaineSeparateurs++ == c)
			return (1);
	return (0);
}

/**
 * CaractereAlphabetique - checks for alphabetic character
 * @valeurCaractere: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int CaractereAlphabetique(int valeurCaractere)
{
	if ((valeurCaractere >= 'a' && valeurCaractere <= 'z') || (valeurCaractere >= 'A' && valeurCaractere <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * convertirehaineenentier - converts a string to an integer
 * @chaine: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int convertirehaineenentier(char *chaine)
{
	int in, sign = 1, flag = 0, resultat;
	unsigned int sortie = 0;

	for (in = 0; chaine[in] != '\0' && flag != 2; in++)
	{
		if (chaine[in] == '-')
			sign *= -1;

		if (chaine[in] >= '0' && s[in] <= '9')
		{
			flag = 1;
			sortie *= 10;
			sortie += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		resultat = -sortie;
	else
		resultat = sortie;

	return (resultat);
}

