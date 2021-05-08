/*
** EPITECH PROJECT, 2020
** itoc
** File description:
** itoc
*/

#include <stdlib.h>

#define ITOC(x) ((x) + '0')

char *my_revstr(char *str);

char *my_itos(int num)
{
    int i = 0;
    int mem = num;
    int neg = 1;
    char *str;

    if (num < 0)
        neg = -1;
    num *= neg;
    for (; mem * neg > 0; i++, mem /= 10);
    str = malloc(sizeof(char) * (i + 2));
    if (num == 0)
        str[0] = '0';
    for (i = 0; num > 0; i++, num /= 10)
        str[i] = ITOC(num % 10);
    if (neg == -1)
        str[i] = '-';
    return (my_revstr(str));
}
