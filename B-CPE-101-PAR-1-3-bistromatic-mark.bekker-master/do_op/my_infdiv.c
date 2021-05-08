/*
** EPITECH PROJECT, 2020
** inf div
** File description:
** divides to infinit
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_inf_div(char *s1, char *s2, int neg)
{
    char *res = malloc(sizeof(char) * my_strlen(s1));

    res[0] = '1';
    if ((s2[0] == '-' && s2[1] == '0') || s2[0] == '0')
        return (0);
    if (my_longest(s1, s2) == 2)
        return ("0");
    while (my_longest(s1, s2) == 1) {
        sub_doop(s1, s2);
        add_doop(res, "1");
    }
    sub_doop(res, "1");
    if (neg == -1) {
        my_revstr(res);
        res[my_strlen(res)] = '-';
        my_revstr(res);
    }
    return (res);
}

char *div_doop(char *s1, char *s2)
{
    int neg = 1;

    my_revstr(s1);
    my_revstr(s2);
    if (s1[my_strlen(s1) - 1] == '-') {
        neg *= -1;
        s1[my_strlen(s1) - 1] = '\0';
    }
    if (s2[my_strlen(s2) - 1] == '-') {
        neg *= -1;
        s2[my_strlen(s2) - 1] = '\0';
    }
    my_revstr(s1);
    my_revstr(s2);
    return (my_inf_div(s1, s2, neg));
}
