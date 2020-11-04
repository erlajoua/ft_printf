NAME    =   libftprintf.a
LIBFT   =   lib
SRC		=   SRCS

SRCS    =	ft_printf.c\
		plus_d.c \
		moins_d.c \
		prn_d.c \
		arg_d.c \
		d_flag.c \
		c_flag.c \
		utils.c \
		common.c \
		p_flag.c \
		s_flag.c \
		u_flag.c \
		x_flag.c \

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
