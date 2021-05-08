/*
** EPITECH PROJECT, 2020
** infinit modulo
** File description:
** gets modulo to infinit
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_inf_mod(char *s1, char *s2)
{
    if ((s2[0] == '-' && s2[1] == '0') || s2[0] == '0')
        return (0);
    if (my_longest(s1, s2) == 2)
        return (s1);
    while (my_longest(s1, s2) == 1)
        sub_doop(s1, s2);
    return (s1);
}

char *mod_doop(char *s1, char *s2)
{
    my_revstr(s1);
    my_revstr(s2);
    if (s1[my_strlen(s1) - 1] == '-')
        s1[my_strlen(s1) - 1] = '\0';
    if (s2[my_strlen(s2) - 1] == '-')
        s2[my_strlen(s2) - 1] = '\0';
    my_revstr(s1);
    my_revstr(s2);
    return (my_inf_mod(s1, s2));
}
