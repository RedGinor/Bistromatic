/*
** EPITECH PROJECT, 2020
** my_neg
** File description:
** gets neg
*/

int my_num(char c);

int my_neg(char *str, int i, int lim)
{
    int neg = 1;

    if (i < 0)
        return (neg);
    while (my_num(str[i]) == 1 && i >= lim) {
        if (str[i] == '-')
            neg *= -1;
        i--;
    }
    return (neg);
}
