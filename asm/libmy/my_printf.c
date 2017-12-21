/*
** my_printf.c for my_printf in /home/buchse_a/Documents/PSU_2018_my_printf
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Nov  4 09:53:03 2013 Antoine Buchser
** Last update Thu Nov 14 16:03:14 2013 Antoine Buchser
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	my_special_modifiers(va_list ap, char *str)
{
  if (str[0] == '0' || str[0] == '.')
    return (zero_mod(ap, str));
  else if (str[0] == ' ' || str[0] == '+')
    return (spaceandplus_mod(ap, str));
  else if (str[0] == '-')
    return (minus_mod(ap, str));
  else if (str[0] == '#')
    return (sharp_mod(ap, str));
  else if (str[0] == 'h')
    return (h_char_mod(ap, str));
  else if (str[0] >= '1' && str[0] <= '9')
    return (number_mod(ap, str));
  else
    return (1);
}

int	my_bigs_arg_manage(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 32 && str[i] <= 126 || str[i] == 0)
	my_putchar(str[i]);
      else
	{
	  my_putchar('\\');
	  if (str[i] < 10)
	    my_putchar('0');
	  if (str[i] < 100)
	    my_putchar('0');
	  my_putnbr_base((str[i]), "01234567");
	}
      i = i + 1;
    }
}

int	my_x_arg_manage(unsigned int nb, char c)
{
  if (c == 'x')
    my_putunnbr_base(nb, "0123456789abcdef");
  else
    my_putunnbr_base(nb, "0123456789ABCDEF");
}

int	my_param_manage(va_list ap, char *s)
{
  if (s[0] == 'd' || s[0] == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (s[0] == 's')
    my_putstr(va_arg(ap, char*));
  else if (s[0] == 'c')
    my_putchar(va_arg(ap, int));
  else if (s[0] == '%')
    my_putchar('%');
  else if (s[0] == 'o')
    my_putnbr_base(va_arg(ap, int), "01234567");
  else if (s[0] == 'u')
    my_put_unnbr(va_arg(ap, unsigned int));
  else if (s[0] == 'p')
    my_p_arg_manage(va_arg(ap, void*));
  else if (s[0] == 'x' || s[0] == 'X')
    my_x_arg_manage(va_arg(ap, unsigned int), s[0]);
  else if (s[0] == 'b')
    my_putunnbr_base(va_arg(ap, unsigned int), "01");
  else if (s[0] == 'S')
    my_bigs_arg_manage(va_arg(ap, char*));
  else if (my_char_type(s[0]) == 1 || my_char_type(s[0]) == 2 || s[0] == '.')
    return (my_special_modifiers(ap, s));
  else
    my_puterror(s[0]);
  return (0);
}

int		my_printf(char *format, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, format);
  i = 0;
  while (format[i])
    {
      if (format[i] == '%')
	i = i + 1 + my_param_manage(ap, format + i + 1);
      else
	my_putchar(format[i]);
      i++;
    }
  va_end(ap);
}
