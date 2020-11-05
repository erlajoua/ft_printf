NAME    =   libftprintf.a
LIBFT   =   lib
SRC		=   SRCS

SRCS    =	ft_printf.c \
		c_flag.c \
		d_arg.c \
		d_case.c \
		d_flag.c \
		d_tri.c \
		moins_d.c \
		p_case.c \
		p_flag.c \
		plus_d.c \
		s_case.c \
		s_flag.c \
		s_tri.c \
		u_arg.c \
		u_case.c \
		u_flag.c \
		utils.c \
		utils2.c \
		utils3.c \
		u_tri.c \
		x_case.c \
		x_flag.c \
		x_tri.c \
		xx_case.c \
		xx_flag.c \
		xx_tri.c \

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
