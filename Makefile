NAME    =   libftprintf.a
LIBFT   =   lib
SRC		=   SRCS

SRCS    =	ft_printf.c \
		srcs/c_flag.c \
		srcs/d_arg.c \
		srcs/d_case.c \
		srcs/d_flag.c \
		srcs/d_tri.c \
		srcs/moins_d.c \
		srcs/p_case.c \
		srcs/p_flag.c \
		srcs/plus_d.c \
		srcs/s_case.c \
		srcs/s_flag.c \
		srcs/s_tri.c \
		srcs/u_arg.c \
		srcs/u_case.c \
		srcs/u_flag.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/utils3.c \
		srcs/utils4.c \
		srcs/u_tri.c \
		srcs/x_case.c \
		srcs/x_flag.c \
		srcs/x_tri.c \
		srcs/xx_case.c \
		srcs/xx_flag.c \
		srcs/xx_tri.c \
		srcs/per_flag.c \
		srcs/per_case.c \
		srcs/per_tri.c \

OBJS    =   $(SRCS:.c=.o)
HEAD    =  	header/ft_printf.h
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
