/*
** EPITECH PROJECT, 2020
** data_gestion
** File description:
** manages data
*/

int my_strlen(char const *str);

int my_longest(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    if (my_strlen(s1) < my_strlen(s2))
        return (2);
    for (; s1[i] == s2[j] && s1[i] != '\0'; i++, j++);
    if (s1[i] < s2[j])
        return (2);
    return (1);
}
