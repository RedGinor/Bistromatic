/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

#include <stdlib.h>

int my_num(char c);

int my_neg(char *str, int i, int lim);

char *my_getnbr(char *str, int i, int opp)
{
    int count = 0;
    int neg = 0;
    int lim = i;
    char *num;

    while (my_num(str[i]) != 2 && str[i] != '\0')
        i++;
    if (str[i] == '\0' || my_num(str[i]) == 0)
        return (0);
    neg = my_neg(str, i - 1, lim + opp);
    for (count = i; my_num(str[count]) == 2; count++);
    num = malloc(sizeof(char) * (count + 2));
    count = 0;
    if (neg == -1) {
        num[count] = '-';
        count++;
    }
    for (; my_num(str[i]) == 2; i++, count++)
        num[count] = str[i];
    return (num);
}
