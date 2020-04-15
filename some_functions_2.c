#include "holberton.h"
/**
 * _strcat - function that concatenates two strings.
 * @dest: character.
 * @src: character.
 * Return: the value of dest.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{

	}
	for (j = 0; src[j] != '\0'; j++, i++)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - function that copies the string scr to dest
 * @dest: character
 * @src: character
 * Return: empty
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	for (; src[count] != '\0'; count++)
	{
		dest[count] = src[count];
	}
	dest[count] = '\0';
	return (dest);
}
/**
 * _strconcat - function that conatenates two strings
 * @s1: string 1.
 * @s2: string 2.
 * Return: NULL or the value of dest.
 */
char *_strconcat(char *s1, char *s2)
{
	char *strcon;
	int i, j, count;

	j = 0;
	count = _strlen(s1) + _strlen(s2) + 2;
	/*+2 to add space for / in between command and path and \0 at the end*/
	strcon = malloc(sizeof(char) * count);
	if (strcon == NULL)
		return (NULL);
	for (i = 0; s1 && s1[i] != '\0'; i++)
	{
		strcon[j] = s1[i];
		j++;
	}
	if (j != 0)
	{
		strcon[j] = '/';
		j++;
	}
	for (i = 0; s2 && s2[i] != '\0'; i++)
	{
		strcon[j] = s2[i];
		j++;
	}
	strcon[j] = '\0';
	/*have to free args[0], since we change what args[0] points to*/
	free(s2);
	return (strcon);
}
