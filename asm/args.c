/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Apr  2 19:04:26 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int	get_arg_type(char *arg)
{
  if (arg[0] == 'r')
    return (T_REG);
  else if (arg[0] == '%')
    return (T_DIR);
  else
    return (T_IND);
}
