/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Apr  9 15:29:48 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../op.h"
#include "../my.h"
#include "../asm.h"

static int	nb_of_zeros(long nb)
{
  if (nb <= 0xff)
    return (3);
  else if (nb <= 0xffff)
    return (2);
  else if (nb <= 0xffffff)
    return (1);
  else
    return (0);
}

void	write_direct_nb(t_asm *core, long direct_nb)
{
  int	i;
  long	tmp;

  tmp = direct_nb;
  i = -1;
  while (++i < nb_of_zeros(direct_nb))
    my_putchar_fd(0, core->writefd);
  if (direct_nb > 0xffffff)
    {
      my_putchar_fd(tmp / (0xffffff + 1), core->writefd);
      tmp = tmp % (0xffffff + 1);
    }
  if (direct_nb > 0xffff)
    {
      my_putchar_fd(tmp / (0xffff + 1), core->writefd);
      tmp = tmp % (0xffff + 1);
    }
  if (direct_nb > 0xff)
    {
      my_putchar_fd(tmp / (0xff + 1), core->writefd);
      tmp = tmp % (0xff + 1);
    }
  my_putchar_fd(tmp, core->writefd);
}
