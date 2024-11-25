#include "main.h"
/**
 * _strlen - Renvoie la longueur d'une chaîne de caractè
 * @s: Pointeur vers la chaîne à mesur
 * Cette fonction parcourt la chaîne jusqu'à atteindre le caractère nu
 * pour compter le nombre de caractères
 * Return: La longueur de la chaîn
 */
int _strlen(char *s)
{
int count = 0;
while (s[count] != '\0')
{
count++;
}
return (count);
}