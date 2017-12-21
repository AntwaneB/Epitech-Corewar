/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 12:31:11 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

static void	write_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_error(char *str)
{
  if (str != NULL)
    write_error(str);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}

char	*my_concat(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*des;

  if ((des = malloc((my_strlen(s1) + my_strlen(s2) + 2) * sizeof(char))) == NULL)
    my_error(MALLOC_ERROR);
  i = 0;
  j = -1;
  while (++j < my_strlen(s1))
    {
      des[i] = s1[j];
      i++;
    }
  j = -1;
  while (j++ < my_strlen(s2))
    {
      des[i] = s2[j];
      i++;
    }
  des[i] = '\0';
  return (des);
}

int	count_tab(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab[i])
    i++;
  return (i);
}
