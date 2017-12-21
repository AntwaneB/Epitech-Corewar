/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 12:17:45 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void		content_put_in_list(t_line **list, char **wordtab)
{
  t_line	*elem;
  t_line	*tmp;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    my_error(MALLOC_ERROR);
  elem->wordtab = wordtab;
  elem->next = NULL;
  if (*list == NULL)
    *list = elem;
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
    }
}
