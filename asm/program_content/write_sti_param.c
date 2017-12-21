/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Apr  9 13:05:33 2014 Antoine Buchser
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

void			write_sti_label(t_asm *core, char *arg, int cur_pos)
{
  unsigned short	label_nb;
  int			i;
  int			zeros;

  label_nb = (get_label_pos(core, arg + 2)) - cur_pos % IDX_MOD;
  zeros = (label_nb <= 255) ? 1 : 2;
  i = -1;
  while (++i < IND_SIZE - zeros)
    my_putchar_fd(0, core->writefd);
  if (zeros == 2)
    my_putchar_fd(label_nb / 256, core->writefd);
  my_putchar_fd(label_nb % 256, core->writefd);
}

int			write_sti_arg(t_asm *core, char *arg,
				      int cur_pos, int command_start)
{
  unsigned short	indirect_nb;
  int	i;

  if (arg[0] != LABEL_CHAR && (arg[0] != DIRECT_CHAR || arg[1] != LABEL_CHAR))
    {
      indirect_nb = my_getnbr((arg[0] == 'r'
			       || arg[0] == DIRECT_CHAR) ? arg + 1 : arg)
	% IDX_MOD;
      i = -1;
      if (indirect_nb <= 255)
	{
	  while (++i < IND_SIZE - 1)
	    my_putchar_fd(0, core->writefd);
	}
      else
	{
	  while (++i < IND_SIZE - 2)
	    my_putchar_fd(0, core->writefd);
	  my_putchar_fd(indirect_nb / 256, core->writefd);
	}
      my_putchar_fd(indirect_nb % 256, core->writefd);
    }
  else
    write_sti_label(core, arg, command_start);
  return (IND_SIZE);
}
