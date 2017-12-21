/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Mar 26 13:00:48 2014 Antoine Buchser
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

static void	fill_sum(char **args_tab, char *sum, int i)
{
  if (args_tab[i][0] == 'r')
    {
      sum[i * 2] = 0 + '0';
      sum[i * 2 + 1] = 1 + '0';
    }
  else if (args_tab[i][0] == '%')
    {
      sum[i * 2] = 1 + '0';
      sum[i * 2 + 1] = 0 + '0';
    }
  else
    {
      sum[i * 2] = 1 + '0';
      sum[i * 2 + 1] = 1 + '0';
    }
}

void	write_args_sum(t_asm *core, char **wordtab, int move)
{
  char	sum[9];
  char	**args_tab;
  int	i;

  args_tab = my_explode(wordtab[1 + move], ", ");
  i = 0;
  while (args_tab[i])
    {
      fill_sum(args_tab, sum, i);
      i++;
    }
  while (i < 4)
    {
      sum[i * 2] = 0 + '0';
      sum[i * 2 + 1] = 0 + '0';
      i++;
    }
  sum[8] = '\0';
  my_putchar_fd(my_getnbr_base(sum, "01"), core->writefd);
}
