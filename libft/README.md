# libft

[![built with C](https://img.shields.io/badge/built%20with-C-blue.svg)](https://docs.microsoft.com/es-es/cpp/c-language/?view=msvc-170)

```Makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft buffed                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uherrero <uliherre@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 19:37:36 by uherrero          #+#    #+#              #
#    Updated: 2022/03/22 16:46:53 by uliherre         ##   ######.es           #
#                                                                              #
# **************************************************************************** #
```

# table of contents

- [libft](#libft)
- [table of contents](#table-of-contents)
- [subject](#subject)
- [modules](#modules)
  - [ft_bit](#ft_bit)
  - [ft_put](#ft_put)
  - [ft_mem](#ft_mem)
  - [ft_ctype](#ft_ctype)
  - [ft_num](#ft_num)
  - [ft_str](#ft_str)
  - [ft_list](#ft_list)
  - [ft_gnl](#ft_gnl)
  - [ft_cronos](#ft_cronos)

# subject

<object data="https://github.com/TIxtex/libft/blob/master/es.subject.pdf" type="application/pdf">
    <embed src="https://github.com/TIxtex/libft/blob/master/es.subject.pdf">
        <p>This browser does not support PDFs. PDF link: <a href="https://github.com/TIxtex/libft/blob/master/es.subject.pdf">__PDF__ </a>.</p>
    </embed>
</object>


# modules

## ft_bit

```C
unsigned char ft_bit(unsigned char x);
unsigned char ft_bit_clear(unsigned char var, unsigned int bit);
unsigned char ft_bit_get(unsigned char var, unsigned char bit);
unsigned char ft_bit_set(unsigned char var, unsigned char bit);
unsigned char ft_bit_toggle(unsigned char var, unsigned char bit);
```

## ft_put

```C
void      ft_putchar_fd(char c, int fd);
void      ft_putstr_fd(char *s, int fd);
void      ft_putendl_fd(char *s, int fd);
void      ft_putnbr_fd(int n, int fd);
void      ft_puterror(const char *error);
```

## ft_mem

```C
void      *ft_calloc(size_t count, size_t size);
void      *ft_memset(void *dst, int c, size_t len);
void      ft_bzero(void *s, size_t n);
void      *ft_memcpy(void *dst, const void *src, size_t n);
void      *ft_memcpy_r(void *dst, const void *src, size_t n);
void      *ft_memccpy(void *dst, const void *src, int c, size_t n);
void      *ft_memmove(void *dst, const void *src, size_t len);
int       ft_memcmp(const void *s1, const void *s2, size_t n);
void      *ft_memchr(const void *s, int c, size_t n);
```

## ft_ctype

```C
int       ft_isalnum(int c);
int       ft_isalpha(int c);
int       ft_isascii(int c);
int       ft_isdigit(int c);
int       ft_isprint(int c);
int       ft_isspace(int c);
int       ft_tolower(int c);
int       ft_toupper(int c);
```

## ft_num

```C
int       ft_atoi(const char *str);
long      ft_atol(const char *str);
long int  ft_strtol(const char *str, char **endptr, int base);
char      *ft_itoa(int n);
char      *ft_utoa(unsigned int n);
```

## ft_str

```C
size_t    ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t    ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t    ft_strlen(const char *s);
int       ft_strncmp(const char *s1, const char *s2, size_t n);
char      *ft_strnstr(const char *haystack, const char *needle, size_t len);
char      *ft_strrchr(const char *s, int c);
char      *ft_substr(char const *s, unsigned int start, size_t len);
char      *ft_strjoin(char const *s1, char const *s2);
char      *ft_strjoin_f1(char *s1, char const *s2);
char      *ft_strjoin_f2(char const *s1, char *s2);
char      *ft_strjoin_f1_f2(char *s1, char *s2);
char      *ft_strtrim(char const *s1, char const *set);
char      *ft_strchr(const char *s, int c);
char      *ft_strdup(const char *s1);
void      ft_strrev(char *str);
char      *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char      **ft_split(char const *s, char c);
```

## ft_list

```C
struct s_list;
struct s_list_link;

t_list    *ft_lstnew(void *content);
void      ft_lstadd_front(t_list **alst, t_list *new);
int       ft_lstsize(t_list *lst);
t_list    *ft_lstlast(t_list *lst);
void      ft_lstadd_back(t_list **alst, t_list *new);
void      ft_lstdelone(t_list *lst, void (*del)(void *));
void      ft_lstclear(t_list **lst, void (*del)(void *));
void      ft_lstiter(t_list *lst, void (*f)(void *));
t_list    *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

## ft_gnl

```C
int       get_next_line(int fd, char **line);
```

## ft_cronos

```C
long long ft_time_now(void);
long long ft_time_diff(long long start, long long end);
```
