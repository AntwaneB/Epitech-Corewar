/*
** my_printf.c for my_printf in /home/buchse_a/Documents/PSU_2018_my_printf
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Nov  4 09:53:03 2013 Antoine Buchser
** Last update Sat Nov 23 10:47:44 2013 Antoine Buchser
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void	my_puterror(char c)
{
  my_putchar('%');
  my_putchar(c);
}

void	my_p_arg_manage(void *ptr)
{
  my_putstr("0x");
  my_putlongnbr_base((unsigned long)ptr, "0123456789abcdef");
}

int	my_char_type(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else if (c == ' ' || c == '+' || c == '#' || c == '*'
	   || c == '-' || c == 'h')
    return (2);
  else
    return (0);
}

char    *my_get_charnbr(char *str)
{
  int   i;
  char  *dest;

  i = 0;
  while (my_char_type(str[i]) == 1)
    i = i + 1;
  i = i - 1;
  dest = malloc((i + 1) * sizeof(char));
  if (dest == NULL)
    return (0);
  dest[i + 1] = '\0';
  while (i >= 0)
    {
      dest[i] = str[i];
      i = i - 1;
    }
  return (dest);
}

int	my_int_length(int nb)
{
  int	i;

  i = 1;
  while (nb > 9)
    {
      i++;
      nb = nb / 10;
    }
  return (i);
}
