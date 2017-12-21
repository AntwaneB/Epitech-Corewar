/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Mar 26 13:11:31 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int	is_opcode(char *mnemonique)
{
  int	i;
  int	check;

  check = 0;
  i = 0;
  while (op_tab[i].mnemonique && check == 0)
    {
      if (my_strcmp(op_tab[i].mnemonique, mnemonique) == 0)
	check = 1;
      i++;
    }
  return (check);
}
