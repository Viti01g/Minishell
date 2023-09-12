/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:34:46 by uliherre          #+#    #+#             */
/*   Updated: 2023/06/06 18:20:12 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h> /**	write();	**/
# include <stdlib.h> /**	malloc();	**/
# include <stddef.h> /**	NULL, size_t, offsetof();	**/
# include <sys/time.h> /**	gettimeofday()	**/
# include <limits.h>

# ifndef MY_CONSTANT_H
#  define MY_CONSTANT_H
#  define FALSE 0
#  define TRUE 1
#  define ZERO 0
#  define BYTE 1
#  define BIT 8
#  define TO_UPPER - 32
#  define TO_LOWER + 32
#  define A_UPPER 65
#  define Z_UPPER 90
#  define A_LOWER 97
#  define Z_LOWER 122
#  define _1K 1000
# endif

# ifndef MY_TYPES
#  define MY_TYPES

typedef struct s_smart_str	t_smart_str;
typedef struct s_smart_str	t_ss;

struct	s_smart_str
{
	size_t		size;
	char		*str;
};

# endif
# ifndef BONUS
#  define BONUS

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_list_d
{
	void				*content;
	struct s_list_d		*next;
	struct s_list_d		*prev;
}						t_list_d;

/**	FT_LIST	**/
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
void			del(void *to_del);
/**	END_FT_LIST	**/

/**	FT_LIST_D	**/
t_list_d		*ft_lstnew_d(void *content);
void			ft_lstadd_front_d(t_list_d **lst, t_list_d **new);
void			ft_lstadd_back_d(t_list_d **lst, t_list_d **new);
void			ft_lstdelone_d(t_list_d **lst, void (*del)(void *));
t_list_d		*ft_lstmap_d(t_list_d *lst,
					void *(*f)(void *), void(*del)(void *));
/**	END_FT_LIST_D	**/

# endif

/**	START_FT_NUM	**/
int				ft_atoi(const char *str);
long int		ft_atol(const char *str);
char			*ft_itoa(int n);
/**	END_FT_NUM	**/

/**	START_FT_CTYPE	**/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isxdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
/**	END_FT_CTYPE	**/

/**	START_FT_STR	**/
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(
					const char *haystack, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			**ft_split(char const *s, char c);
void			ft_strrev(char *str);
/**	END_FT_STR	**/

/**	START_FT_MEM	**/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memcpy_r(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
/** END_FT_MEM	**/

/**	START_FT_PUT	**/
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_puterror(const char *error);
/**	END_FT_PUT	**/

#endif
