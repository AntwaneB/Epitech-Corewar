/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 17:17:52 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

static int	is_in_str(char c, char *str)
{
  int		i;
  int		check;

  check = 0;
  i = 0;
  while (str[i] && check == 0)
    {
      if (str[i] == c)
	check = 1;
      i++;
    }
  return (check);
}

int	labelname_is_valid(char *name)
{
  int	i;
  int	check;

  check = 1;
  i = 0;
  while (name[i] && check == 1)
    {
      if (!is_in_str(name[i], LABEL_CHARS))
	check = 0;
      i++;
    }
  if (name[i - 1] == LABEL_CHAR)
    check = 1;
  return (check);
}
