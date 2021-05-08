##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	eval_expr.c		\
		do_op/my_infadd.c	\
		do_op/my_infmul.c	\
		do_op/my_infsub.c	\
		do_op/my_infdiv.c	\
		do_op/my_infmod.c	\
		my_infopp.c		\
		my_error_handler.c	\
		main.c

LIB	=	lib/my/my_getnbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_prior.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_itos.c	\
		lib/my/my_atoi.c	\
		lib/my/my_longest.c	\
		lib/my/my_num.c		\
		lib/my/my_neg.c		\
		lib/my/my_base.c	\
		lib/my/my_rebase.c

OBJ	=	$(LIB:.c=.o)

NAME 	=	calc

all: 	lib	$(NAME)

lib:	$(OBJ)
	ar rc lib/my/libmy.a $(OBJ)
	scp lib/my/libmy.a lib/
	mkdir -p include
	scp lib/my/bistromatic.h include/
	scp lib/my/my.h include/

$(NAME):
	gcc $(SRC) -o $(NAME) -Llib/ -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f lib/my/libmy.a
	rm -f lib/libmy.a
	rm -rf include

re: 	fclean all
