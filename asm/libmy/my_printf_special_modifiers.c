/*
** special_modifiers.c for my_printf in /home/buchse_a/Documents/PSU_2018_my_printf
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Nov  4 14:06:25 2013 Antoine Buchser
** Last update Thu Nov 14 16:57:55 2013 Antoine Buchser
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	spaceandplus_mod(va_list ap, char *str)
{
  int	tmp;

  if (str[1] == 'd' || str[1] == 'i')
    {
      tmp = va_arg(ap, int);
      if (tmp > 0)
	my_putchar(str[0]);
      my_put_nbr(tmp);
    }
  else
    my_param_manage(ap, str + 1);
  return (1);
}

int	sharp_mod(va_list ap, char *str)
{
  if (str[1] == 'o')
    {
      my_putchar('0');
      my_param_manage(ap, str + 1);
    }
  else if (str[1] == 'x')
    {
      my_putstr("0x");
      my_param_manage(ap, str + 1);
    }
  else if (str[1] == 'X')
    {
      my_putstr("0X");
      my_param_manage(ap, str + 1);
    }
  else
    my_param_manage(ap, str + 1);
  return (1);
}

int	minus_mod(va_list ap, char *str)
{
  int	i;
  int	size;

  size = my_int_length(my_getnbr(str + 1));
  i = 0;
  my_param_manage(ap, str + size + 1);
  while (i < my_getnbr(str + 1) - size)
    {
      my_putchar(' ');
      i++;
    }
  return (size + 1);
}

int	zero_mod(va_list ap, char *str)
{
  int	tmp;
  int	i;
  int	size;

  if (my_char_type(str[1]) == 1)
    {
      size = my_int_length(my_getnbr(str + 1));
      if (str[size + 1] == 'd')
	{
	  tmp = va_arg(ap, int);
	  i = 0;
	  while (i < my_getnbr(str + 1) - my_int_length(tmp))
	    {
	      my_putchar('0');
	      i++;
	    }
	  my_put_nbr(tmp);
	}
      else
	my_param_manage(ap, str + size + 1);
      return (size + 1);
    }
  else
    my_param_manage(ap, str + 1);
  return (1);
}

int	number_mod(va_list ap, char *str)
{
  int	i;
  int	size;

  size = my_int_length(my_getnbr(str));
  i = 0;
  while (i < my_getnbr(str) - size)
    {
      my_putchar(' ');
      i++;
    }
  my_param_manage(ap, str + size);
  return (size + 1);
}
