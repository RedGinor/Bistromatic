/*
** EPITECH PROJECT, 2020
** inf mul
** File description:
** multiplies infit numbers
*/

#include <stdlib.h>
#include "../include/my.h"

void *multop(char *s1, char *s2, int neg, char *res)
{
    int tmp = 0;
    int j = 0;
    int l = my_strlen(s1) + my_strlen(s2);

    for (int i = 0; i < l - 1; i++)
        res[i] = '0';
    for (int i = 0; s1[i] != '\0' && s1[i] != '-'; i++) {
        tmp = 0;
        for (j = 0; s2[j] != '\0' && s2[j] != '-'; j++) {
            res[i + j] += (s1[i] - '0') * (s2[j] - '0') + tmp - '0';
            tmp = res[i + j] / 10;
            res[i + j] -= tmp * 10 - '0';
        }
        if (tmp != 0)
            res[i + j] = tmp + '0';
    }
    for (; res[l - 1] != '\0'; l++);
    if (neg == -1 && res[l] == '\0')
        res[l - 1] = '-';
    my_revstr(res);
}

char *mul_doop(char *s1, char *s2)
{
    int neg = 1;
    char *res = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));

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
    multop(s1, s2, neg, res);
    return (res);
}
