/*
** main.c for Coreouar in /home/buchse_a/Documents/CPE_2014_Corewar/ASM
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Mar 11 13:00:18 2014 Antoine Buchser
** Last update Thu Apr 10 23:01:39 2014 Antoine Buchser
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

char	*get_comment_str(t_line *line)
{
  int	linelen;
  int	i;
  char	*dest;

  linelen = 0;
  i = 0;
  while (line->wordtab[++i])
    linelen += my_strlen(line->wordtab[i]);
  if ((dest = malloc((linelen + 1) * sizeof(*dest))) == NULL)
    return (NULL);
  dest[0] = '\0';
  i = 0;
  while (line->wordtab[++i])
    my_strcat(dest, line->wordtab[i]);
  return (dest);
}

int		comment_is_valid(t_asm *core)
{
  t_line	*tmp;
  int		found;
  char		*line;

  found = 0;
  tmp = core->content;
  while (tmp && !found)
    {
      if (tmp->wordtab != NULL && tmp->wordtab[0] != NULL
	  && !my_strcmp(tmp->wordtab[0], COMMENT_CMD_STRING))
	found = 1;
      tmp = (!found) ? tmp->next : tmp;
    }
  line = (found == 1) ? get_comment_str(tmp) : NULL;
  if (found && line != NULL && tmp->wordtab[1] != NULL && my_strlen(line) > 2
      && line[0] == '"' && line[my_strlen(line) - 1] == '"')
    {
      if (my_strlen(line) - 2 > COMMENT_LENGTH)
	my_putstr("Warning: The comment of your champion"
		  " is too long, it will be truncated.\n");
      free(line);
      return (1);
    }
  return ((found == 1) ? 0 : 1);
}
