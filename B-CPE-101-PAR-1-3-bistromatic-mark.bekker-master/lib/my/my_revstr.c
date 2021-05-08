/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverts str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char c;

    while (str[i] != '\0')
        i++;
    j = i / 2;
    i--;
    for (int k = 0; k < j; k++) {
        c = str[i];
        str[i] = str[k];
        str[k] = c;
        i--;
    }
    return (str);
}
