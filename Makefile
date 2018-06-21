FLAG = -Wall -Werror -Wextra -O3

NAME = libftprintf.a

TMP = temp.a

MAKE = Makefile

LIB = libft/libft.a

INCLUDESDIR = includes

HEADER = includes/ft_printf.h

LIBDIR = libft

SRCDIR = srcs

SRC = srcs/color.c srcs/attrib.c srcs/global_conversion.c srcs/ft_printf.c srcs/initialize.c srcs/integer_signed_conversion.c srcs/integer_unsigned_conversion.c srcs/precision_field.c srcs/scan.c srcs/unicod_conversion.c

BIN = $(SRC:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(LIB) $(MAKE) $(BIN) $(HEADER)
	ar rc $(TMP) $(BIN)
	libtool -static -o libftprintf.a  $(LIBDIR)/libft.a  temp.a
	@/bin/rm -rf $(TMP)

$(LIB):
	@make -C $(LIBDIR)

%.o: %.c $(HEADER)
		@gcc -o $@ -c $< -I $(INCLUDESDIR) $(FLAG)

clean:
		@/bin/rm -rf $(BIN)
		@ make clean -C $(LIBDIR)

fclean: clean
		@/bin/rm -rf $(NAME)
		@ make fclean -C $(LIBDIR)

re: fclean all
