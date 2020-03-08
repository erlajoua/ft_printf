NAME    =   libftprintf.a
LIBFT   =   lib
SRC		=   SRCS

SRCS    =	ft_printf.c				\
			$(SRC)/ft_functions.c	\
				$(SRC)/arg_d.c		\
				$(SRC)/d_flag.c		\
				$(SRC)/moins_d.c	\
				$(SRC)/moins_d2.c	\
				$(SRC)/moins_d3.c	\
				$(SRC)/moins_d4.c	\
				$(SRC)/plus_d.c		\
				$(SRC)/prn_d.c		\
				$(SRC)/prn_d_2.c	\
				$(SRC)/prn_d_3.c		

OBJS    =   $(SRCS:.c=.o)
HEAD    =   ft_printf.h
AR      =   ar rc
LIB     =   ranlib
GCC     =   gcc
CFLAGS  =   -Wall -Wextra -Werror
all     :   $(NAME)
.c.o    :
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME) :	$(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)
clean   :
	rm -rf $(OBJS) $(BOBJS)
fclean  : clean
	rm -rf  $(NAME)
re      :   fclean all
.PHONY  :   all clean fclean re
