/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 22:20:49 2014 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"
#include "my.h"
#include "asm.h"

int	create_output(char *filename)
{
  int	fd;
  char	*dest;

  dest = my_concat(filename, ".cor");
  if ((fd = open(dest, O_CREAT | O_WRONLY | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    my_error(COULDNT_CREATE_FILE);
  free(dest);
  return (fd);
}

void	start_asm(t_asm *core)
{
  int	pos;

  core->size = 0;
  core->labels = NULL;
  if ((pos = file_content_is_valid(core)) != -1
      && validate_labels(core) != -1)
    {
      core->writefd = create_output(core->filename);
      write_magic_number(core);
      write_program_name(core);
      write_program_size(core);
      write_program_comment(core);
      write_program_content(core);
      close(core->writefd);
    }
  else
    my_putstr("\nErrors have been encountered, exiting.\n");
}

void	read_file_content(t_asm *core)
{
  char	*line;
  char	*tmp;

  while ((line = get_next_line(core->readfd)))
    {
      tmp = remove_space(line);
      content_put_in_list(&(core->content), my_str_to_wordtab(tmp));
      free(line);
      free(tmp);
    }
}

void	init_core_struct(t_asm *core, int fd, char *filename)
{
  core->readfd = fd;
  core->filename = filename;
  core->content = NULL;
  read_file_content(core);
}

int	main(int ac, char **av)
{
  int	i;
  int	fd;
  t_asm	core;

  i = 1;
  while (i < ac)
    {
      if ((fd = usable_file(av[i])) != -1)
	{
	  init_core_struct(&core, fd,
			   my_strndup(av[i], my_strlen(av[i]) - 2));
	  my_printf("Compiling file: %s:\n", av[i]);
	  start_asm(&core);
	  close(fd);
	}
      else
	my_error(FILE_NOT_READABLE);
      i++;
    }
  if (ac == 1)
    my_putstr("usage: ./asm file_name[.s]\n");
  return (EXIT_SUCCESS);
}
