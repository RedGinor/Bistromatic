/*
** EPITECH PROJECT, 2020
** main for bistromatic
** File description:
** bistr main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/my.h"
#include "include/bistromatic.h"

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

int main(int ac, char **av)
{
    unsigned int size;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+-*/%\" exp_len\n");
        return (EXIT_USAGE); }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_atoi(av[3]);
    expr = get_expr(size);
    expr[size] = '\0';
    if (error_handler(av[1], av[2], expr) == 42) {
        my_putstr(SYNTAX_ERROR_MSG);
        return (EXIT_USAGE); }
    my_translate(expr, av[1], av[2]);
    my_putstr(my_retr(eval_expr(expr), av[1], av[2][3]));
    return (EXIT_SUCCESS);
}
