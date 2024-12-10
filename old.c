#include "get_next_line.h"

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
size_t	ft_strnlen(const char *str, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && len < maxlen)
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat_append(char *dst, const char src,
size_t dstsize, size_t dst_len)
{

	if (dst_len >= dstsize)
		return (dstsize + 1);
	if (0 < dstsize - dst_len - 1 && src != '\0')
	{
		dst[dst_len] = src;
	}
	dst[dst_len + 1] = '\0';
	return (dst_len + 1);
}

size_t	ft_strlcat(char *dst, const char src, size_t dstsize)
{
	size_t	dst_len;

	if (dst == NULL)
	{
		return (-1);
	}
	dst_len = ft_strnlen(dst, dstsize);
	return (ft_strlcat_append(dst, src, dstsize, dst_len));
}

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

char *get_next_line(int fd)
{
    t_the_line  my_line;

    my_line.first = NULL;
    my_line.read_bytes = read(fd, my_line.temp, 1);
    if (my_line.read_bytes != 1)
        return NULL; 
    while (my_line.read_bytes == 1)
    {
        ft_lstadd_back(&(my_line.first), my_line.temp[0]);
        my_line.read_bytes = read(fd, my_line.temp, 1);
        if (my_line.temp[0] == '\n')
        {
            ft_lstadd_back(&(my_line.first), my_line.temp[0]);
            my_line.read_bytes = NEW_LINE; 
        } 
    }
    my_line.buffer = ft_calloc(BUFFER_SIZE, 1);
    ft_lstiter(my_line.first, my_line.buffer, &ft_strlcat);
    ft_lstclear(&(my_line.first));
    return (my_line.buffer);

}

int main()
{
   // int fd_home = 0;
    int fd = open("text.txt",O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    while (str)
    {
        free(str);    
        str = get_next_line(fd);
        printf("%s", str);
    }

    free(str);
    return 0;
}