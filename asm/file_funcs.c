/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 17:31:52 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "op.h"
#include "my.h"
#include "asm.h"

void	my_putchar_fd(int c, int fd)
{
  write(fd, &c, 1);
}

void	my_putstr_fd(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}
