LIBFT = ./Libft/libft.a

NAME = libftprintf.a

SOURCES = ft_printf.c ft_printf_support.c ft_printf_to_convert.c

SOURCES_bonus = ft_printf_bonus.c ft_printf_support_bonus.c ft_printf_to_convert_bonus.c ft_printf_flags_bonus.c ft_printf_flags_bonus2.c ft_printf_bonus2.c

OBJECTS = $(SOURCES:%.c=%.o)

OBJECTS_bonus = $(SOURCES_bonus:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS)
	$(MAKE) -C ./Libft
	cp Libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar -rcs $(NAME) $(OBJECTS)

all : $(NAME)

bonus: $(NAME)
	$(MAKE) -C ./Libft
	cp Libft/libft.a $(NAME)
	$(CC) $(CFLAGS) -c $(SOURCES_bonus)
	ar -rcs $(NAME) $(OBJECTS_bonus)

clean :
	$(MAKE) clean -C ./Libft 
	rm -rf $(OBJECTS) $(OBJECTS_bonus)

fclean : clean
	$(MAKE) fclean -C ./Libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
