SRCS_PS	= 	mandatory/main.c \
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
# FLAGS		= -g -fsanitize=address -Wall -Wextra -Werror -I. 


all:	$(NAME_PS)

$(NAME_PS):		$(OBJS_PS)
			$(CC) -o $(NAME_PS) $(OBJS_PS)

bonus: $(NAME_CH)

$(NAME_CH):		$(OBJS_CH)
			$(CC) $(FLAGS) -o $(NAME_CH) $(OBJS_CH)

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

re:		fclean all bonus

.PHONY: all clean fclean re
