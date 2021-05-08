/*
** EPITECH PROJECT, 2020
** eval expr
** File description:
** make prior
*/

#include <stdlib.h>
#include "include/my.h"

int my_move(char *str, int num)
{
    for (; my_number(str[num]) != 2 && str[num] != '\0'; num++);
    for (; my_number(str[num]) != 1 && str[num] != '\0'; num++);
    return (num);
}

void my_strmod(char *str, int min, int max, char *res)
{
    int mem = min;

    if (str[min] != '(' && str[max - 1] != ')')
        mem = my_move(str, min);
    if (my_prior(str[min]) >= 1)
        min++;
    if (my_prior(str[mem]) == 2 && my_prior(str[min - 1]) == 1) {
        if (res[min] != '-')
            str[min - 1] = '+';
        else
            min--;
    }
    for (int k = 0; res[k] != '\0'; k++, min++)
        str[min] = res[k];
    for (; min != max; min++)
        str[min] = '_';
}

char *my_opgest(char *str, int i, int lim)
{
    char *s1 = my_getnbr(str, i, 0);
    int max = 0;
    int min = i;

    if (my_opend(str, lim) == 0)
        return (my_getnbr(str, lim, 0));
    i = my_move(str, i);
    if (my_opend(str, lim) == 1)
        return (my_intopp(s1, str[i], my_getnbr(str, i, 1)));
    max = my_move(str, i);
    if (my_prior(str[max]) == 2 && my_prior(str[i]) != 2)
        return (my_opgest(str, i, lim));
    my_strmod(str, min, max, my_intopp(s1, str[i], my_getnbr(str, i, 1)));
    return (my_opgest(str, lim, lim));
}

char *eval_expr(char *str)
{
    int i = 0;
    int j = 0;
    int mem = 0;

    for (; str[j] != ')' && str[j] != '\0'; j++)
        if (str[j] == '(')
            i = j;
    if (str[j] == ')') {
        my_strmod(str, i, j + 1, my_opgest(str, i + 1, i + 1));
        return (eval_expr(str));
    }
    return (my_opgest(str, 0, 0));
}
