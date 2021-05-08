/*
** EPITECH PROJECT, 2020
** re translates
** File description:
** translates
*/

char *my_retr(char *str, char *av1, char minus)
{
    if (str[0] == '-')
        str[0] = minus;
    for (int i = 0; av1[i] != '\0'; i++)
        for (int j = 0; str[j] != '\0'; j++)
            if (str[j] == i + '0')
                str[j] = av1[i];
    return (str);
}
