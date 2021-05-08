/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

void my_putchar(char c);

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
