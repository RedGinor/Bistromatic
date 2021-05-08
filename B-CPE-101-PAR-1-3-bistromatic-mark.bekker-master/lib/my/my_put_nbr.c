/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Write a function that displays the number given as a parameter.
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int r = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * - 1;
    }
    r = nb % 10;
    nb = nb / 10;
    if (nb > 0)
        my_put_nbr(nb);
    my_putchar(r + '0');
}
