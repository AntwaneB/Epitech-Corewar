/*
** my.h for libmy in /home/buchse_a/Documents/PSU_2013_my_ls
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Nov 28 14:21:42 2013 Antoine Buchser
** Last update Wed Apr  9 13:32:55 2014 Antoine Buchser
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
long	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);

/*
** Fonctions ajoutees
*/
int	my_putnbr_base(int nbr, char *base);
int	my_getnbr_base(char *str, char *base);
int	my_factorielle_rec(int nb);
int	my_show_wordtab(char **tab);
char	**my_str_to_wordtab(char *str);
char	*sum_params(int argc, char **argv);
char	*my_strdup(char *src);
int	my_put_unnbr(unsigned int nb);
int	my_putposnbr_base(int nbr, char *base);
int	my_putunnbr_base(unsigned long nbr, char *base);
int	my_putlongnbr_base(long int nbr, char *base);
int	my_printf(char *format, ...);
char	*my_strndup(char *str, int len);

/*
** Sous-fonctions
*/
int	my_morethanint(char *str, int nb_moins);
int	my_nb_lenght_char(char *str);
int	my_nbmoins(char *str);
int	get_pos_b(char c, char *base);
int	my_base_ok(char *str, char *base);
int	call_my_power_rec(int nb, int result, int power);
int	my_put_maxintneg();
int	my_put_nbr_rec(int nb, int tmp, int puissance);
void	my_put_zeros(int nbr);
char	my_char_swap(char *a, char *b);
int	my_isalphanumeric(char c);
int	my_strcmp2(char *str, char *to_find);
int	my_char_isalphanum(char c);
int	my_nb_sep(char *str);
char	**create_str_to_wordtab(char *str, char **tab, int nb_sep);
int	my_put_unnbr_rec(unsigned int nb, int tmp, int puissance);


/*
** my_printf
*/
int	spaceandplus_mod(va_list ap, char *str);
int	sharp_mod(va_list ap, char *str);
int	minus_mod(va_list ap, char *str);
int	zero_mod(va_list ap, char *str);
int	number_mod(va_list ap, char *str);
int	h_char_mod(va_list ap, char *s);
int	hh_char_mod(va_list ap, char *s);
void	my_puterror(char c);
void	my_p_arg_manage(void *ptr);
int	my_char_type(char c);
char	*my_get_charnbr(char *str);
int	my_int_length(int nb);

#endif /* !MY_H_ */
