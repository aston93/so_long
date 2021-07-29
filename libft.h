/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazurki <dmazurki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:57:51 by dmazurki          #+#    #+#             */
/*   Updated: 2021/06/21 19:59:22 by dmazurki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	*ft_memset(void *str, int c, int n);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n);
void	*ft_memmove(void *destination, const void *source, size_t num);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int dig);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int ch);
int		ft_tolower(int c);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*	----------------ALL BELOW: FT_PRINTF	*/

typedef struct s_flag
{
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		flag_asterisks;
	int		flag_plus;
	int		field_width;
	int		precision;
	int		i;
	int		result;
	int		val_len;
	int		prtd_in_handl;
	int		val;
	char	*Fstr;
}					t_flag;

/*	Supporting functions	*/

int		ft_printf(const char *str, ...);
void	reset_flags(t_flag *flag);
void	check_flags(t_flag *flag, const char *arr, va_list *arg);
char	*ft_printf_itoa(int n, t_flag *flag);
void	ft_putstr_printf(char *str, t_flag *flag);
void	ft_putstr_w_precision_printf(char *str, t_flag *flag);
void	padding(int padding_size, t_flag *flag, char chr);
char	*add_plus_sign(char *str);
void	ft_hex_converter(va_list *arg, t_flag *flag, char chr);
char	*ft_itoa_unsigned(unsigned int n);
char	store_uppercase(int num);
char	store_lowercase(int num);
void	hex_helper_2(t_flag *flag);
void	hex_helper_3(t_flag *flag);

/* specifier handlers */

void	ft_prctg_handler(const char *str, t_flag *flag);
void	ft_c_handler(va_list *arg, t_flag *flag);
void	ft_s_handler(va_list *arg, t_flag *flag);
void	ft_d_i_handler(va_list *arg, t_flag *flag);
void	ft_u_handler(va_list *arg, t_flag *flag);
void	ft_p_handler(va_list *arg, t_flag *flag);

/*	test files	*/
void	ztest_c_handler(void);
void	ztest_prctg_handler(void);
void	ztest_d_i_handler(void);
void	ztest_s_handler(void);
void	ztest_p_handler(void);
void	ztest_u_handler(void);
void	ztest_X_handler(void);
void	ztest_x_handler(void);
void	ztest_mixed_handler(void);

#endif