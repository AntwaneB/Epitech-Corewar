/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 22:54:59 2014 Antoine Buchser
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

static int	get_first_command_pos(t_asm *core)
{
  t_line	*tmp;
  int		found;
  int		i;

  found = 0;
  i = 0;
  tmp = core->content;
  while (tmp && !found)
    {
      if (tmp->wordtab != NULL && tmp->wordtab[0] != NULL
	  && my_strcmp(tmp->wordtab[0], NAME_CMD_STRING)
	  && my_strcmp(tmp->wordtab[0], COMMENT_CMD_STRING))
	found = 1;
      tmp = tmp->next;
      i++;
    }
  return (i);
}


int	file_content_is_valid(t_asm *core)
{
  int	pos;

  pos = 0;
  if (!name_is_valid(core))
    {
      my_putstr("Invalid or missing champion name.\n");
      return (-1);
    }
  if (!comment_is_valid(core))
    {
      my_putstr("Invalid champion comment.\n");
      return (-1);
    }
  if ((pos = content_is_valid(core,
			      get_first_command(core),
			      get_first_command_pos(core),
			      pos)) == -1)
    return (-1);
  core->size = pos;
  return (pos);
}
