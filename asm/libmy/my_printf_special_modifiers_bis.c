/*
** special_modifiers_bis.c for my_printf in /home/buchse_a/Documents/PSU_2018_my_printf
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Nov  4 14:06:25 2013 Antoine Buchser
** Last update Thu Nov 14 16:04:16 2013 Antoine Buchser
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

/*
** Passage de int et non short int car cast automatique de va_arg
*/
int	h_char_mod(va_list ap, char *s)
{
  if (s[1] == 'd' || s[1] == 'i')
    {
      my_put_nbr(va_arg(ap, int));
      return (1);
    }
  else if (s[1] == 'u' || s[1] == 'o' || s[1] == 'x' || s[1] == 'X')
    {
      my_put_nbr(va_arg(ap, int));
      return (1);
    }
  else if (s[1] == 'h')
    return (hh_char_mod(ap, s + 1));
  else
    return (1);
}

int	hh_char_mod(va_list ap, char *s)
{
  if (s[1] == 'd' || s[1] == 'i')
    {
      my_put_nbr(va_arg(ap, int));
      return (2);
    }
  else if (s[1] == 'u' || s[1] == 'o' || s[1] == 'x' || s[1] == 'X')
    {
      my_put_nbr(va_arg(ap, int));
      return (2);
    }
  else
    return (1);
}
