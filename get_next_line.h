#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 100 
# define NEW_LINE -2

typedef struct s_list
{
    char    c;
    struct s_list *next;
}   t_list;

typedef struct s_the_line
{
    int     read_bytes;
    char    temp[1];
    char    *buffer;
    t_list  *first;
}   t_the_line;

// get_next_line_utils.c
void    ft_lstadd_back(t_list **lst, char c);
void	ft_lstiter(t_list *lst, char * line_buffer,
size_t (*f)(char *dst, char c, size_t size));
void	ft_lstclear(t_list **lst);
void	*ft_calloc(size_t nmemb, size_t size);

// get_next_line.c
size_t          ft_strlcat(char *dst, const char src, size_t dstsize);
size_t	ft_strnlen(const char *str, size_t maxlen);
size_t	ft_strlcat_append(char *dst, const char src,
size_t dstsize, size_t dst_len);
char *get_next_line(int fd);

#endif