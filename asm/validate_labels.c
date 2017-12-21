/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 17:22:42 2014 Antoine Buchser
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

static char	*validate_label_in_args(t_asm *core, char **wordtab, int move)
{
  char		**args_tab;
  int		i;

  args_tab = my_explode(wordtab[1 + move], ", ");
  i = 0;
  while (args_tab[i])
    {
      if (args_tab[i][0] == '%' && args_tab[i][1] == LABEL_CHAR)
	{
	  if (!label_exists(core->labels, args_tab[i] + 2))
	    return (args_tab[i] + 2);
	}
      else if (args_tab[i][0] != 'r' && args_tab[i][1] == LABEL_CHAR)
	{
	  if (!label_exists(core->labels, args_tab[i] + 1))
	    return (args_tab[i] + 1);
	}
      i++;
    }
  return (NULL);
}

int		validate_labels(t_asm *core)
{
  t_line	*command;
  char		*error;
  int		move;

  command = get_first_command(core);
  while (command)
    {
      if (command->wordtab && command->wordtab[0]
	  && (move = is_label(command->wordtab[0])) == 1)
	{
	  if (!labelname_is_valid(command->wordtab[0]))
	    my_printf("%s invalid label name.\n", command->wordtab[0]);
	  if (!labelname_is_valid(command->wordtab[0]))
	    return (-1);
	}
      if (command->wordtab && command->wordtab[move])
	{
	  if ((error = validate_label_in_args(core, command->wordtab, move)) != NULL)
	    my_printf("%s: label does not exist.\n", error);
	  if (validate_label_in_args(core, command->wordtab, move) != NULL)
	    return (-1);
	}
      command = command->next;
    }
  return (0);
}
