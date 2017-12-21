/*
** check_arg.c for corewar in /home/thomas/Projets/corewar-2014/asm
** 
** Made by Thomas MORITZ
** Login   <moritz_t@epitech.eu>
** 
** Started on  Wed Mar 26 12:35:50 2014 Thomas MORITZ
** Last update Wed Mar 26 12:42:48 2014 Thomas MORITZ
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

int	is_valid_args(t_asm *core, char *opname, char **arg)
{
  int	i;
  int	arg_nbr;

  i = 0;
  arg_nbr = 0;
  while (arg[arg_nbr] != NULL)
    arg_nbr++;
  while (op_tab[i].mnemonique)
    {
      if (my_strcmp(op_tab[i].mnemonique, opname) == 0)
	{
	  if (arg_nbr == op_tab[i].nbr_args)
	    return (1);
	  else
	    return (0);
	}
      i++;
    }
}
