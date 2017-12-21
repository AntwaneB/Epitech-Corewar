/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 21:31:38 2014 Antoine Buchser
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

op_t	*get_opcode_tab(t_asm *core, char *opname)
{
  int	i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(op_tab[i].mnemonique, opname) == 0)
	return (&(op_tab[i]));
      i++;
    }
  return (NULL);
}

int	write_opcode(t_asm *core, char *opname)
{
  op_t	*op_infos;

  op_infos = get_opcode_tab(core, opname);
  my_putchar_fd(op_infos->code, core->writefd);
  return (op_infos->nbr_args);
}
