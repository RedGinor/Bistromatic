/*
** EPITECH PROJECT, 2020
** int_opperations
** File description:
** does int operations
*/

#include "include/my.h"

char *my_intopp(char *s1, char opp, char *s2)
{
    if ((opp == '+' && ((s1[0] != '-' && s2[0] != '-') ||
                        (s1[0] == '-' && s2[0] == '-'))) ||
        (opp == '-' && ((s1[0] == '-' && s2[0] != '-') ||
                        (s1[0] != '-' && s2[0] == '-'))))
        return (add_doop(s1, s2));
    if (opp == '+' || opp == '-')
        if (s1[0] == '-')
            return (sub_doop(s2, s1));
        else
            return (sub_doop(s1, s2));
    if (opp == '*')
        return (mul_doop(s1, s2));
    if (opp == '/')
        return (div_doop(s1, s2));
    if (opp == '%')
        return (mod_doop(s1, s2));
    return ("0");
}
