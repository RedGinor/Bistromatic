/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

int my_atoi(char *s)
{
    int number = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        number *= 10;
        number += s[i] - '0';
    }
    return (number);
}
