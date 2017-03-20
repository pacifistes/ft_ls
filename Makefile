NAME = ft_ls

INCLUDES = includes/
LIBFT = ./libft/

SRCS = 	ft_ls.c register_file.c sort_by_alphabet.c sort_by_mtime.c reverse_list.c \
sort.c begin_by_point.c register_option.c ft_error.c init_option.c \
list_join.c size_list.c print_no_directory.c option_l.c print_total_bloc.c \
no_sort.c option_valid.c print_maj_f.c print_inode.c init_l_struct.c \
check_extend_and_acl.c ls_print_file.c sort_by_birthtime.c sort_by_atime.c \
sort_by_size.c sort_by_ctime.c register_directory.c print_time.c color_file.c \
print_type_and_acces.c print_major_minor.c print_subfolder.c print_owner.c

WFLAGS = -Wall -Werror -Wextra

CC = gcc -g

OBJ = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -c $(WFLAGS) -I $(LIBFT) -I $(INCLUDES) $< -o $@

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) -I $(INCLUDES) -I $(LIBFT) -L $(LIBFT) -lft

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
