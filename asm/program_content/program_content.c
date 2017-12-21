/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 12:26:07 2014 Thomas MORITZ
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

t_line		*get_first_command(t_asm *core)
{
  t_line	*command;
  t_line	*tmp;

  command = NULL;
  tmp = core->content;
  while (tmp && command == NULL)
    {
      if (tmp->wordtab != NULL && tmp->wordtab[0] != NULL
	  && my_strcmp(tmp->wordtab[0], NAME_CMD_STRING)
	  && my_strcmp(tmp->wordtab[0], COMMENT_CMD_STRING))
	command = tmp;
      tmp = tmp->next;
    }
  return (command);
}

void		write_all_command(t_asm *core, char **wordtab, int move, int *pos)
{
  t_line	command;
  int		minus;

  write_opcode(core, wordtab[move]);
  *pos += 1;
  minus = 1;
  if (need_args_sum(wordtab[move]))
    {
      minus++;
      *pos += 1;
      write_args_sum(core, wordtab, move);
    }
  command.wordtab = wordtab;
  command.move = move;
  write_all_params(core, &command, pos, *pos - minus);
}

void		write_program_content(t_asm *core)
{
  t_line	*command;
  int		move;
  int		pos;

  pos = 0;
  if ((command = get_first_command(core)) != NULL)
    {
      while (command != NULL)
	{
	  if (command->wordtab != NULL)
	    move = is_label(command->wordtab[0]);
	  if (command->wordtab != NULL && command->wordtab[move] != NULL
	      && is_opcode(command->wordtab[move]))
	    {
	      if (is_valid_command(core, command->wordtab, move, -1))
		write_all_command(core, command->wordtab, move, &pos);
	    }
	  command = command->next;
	}
    }
}
