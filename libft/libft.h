/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:05:11 by psergio-          #+#    #+#             */
/*   Updated: 2021/05/27 13:05:20 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_buffer {
	int		start;
	int		next_nl;
	int		end;
	char	data[BUFFER_SIZE];
}			t_buffer;

/**
 * Retrieves a string that ends with a newline charactere from the file
 * descriptor `fd` and make the pointer `line` point to it
 * */

int				get_next_line(int fd, char **line);

# define GNL_ERROR -1
# define GNL_END_OF_FILE 0
# define GNL_LINE_READ 1
# define GNL_NO_NEWLINE 2

/**
 * A node that points to the next member of the list
 */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stack {
	int		size;
	t_list	*top;
}	t_stack;

/**
 * Joins two blocks of memory in a new mallocked one.
 */

void			*ft_memjoin(void *s1, size_t size1, void *s2, size_t size2);

/**
 * Writes the first `n` bytes of the memory address pointed to by `s` with the
 * value `c`.
 */

void			*ft_memset(void *s, int c, size_t n);

/**
 * Writes the first `n` bytes of the memory address pointed to by `s` with '\0'.
 */

void			ft_bzero(void *s, size_t n);

/**
 * Copy the first `n` bytes of the memory address pointed to by `src` to `dest`.
 * If the memory addresses overlap, there may be data lost.
 */

void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copy the content of `src` to `dest` until `n` bytes are copied, or until
 * a character `c` is found in `src`.
 * If the memory addresses overlap, there may be data lost.
 */

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**
 * Copy up to `n` bytes of `src` to `dest`. The memory addresses may overlap
 * without the worry of data loss.
 */

void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Searches the first `n` bytes of the address `s` for the byte `c`. Returns an
 * address that points to the first occurence of that character if one is found,
 * NULL otherwise.
 */

void			*ft_memchr(const void *s, int c, size_t n);

/**
 * Compares each byte of both memory addresses `s1` and `s2` yp to `n`.
 * If any byte differ, returns the difference between these bytes, both treated
 * as unsigned chars. Returns 0 if no difference is found.
 */

int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Returns the size in bytes of the string `str`.
 */
size_t			ft_strlen(const char *str);

/**
 * Copies `size` - 1 characters of the string `src` to the buffer `dest`,
 * putting a nul-terminator character in the last byte.
 **/

size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * Concatenates the string `src` to the end of the buffer `dest` until
 * `size` - 1 characters are present, putting a nul-terminator character in the
 * last byte.
 * If `dest` does not have enough space in the first `size` bytes, nothing is
 * done.
 */
size_t			ft_strlcat(char *dest, const char *src, size_t size);

/**
 * Searches the string `s` for the character `c`. Returns a pointer that points
 * to the first occurence of that character, or NULL if that character was
 * not found.
 */

char			*ft_strchr(const char *s, int c);

/**
 * Searches the string `s` or the last occurence of the character `c`. Returns
 * a pointer to that character if one is found, NULL otherwise.
 */

char			*ft_strrchr(const char *s, int c);

/**
 * Searches the string `little` inside the string `big`. Returns a pointer to
 * the beginning of the first occurence of `little` if one is found, NULL
 * otherwise.
 */

char			*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Compares each character of both strings `s1` and `s2` up to `n` bytes.
 * If two two characters differ, returns the difference between these two
 * characters, treated as unsigned chars. Returns 0 if no difference is found.
 */

int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Converts the string `str` into a valid integer. If the string is invalid,
 * returns 0. If the number overflows, the result will be overflowed.
 */

int				ft_atoi(const char *str);

/**
 * Converts the string `str` into a valid long integer. If the string is
 * invalid, returns 0. If the number overflows, the result will be overflowed.
 */

long long int	ft_atol(const char *str);

/**
 * Returns true if the string passed as parameter only contains digits
 */

int				ft_isnumber(char *str);

/**
 * returns 1 if the character `c` is a space. 0 otherwise.
 */

int				ft_isspace(int c);

/**
 * returns 1 if the character `c` is a letter. 0 otherwise.
 */

int				ft_isalpha(int c);

/**
 * returns 1 if the character `c` is a digit. 0 otherwise.
 */

int				ft_isdigit(int c);

/**
 * returns 1 if the character `c` is a letter or a digit. 0 otherwise.
 */

int				ft_isalnum(int c);

/**
 * returns 1 if the character `c` is part of the ASCII table. 0 otherwise.
 */

int				ft_isascii(int c);

/**
 * returns 1 if the character `c` is printable. 0 otherwise.
 */

int				ft_isprint(int c);

/**
 * Returns the smallest value between `a` and `b`.
 */

int				ft_min(int a, int b);

/**
 * Returns the smallest value between the unsigned values `a` and `b`.
 */

size_t			ft_umin(size_t a, size_t b);

/**
 * Returns the biggest value between `a` and `b`.
 */

size_t			ft_max(int a, int b);

/**
 * Returns the uppercase version of the character `c`.
 */

int				ft_toupper(int c);

/**
 * Returns the lowercase version of the character `c`.
 */

int				ft_tolower(int c);

/**
 * Returns 1 if the string `str` ends with the characters in the string `tail`
 * in the same order.
 */

int				ft_ends_with(const char *str, const char *tail);

/**
 * Changes oll of the characters inside the string `str` to uppercase.
 */

char			*ft_strtoupper(char *str);

/**
 * Allocates `count` * `size` bytes and fills them with '\0'. Returns NULL
 * if an error occurs.
 */

void			*ft_calloc(size_t count, size_t size);

/**
 * Creates a mallocked copy of the string `s1`. Returns NULL if an error occurs.
 */

char			*ft_strdup(const char *s1);

/**
 * Creates a mallocked substring of the string `s`.
 */

char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Joins both strings `s1` and `s2` in a mallocked buffer.
 */

char			*ft_strjoin(char const *s1, char const *s2);

/**
 * Trims all of the characters in the `set` from the string `s1`. Returns a
 * mallocked string with the result.
 */

char			*ft_strtrim(char const *s1, char const *set);

/**
 * Creates a NULL terminated array of strings composed by the result of the
 * division of `s` in all the occurences of the character `c`.
 * Both the array and every substring must be properly freed after use.
 */

char			**ft_split(char const *s, char c);

/**
 * Converts the number `nbr` into a string representation in any base. The
 * digits of the base must be specified in the string `base`. The minimum base
 * is binary.
 */

char			*ft_stoa_base(size_t nbr, const char *base);

/**
 * Converts the number `n` into a string representation in the decimal base.
 */

char			*ft_itoa(int n);

/**
 * Converts the unsigned int number `n` into a string representation
 * in the decimal base.
 */

char			*ft_uitoa(unsigned int nbr);
char			*ft_itox(ssize_t n);
char			*ft_stox(size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);

/* Prints the string `*s` in the file descriptor `fd` */
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new_element);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new_element);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

t_stack			*ft_stack_new(void);
void			ft_stack_push(t_stack *stack, void *content);
void			*ft_stack_pop(t_stack *stack);
void			ft_stack_destroy(t_stack *stack);

/** Does nothing */
void			ft_stack_do_nothing(void *content);

#endif
