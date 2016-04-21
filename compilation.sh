rm -rf test_gnl
make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c
gcc -Wall -Wextra -Werror -I libft/includes/ -c main_test.c
gcc -o test_gnl get_next_line.o main_test.o -L libft/ -lft
