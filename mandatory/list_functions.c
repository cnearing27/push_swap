#include "push_swap.h"

void	print_list(t_list *list)
{
	if (list)
	{
		ft_putstr(list -> command);
		if (list -> next)
			write(1, "\n", 1);
		print_list(list -> next);
	}
}

t_list	*ft_lstnew(char	*command)
{
	t_list	*new_el;

	new_el = malloc(sizeof(t_list));
	if (!new_el)
		return (NULL);
	new_el->command = command;
	new_el->next = NULL;
	return (new_el);
}

t_list	*ft_lstlast(t_list	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*el;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		el = ft_lstlast(*(lst));
		el->next = new;
	}
}

