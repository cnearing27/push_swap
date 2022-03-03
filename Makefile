SRCS_PS	= 	mandatory/main.c \
			mandatory/list_functions.c \
			check_args.c \
			mandatory/operations1.c \
			mandatory/operations2.c \
			mandatory/operations3.c \
			mandatory/solve.c \
			mandatory/big_sort.c \
			mandatory/help_funcs.c \
			mandatory/help_funcs2.c \
			mandatory/rotates.c

SRCS_CH	=	bonus/main.c \
			bonus/do_op.c \
			check_args.c \
			bonus/operations1.c \
			bonus/operations2.c \
			bonus/operations3.c \
			bonus/get_solution.c \
			bonus/ft_split.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c

HEADERS		= mandatoy/push_swap.h \
			bonus/checker.h

OBJS_PS		= $(SRCS_PS:.c=.o)
OBJS_CH		= $(SRCS_CH:.c=.o)

NAME_PS		= push_swap
NAME_CH		= checker

CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -I.

$(NAME_PS):		$(OBJS_PS)
			$(CC) -o $(NAME_PS) $(OBJS_PS)

$(NAME_CH):		$(OBJS_CH)
			$(CC) -o $(NAME_CH) $(OBJS_CH)

all:	$(NAME_PS) $(NAME_CH)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean_push_swap:
			$(RM) $(OBJS_PS)

clean_checker:
			$(RM) $(OBJS_CH)

clean:		clean_checker clean_push_swap

fclean_push_swap:	clean_push_swap
			$(RM) push_swap

fclean_checker:		clean_checker
			$(RM) checker

fclean:	fclean_checker fclean_push_swap

re:		fclean all

.PHONY: all clean fclean re
