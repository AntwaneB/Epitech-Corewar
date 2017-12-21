/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 22:01:35 2014 Antoine Buchser
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

int	get_pos_jump(t_asm *core, char **wordtab, int move)
{
  int	pos;
  int	i;
  char	**args_tab;

  args_tab = my_explode(wordtab[1 + move], ", ");
  pos = 1;
  if (need_args_sum(wordtab[move]))
    pos++;
  i = -1;
  while (args_tab[++i])
    {
      if (i > 0 && my_strcmp("sti", wordtab[move]) == 0)
	pos += IND_SIZE;
      else if (my_strcmp("zjmp", wordtab[move]) == 0
	       || my_strcmp("fork", wordtab[move]) == 0
	       || my_strcmp("lfork", wordtab[move]) == 0)
	pos += IND_SIZE;
      else if (get_arg_type(args_tab[i]) == T_REG)
	pos += 1;
      else if (get_arg_type(args_tab[i]) == T_DIR)
	pos += DIR_SIZE;
      else if (get_arg_type(args_tab[i]) == T_IND)
	pos += IND_SIZE;
    }
  return (pos);
}
