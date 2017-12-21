/*
** remove_space.c for corouar in /home/thomas/Projets/corewar-2014
**
** Made by Thomas MORITZ
** Login   <moritz_t@epitech.eu>
**
** Started on  Thu Apr 10 17:05:59 2014 Thomas MORITZ
** Last update Thu Apr 10 23:53:36 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

char	*remove_space(char *str)
{
  char	*save;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((save = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    my_error("Malloc Failed\n");
  while (str[i] && str[i] != COMMENT_CHAR && str[i] != ';')
    {
      if (str[i] == ' ' && str[i - 1] != SEPARATOR_CHAR)
	{
	  save[j] = ' ';
	  j++;
	}
      else if (str[i] != ' ')
	{
	  save[j] = str[i];
	  j++;
	}
      i++;
    }
  save[j] = '\0';
  return (save);
}
