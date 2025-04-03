/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischeini <ischeini@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:37:54 by sscheini          #+#    #+#             */
/*   Updated: 2025/03/17 17:09:21 by ischeini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <limits.h>
# include <unistd.h>
# include "ft_printf_bonus.h"
# include "get_next_line_bonus.h"

/* Ft_strlcpy copies 'size' bytes form 'src' into 'dst'. 		  			*/
/* - If 'size' >= src_len + 1, it copies all of 'src' into 'dst'. 			*/
/* - Else, it truncates the copy after size - 1 bytes.			  			*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* Ft_strlcat concatenates 'size' bytes from 'src' at the end of 'dst'. 	*/
/* - If 'size' <= dst_len, it doesn't concatenate.					 		*/
/* - If 'size' >= dst_len + src_len + 1, it concatenates all of 'src'.		*/
/* - Else, it truncates the concatenation after 'size' - 1 bytes.	  		*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* Ft_strlen returns the count of characters on 's', not including the '\0'.*/
size_t	ft_strlen(const char *s);

/* Ft_memmove moves 'n' bytes from 'src' into 'dest', returning 'dest'.		*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/* Ft_memcpy copies 'n' bytes from 'src' into 'dest', returning 'dest'.		*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* Ft_memchr searches for 'c' inside 's' for 'n' bytes.						*/
/* - Returns a VOID * to the first match or NULL, in case there's no match.	*/
void	*ft_memchr(const void *s, int c, size_t n);

/* Ft_memset sets 'n' bytes of 's' with 'c', returning 's'. */
void	*ft_memset(void *s, int c, size_t n);

/* Ft_calloc allocates 'nmemb'*'size' bytes of memory and sets them to '\0'.*/
/* - Returns a VOID * created as a result.									*/
void	*ft_calloc(size_t nmemb, size_t size);

/* Ft_striteri iterates 'f' in every character of 's'. */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Ft_bzero sets 'n' bytes of the VOID * passed as an argument, to '\0'. 	*/
void	ft_bzero(void *s, size_t n);

/* Ft_split returns an ARRAY of CHAR * with every word found in 's'.		*/
/* - The words are divided using 'c'.										*/
char	**ft_split(char const *s, char c);

/* Ft_utoa returns a CHAR * that includes the SIZE_T n argument as text.	*/
/* For function recicling purposes, it accepts a CHAR * base as argument.	*/
char	*ft_utoa_base(size_t n, const char *base);

/* Ft_strnstr returns a CHAR * to the first match of all 'little' in 'big'.	*/
/* - The match must exist in 'len' bytes of 'big'.							*/
/* - Returns 'big' if 'little' is empty.									*/
/* - Returns NULL if no match is found.										*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* Ft_substr returns a new CHAR * with 'len' bytes copied from 's[start]'. 	*/
/* - If start > s_len, it returns a new CHAR * with 1 '\0' byte allocated. 	*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Ft_strmapi iterates the 'f' function in every character of 's'.			*/
/* - Returns a CHAR * with the results of all the iterations in order.		*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Ft_strtrim returns a CHAR * resultant of the trimming of 'set' in 's1'.	*/
/* - Cuts every match of 'set' from the start of 's1' until a non match.	*/
/* - Cuts every match of 'set' from the end of 's1' until a non match.		*/
char	*ft_strtrim(char const *s1, char const *set);

/* Ft_strjoin returns a CHAR * with the result of concatenate 's1' and 's2'.*/
char	*ft_strjoin(char const *s1, char const *s2);

/* Ft_argjoin returns a CHAR * with the result of concatenate all the argv. */
char	*ft_argjoin(char **argv);

/* Ft_strrchr returns a CHAR * to the last ocurrance of 'c' inside 's'.		*/
/* - Return NULL in case no ocurrance is found.								*/
char	*ft_strrchr(const char *s, int c);

/* Ft_strchr returns a CHAR * to the first ocurrance of 'c' inside 's'.		*/
/* - Return NULL in case no ocurrance is found.								*/
char	*ft_strchr(const char *s, int c);

/* Ft_strdup creates and returns a CHAR * that includes 's'.				*/
char	*ft_strdup(const char *s);

/* Ft_itoa returns a CHAR * that includes the INT passed as an argument. 	*/
char	*ft_itoa(int n);

/* Ft_strncmp compares 's1' and 's2' for 'n' bytes.							*/
/* - Returns '0' if true, or a '+' or '-' number if false.(ASCII difference)*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Ft_memcmp compares 's1' and 's2' for 'n' bytes.							*/
/* - Returns '0' if true, or a '+' or '-' number if false.(ASCII difference)*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* Ft_putendl_fd writes all of 's' into the 'fd' passed as an argument.		*/
/* - Writes '\n' at the end, after writing 's', instead of a '\0'.			*/
int		ft_putendl_fd(char *s, int fd);

/* Ft_putchar_fd writes 'c' into the 'fd' passed as an argument. 			*/
int		ft_putchar_fd(char c, int fd);

/* Ft_putstr_fd writes all of 's' into the 'fd' passed as ab argument. 		*/
/* - The '\0' character is not written at the end of 's'.			   		*/
int		ft_putstr_fd(char *s, int fd);

/* Ft_putnbr_fd writes 'n' as a STRING into the 'fd' passed as an argument. */
int		ft_putnbr_fd(int n, int fd);

/* Ft_atol returns an LONG INT with the first number found on a CHAR *.		*/
long	ft_atol(const char *nptr, long *n);

/* Ft_atoi returns an INT with the first number found on a CHAR *.			*/
int		ft_atoi(const char *nptr);

int		ft_isalpha(int c);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_issign(int c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Ft_lstmap creates a T_LIST * result of iterate 'f' on every 'lst.content'*/
/* - If a node created iterating 'f' fails, it frees all the previous nodes.*/
/* - Returns the T_LIST * resulted of iterating 'f' on every 'lst.content'.	*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Ft_lstnew creates and returns a new T_LIST * of only one node.		 	*/
/* - The 'lst.content' is setted as the 'content' passed as an argument.	*/
/* - The 'lst.next' is setted as NULL.									 	*/
t_list	*ft_lstnew(void *content);

/* Ft_lstlast returns a T_LIST * to the last node of 'lst'. */
t_list	*ft_lstlast(t_list *lst);

/* Ft_lstclear frees every node included on the T_LIST ** using 'del'.		*/
/* - Finally, it frees itself.										   		*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* Ft_lstdelone free 'lst.content' with 'del' function. Then it frees lst. 	*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/* Ft_lstiter iterates 'f' on every 'lst-content' of every node on 'lst'. 	*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* Ft_lstadd_front adds the 'new' list to the start of the T_LIST ** .		*/
/* - The previous node at the start of the T_LIST ** is moved to 'lst.next'.*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/* Ft_lstadd_back adds the 'new' list to the end of the T_LIST **.			*/
/* - If the T_LIST ** is empty, it sets 'new' at the start of it.			*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/* Ft_lstsize returns a count off all the nodes inside 'lst'. 				*/
int		ft_lstsize(t_list *lst);

/* Ft that free a poinetr of pointer char									*/
int		ft_free_char(char **to_free);

/* Ft strdup of char **														*/
char	**ft_pstrdup(const char **s);

int		ft_pstrlen(const char **s);

#endif
