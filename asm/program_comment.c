/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Fri Apr 11 12:23:59 2014 Antoine Buchser
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

static char	*get_comment_str(t_line *line)
{
  int		linelen;
  int		i;
  char		*dest;

  linelen = 0;
  i = 0;
  while (line->wordtab[++i])
    linelen += my_strlen(line->wordtab[i]);
  if ((dest = malloc((linelen + 1 + count_tab(line->wordtab))
		     * sizeof(*dest))) == NULL)
    return (NULL);
  dest[0] = '\0';
  i = 0;
  while (line->wordtab[++i])
    {
      my_strcat(dest, line->wordtab[i]);
      if (i + 1 != count_tab(line->wordtab))
	my_strcat(dest, " ");
    }
  return (dest);
}

char		*get_comment(t_asm *core)
{
  int		found;
  t_line	*tmp;
  char		*comment;

  tmp = core->content;
  found = 0;
  while (tmp && found == 0)
    {
      if (!my_strcmp(tmp->wordtab[0], COMMENT_CMD_STRING))
	found = 1;
      if (my_strcmp(tmp->wordtab[0], COMMENT_CMD_STRING))
	tmp = tmp->next;
    }
  if (found == 1)
    {
      comment = get_comment_str(tmp) + 1;
      comment[my_strlen(comment) - 1] = '\0';
    }
  return ((found == 1) ? comment : NULL);
}

void	write_program_comment(t_asm *core)
{
  char	*comment;
  int	i;

  comment = get_comment(core);
  if (my_strlen(comment) <= COMMENT_LENGTH)
    my_putstr_fd(comment, core->writefd);
  else
    {
      comment[COMMENT_LENGTH - 1] = '\0';
      my_putstr_fd(comment, core->writefd);
    }
  i = 0;
  while (i < COMMENT_LENGTH + 1 - my_strlen(comment))
    {
      my_putchar_fd('\0', core->writefd);
      i++;
    }
  my_putstr("\t");
  my_putstr(comment);
  my_putchar('\n');
}
