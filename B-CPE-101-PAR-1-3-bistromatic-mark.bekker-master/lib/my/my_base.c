/*
** EPITECH PROJECT, 2020
** checks base
** File description:
** checks base
*/

void my_translate(char *str, char *av1, char *av2)
{
    char *opps = "()+-*/%";

    for (int i = 0; av1[i] != '\0'; i++)
        for (int j = 0; str[j] != '\0'; j++)
            if (str[j] == av1[i])
                str[j] = i + '0';
    for (int i = 0; av2[i] != '\0'; i++)
        for (int j = 0; str[j] != '\0'; j++)
            if (str[j] == av2[i])
                str[j] = opps[i];
}
