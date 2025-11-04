CC = cc
CFLAGS = -I../ -g

OBJS = ft_printf.o \
			 ft_parse.o \
			 ft_str_to_str.o \
			 ft_int.o \
			 ft_int_to_str.o \
			 ft_int_to_str_hex.o \
			 ft_int_flags.o \

BONUS_OBJS = ft_printf_bonus.o \
						 ft_parse.o \
						 ft_str_to_str.o \
						 ft_int.o \
						 ft_int_to_str.o \
						 ft_int_to_str_hex.o \
						 ft_int_flags.o \

all:
	make -C .. bonus
	cp ../libftprintf.a .
	$(CC) $(CFLAGS) main.c $(NAME) -L.. -lftprintf -o test 

test: all
	./test

