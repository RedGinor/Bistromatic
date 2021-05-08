/*
** EPITECH PROJECT, 2020
** error handler
** File description:
** handles errors
*/

#include "include/my.h"

int error_mult(char *av1, char *av2)
{
    for (int i = 0; av1[i] != '\0'; i++)
        for (int j = 0; av2[j] != '\0'; j++)
            if (av1[i] == av2[j])
                return (42);
    return (0);
}

int error_base(char *av)
{
    for (int i = 0; av[i] != '\0'; i++)
        for (int j = 0; av[j] != '\0'; j++)
            if (av[i] == av[j] && i != j)
                return (42);
    return (0);
}

int error_expr(char *str)
{
    int prt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((my_prior(str[i]) == 2 && my_prior(str[i + 1]) == 2) ||
            (my_prior(str[i]) == 1 && my_prior(str[i + 1]) == 2))
            return (42);
        if ((str[i] == '(' && my_number(str[i - 1]) == 2 && i > 0) ||
            (str[i] == ')' && my_number(str[i + 1]) == 2))
            return (42);
        if (str[i] == '(')
            prt++;
        if (str[i] == ')')
            prt--;
        if (prt < 0)
            return (42);
    }
    if (prt != 0)
        return (42);
    return (0);
}

int error_handler(char *av1, char *av2, char *str)
{
    int score = 0;
    int match = 0;

    for (int i = 0; str[i] != '\0'; i++)
        for (int j = 0; av1[j] != '\0'; j++)
            if (str[i] == av1[j])
                score++;
    for (int i = 0; str[i] != '\0'; i++)
        for (int j = 0; av2[j] != '\0'; j++)
            if (str[i] == av2[j])
                score++;
    for (int i = 0; av1[i] != '\0'; i++)
        if (av1[i] == str[my_strlen(str) - 1] ||
            str[my_strlen(str) - 1] == ')')
            match++;
    if (error_expr(str) == 42 || error_mult(av1, av2) == 42 ||
        error_base(av1) == 42 || error_base(av2) == 42 ||
        my_strlen(str) != score || match == 0)
        return (42);
    return (0);
}
