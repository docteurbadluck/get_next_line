#include "get_next_line.h"

void	ft_lstiter(t_list *lst, char * line_buffer, size_t (*f)(char *dst, char c, size_t size))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f( line_buffer, tmp->c, (size_t)BUFFER_SIZE);
		tmp = tmp->next;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
        free(*lst); 
		*lst = temp;
	}
	*lst = NULL;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void            *ptr;
	size_t	        total_size;
    unsigned char   *rm;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
    rm = ptr;
    while (total_size--)
    {
        *rm++ = '\0';
    }
    return ptr;
}

void	ft_lstadd_back(t_list **lst, char c)
{
	t_list	*temp;
    t_list  *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->c = c;
	new_node->next = NULL;

	if (*lst == NULL)
		*lst = new_node;
	else
	{
        temp = *lst;
        while (temp->next != NULL)
            temp = temp->next;
		temp->next = new_node;
	}
}