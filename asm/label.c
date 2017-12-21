/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Apr  2 20:35:21 2014 Antoine Buchser
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

int	is_label(char *str)
{
  return ((str[my_strlen(str) - 1] == ':') ? 1 : 0);
}

void	add_label_to_list(t_lab **list, char *name, int pos)
{
  t_lab	*elem;
  t_lab	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    my_error(MALLOC_ERROR);
  elem->name = NULL;
  elem->name = my_strndup(name, my_strlen(name) - 1);
  elem->pos = pos;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = elem;
    }
}

int	label_exists(t_lab *list, char *name)
{
  t_lab	*tmp;
  int	check;

  check = 0;
  tmp = list;
  while (tmp != NULL && check == 0)
    {
      if (tmp->name
	  && name
	  && my_strcmp(tmp->name, name) == 0)
	check = 1;
      tmp = tmp->next;
    }
  return (check);
}

int	save_label(t_asm *core, char *name, int pos)
{
  if (!label_exists(core->labels, name))
    {
      add_label_to_list(&(core->labels), name, pos);
      return (0);
    }
  else
    return (-1);
}

int	get_label_pos(t_asm *core, char *name)
{
  t_lab	*tmp;
  int	check;

  if (label_exists(core->labels, name))
    {
      check = 0;
      tmp = core->labels;
      while (tmp && check == 0)
	{
	  if (my_strcmp(tmp->name, name) == 0)
	    check = 1;
	  else
	    tmp = tmp->next;
	}
      return (tmp->pos);
    }
  else
    return (-1);
}
