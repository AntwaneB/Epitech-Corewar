
/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Tue Apr  8 12:09:39 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void	write_program_size(t_asm *core)
{
  int	tmp;
  int	i;

  i = 0;
  while (i < 5)
    {
      my_putchar_fd(0, core->writefd);
      i++;
    }
  tmp = core->size;
  if (tmp > 255)
    my_putchar_fd(tmp / 256, core->writefd);
  else
    my_putchar_fd(0, core->writefd);
  my_putchar_fd(tmp % 256, core->writefd);
}
