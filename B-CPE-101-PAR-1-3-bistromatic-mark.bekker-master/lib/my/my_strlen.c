/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** counts and returns the number of characters given as parrameter
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
