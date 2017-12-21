/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Mar 26 13:10:16 2014 Antoine Buchser
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

int	need_args_sum(char *opcode)
{
  if (my_strcmp(opcode, "live") != 0
      && my_strcmp(opcode, "zjmp") != 0
      && my_strcmp(opcode, "fork") != 0
      && my_strcmp(opcode, "lfork") != 0)
    return (1);
  else
    return (0);
}
