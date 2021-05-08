/*
** EPITECH PROJECT, 2020
** my_prior
** File description:
** priority check
*/

int my_prior(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return (2);
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int my_number(char c)
{
    if (c >= '0' && c <= '9')
        return (2);
    if (c == '-' || c == '+' || c == '*' ||
        c == '/' || c == '%' || c == '(' || c == ')')
        return (1);
    return (0);
}

int my_opend(char *str, int i)
{
    int j = 0;

    for (; my_number(str[i]) == 1; i++);
    for (; str[i] != '\0' && str[i] != ')'; i++)
        if (my_prior(str[i]) >= 1) {
            j++;
            while (my_prior(str[i]) >= 1)
                i++;
        }
    return (j);
}
