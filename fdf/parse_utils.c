#include "fdf.h"

t_Dlist	*dlist_new(void)
{
	t_Dlist		*p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new == NULL)
	{
		ft_putstr_fd("Allocation failed", 1);
		exit(EXIT_FAILURE);
	}
	p_new->width = 0;
    p_new->height = 0;
	p_new->p_head = NULL;
    p_new->p_tail = NULL;
	return (p_new);
}

int	dlist_append(t_Dlist *p_list, char *nbr, int i)
{
	struct s_node	*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new == NULL)
		{
			ft_putstr_fd("Allocation failed", 1);
			return (-1);
		}
		p_new->x = i;
		p_new->y = p_list->height;
        p_new->z = ft_atoi(nbr);
        p_new->p_next = NULL;
        if (p_list->p_head == NULL)
        {
            p_list->p_head = p_new;
            p_list->p_tail = p_new;
        }
        else
        {
            p_list->p_tail->p_next = p_new;
            p_list->p_tail = p_new;
        }
	}
	return (1);
}

void	dlist_delete(t_Dlist *p_list)
{
	struct s_node	*p_temp;
	struct s_node	*p_del;
	int 			lenght;
	int 			i;

	i = -1;
	lenght = p_list->lenght;
	if (p_list != NULL)
	{
		p_temp = p_list->p_head;
		while (++i < lenght)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del);
		}
		free(p_list);
		p_list = NULL;
	}
}

void	ft_free(t_Dlist *p_list)
{
	dlist_delete(p_list);
}