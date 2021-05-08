/*
** EPITECH PROJECT, 2020
** my_num
** File description:
** ok if is num
*/

int my_num(char c)
{
    if (c >= '0' && c <= '9')
        return (2);
    if (c == '-' || c == '+')
        return (1);
    return (0);
}
