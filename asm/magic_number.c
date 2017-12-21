/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Wed Mar 19 13:10:12 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void	write_magic_number(t_asm *core)
{
  int	magic;
  int	tmp;
  int	write_fd;

  write_fd = core->writefd;
  magic = COREWAR_EXEC_MAGIC;
  my_putchar_fd('\0', write_fd);
  tmp = (magic & 0xFF0000) >> 16;
  write(write_fd, &tmp, 1);
  tmp = (magic & 0xFF00) >> 8;
  write(write_fd, &tmp, 1);
  tmp = (magic & 0xFF);
  write(write_fd, &tmp, 1);
}
