/*
** EPITECH PROJECT, 2020
** inf sub
** File description:
** substarcts to infinit
*/

#include <stdlib.h>
#include "../include/my.h"

int my_do_sub(char c1, char c2, int mem)
{
    int num1 = 0;
    int num2 = 0;

    if (c1 >= '0' && c1 <= '9')
        num1 = c1 - '0';
    if (c2 >= '0' && c2 <= '9')
        num2 = c2 - '0';
    return (num1 - num2 - mem);
}

char *my_inf_sub(char *s1, char *s2, int neg)
{
    int mem = 0;

    for (int i = 0; i < my_strlen(s1); i++) {
        if (i < my_strlen(s2))
            s1[i] = my_do_sub(s1[i], s2[i], mem);
        else
            s1[i] -= mem + '0';
        mem = 0;
        if (s1[i] < 0) {
            mem = 1;
            s1[i] += 10;
        }
        s1[i] += '0';
    }
    if (s1[my_strlen(s1) - 1] == '0' && my_strlen(s1) > 1)
        s1[my_strlen(s1) - 1] = '\0';
    if (neg == 1)
        s1[my_strlen(s1)] = '-';
    return (my_revstr(s1));
}

char *sub_doop(char *s1, char *s2)
{
    my_revstr(s1);
    my_revstr(s2);
    if (s1[my_strlen(s1) - 1] == '-')
        s1[my_strlen(s1) - 1] = '\0';
    if (s2[my_strlen(s2) - 1] == '-')
        s2[my_strlen(s2) - 1] = '\0';
    my_revstr(s1);
    my_revstr(s2);
    if (my_longest(s1, s2) == 1)
        return (my_inf_sub(my_revstr(s1), my_revstr(s2), 0));
    else
        return (my_inf_sub(my_revstr(s2), my_revstr(s1), 1));
}
