/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 12:24:37 2014 Thomas MORITZ
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

int	write_registery(t_asm *core, char *arg,
			int cur_pos, int command_start)
{
  int	reg_nb;

  reg_nb = my_getnbr(arg + 1);
  my_putchar_fd(reg_nb, core->writefd);
  return (1);
}

static void		write_label(t_asm *core, char *arg,
				    int cur_pos, int size)
{
  unsigned short	label_nb;
  int			i;
  int			zeros;

  label_nb = (get_label_pos(core, arg + 2)) - cur_pos % IDX_MOD;
  zeros = (label_nb <= 255) ? 1 : 2;
  i = -1;
  while (++i < size - zeros)
    my_putchar_fd(0, core->writefd);
  if (zeros == 2)
    my_putchar_fd(label_nb / 256, core->writefd);
  my_putchar_fd(label_nb % 256, core->writefd);
}

int			write_direct(t_asm *core, char *arg,
				     int cur_pos, int command_start)
{
  unsigned long		direct_nb;
  int			i;
  int			zeros;

  if (my_str_isnum(arg + 1))
    {
      direct_nb = (my_getnbr(arg + 1) < 0) ?
	(unsigned short)(my_getnbr(arg + 1)) : my_getnbr(arg + 1);
      write_direct_nb(core, direct_nb);
    }
  else if (arg[1] == LABEL_CHAR)
    write_label(core, arg, command_start, DIR_SIZE);
  return (DIR_SIZE);
}

int			write_indirect(t_asm *core, char *arg,
				       int cur_pos, int command_start)
{
  unsigned short	indirect_nb;
  int			i;

  if (arg[0] != LABEL_CHAR)
    {
      indirect_nb = my_getnbr(arg) % IDX_MOD;
      i = -1;
      if (indirect_nb <= 255)
	{
	  while (++i < IND_SIZE - 1)
	    my_putchar_fd(0, core->writefd);
	  my_putchar_fd(indirect_nb, core->writefd);
	}
      else
	{
	  while (++i < IND_SIZE - 2)
	    my_putchar_fd(0, core->writefd);
	  my_putchar_fd(indirect_nb / 256, core->writefd);
	  my_putchar_fd(indirect_nb % 256, core->writefd);
	}
    }
  else
    write_label(core, arg, command_start, IND_SIZE);
  return (IND_SIZE);
}

void	write_all_params(t_asm *core, t_line *command,
			 int *pos, int command_start)
{
  char	**args_tab;
  int	i;
  int	move;
  char	**wordtab;

  wordtab = command->wordtab;
  move = command->move;
  args_tab = my_explode(wordtab[1 + move], ", ");
  i = 0;
  while (args_tab[i])
    {
      if ((i > 0 && my_strcmp("sti", wordtab[move]) == 0)
	  || my_strcmp("zjmp", wordtab[move]) == 0
	  || my_strcmp("fork", wordtab[move]) == 0
	  || my_strcmp("lfork", wordtab[move]) == 0)
	*pos += write_sti_arg(core, args_tab[i], *pos, command_start);
      else if (args_tab[i][0] == 'r')
	*pos += write_registery(core, args_tab[i], *pos, command_start);
      else if (args_tab[i][0] == '%')
	*pos += write_direct(core, args_tab[i], *pos, command_start);
      else
	*pos += write_indirect(core, args_tab[i], *pos, command_start);
      i++;
    }
}
