/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 22:01:52 2014 Antoine Buchser
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

int	is_valid_command(t_asm *core, char **wordtab, int move, int line_nb)
{
  op_t	*op_infos;
  int	i;
  char	**args_tab;

  i = 0;
  args_tab = my_explode(wordtab[1 + move], ", ");
  op_infos = get_opcode_tab(core, wordtab[move]);
  if (count_tab(args_tab) != op_infos->nbr_args)
    {
      if (line_nb >= 0)
	my_printf("\tInvalid arguments number on line #%d\n", line_nb);
      return (0);
    }
  else
    while (args_tab[i])
      {
	if (!((op_infos->type[i]) & get_arg_type(args_tab[i])))
	  {
	    if (line_nb >= 0)
	      my_printf("\tInvalid arguments type on line #%d\n", line_nb);
	    return (0);
	  }
	i++;
      }
  return (1);
}

int	content_is_valid(t_asm *core, t_line *command, int line_nb, int pos)
{
  int	move;

  while (command)
    {
      if (command->wordtab && command->wordtab[0]
	  && (move = is_label(command->wordtab[0])) == 1)
	save_label(core, command->wordtab[0], pos);
      if (command->wordtab && command->wordtab[move]
	  && is_opcode(command->wordtab[move]))
	{
	  if (!is_valid_command(core, command->wordtab, move, line_nb))
	    return (-1);
	  pos += get_pos_jump(core, command->wordtab, move);
	}
      else if (command->wordtab && command->wordtab[move]
	       && !is_opcode(command->wordtab[move]))
	{
	  my_printf("\tError at line %d: Unknown mnemonic \"%s\"\n",
		    line_nb, command->wordtab[move]);
	  return (-1);
	}
      command = command->next;
      line_nb++;
    }
  return (pos);
}
