/*
** EPITECH PROJECT, 2020
** do_op
** File description:
** does operation
*/

#include "../include/my.h"

int my_do_add(char c1, char c2, int mem)
{
    int num1 = 0;
    int num2 = 0;

    if (c1 >= '0' && c1 <= '9')
        num1 = c1 - '0';
    if (c2 >= '0' && c2 <= '9')
        num2 = c2 - '0';
    return (num1 + num2 + mem);
}

char *my_inf_add(char *s1, char *s2, int neg)
{
    int mem = 0;

    for (int i = 0; i < my_strlen(s1); i++) {
        if (i < my_strlen(s2))
            s1[i] = my_do_add(s1[i], s2[i], mem);
        else
            s1[i] += mem - '0';
        mem = s1[i] / 10;
        s1[i] -= mem * 10 - '0';
    }
    if (mem != 0)
        s1[my_strlen(s1)] = '1';
    if (neg == 1)
        s1[my_strlen(s1) + mem] = '-';
    return (my_revstr(s1));
}

char *add_doop(char *s1, char *s2)
{
    int neg = 0;

    my_revstr(s1);
    my_revstr(s2);
    if (s1[my_strlen(s1) - 1] == '-')
        neg = 1;
    if (s1[my_strlen(s1) - 1] == '-')
        s1[my_strlen(s1) - 1] = '\0';
    if (s2[my_strlen(s2) - 1] == '-')
        s2[my_strlen(s2) - 1] = '\0';
    my_revstr(s1);
    my_revstr(s2);
    if (my_longest(s1, s2) == 1)
        return (my_inf_add(my_revstr(s1), my_revstr(s2), neg));
    else
        return (my_inf_add(my_revstr(s2), my_revstr(s1), neg));
}
