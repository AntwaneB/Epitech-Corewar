/*
** mysh_wordtab.c for minishell1 in /home/schoch_h/Projets/minishell1
** 
** Made by SCHOCH Hugo
** Login   <schoch_h@epitech.net>
** 
** Started on  Tue Dec 17 15:16:58 2013 SCHOCH Hugo
** Last update Thu Apr 10 12:22:09 2014 Thomas MORITZ
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

static int	is_lim_sh(char c, char *lim)
{
  int		pos;

  pos = 0;
  while (lim[pos] != '\0')
    {
      if (c == lim[pos])
	return (1);
      else
	pos = pos + 1;
    }
  return (0);
}


static int	cp_str_to_tab_sh(char *str, char *word, int length, char *lim)
{
  static int	position = 0;
  int		pos_word;

  if (length == -1)
    {
      position = 0;
      length = -length;
      return (0);
    }
  pos_word = 0;
  while (position < length)
    {
      word[pos_word] = str[position];
      position = position + 1;
      pos_word = pos_word + 1;
    }
  word[pos_word] = '\0';
  while (is_lim_sh(str[position], lim))
    position = position + 1;
  word = word + 1;
  return (position);
}

static int	check_str_sh(char *str, char *lim)
{
  int		position;
  int		words;
  int		length;

  position = 0;
  words = 0;
  length = my_strlen(str);
  while (position < length)
    {
      if (is_lim_sh(str[position], lim))
	words = words + 1;
      position = position + 1;
    }
  words = words + 1;
  cp_str_to_tab_sh(NULL, NULL, -1, NULL);
  return (words);
}

char	**my_explode(char *str, char *lim)
{
  char	**res;
  int	total_words;
  int	word;
  int	length;
  int	pos;

  word = -1;
  length = 0;
  pos = 0;
  total_words = check_str_sh(str, lim);
  if ((res = malloc((total_words + 1) * sizeof(char**))) == NULL)
    return (0);
  while (word++ < total_words && length < my_strlen(str))
    {
      while (str[length] != '\0' && str[length] != '\n'
	     && !is_lim_sh(str[length], lim))
	length = length + 1;
      if ((res[word] = malloc((length - pos + 1) * sizeof(char))) == NULL)
	return (0);
      pos = cp_str_to_tab_sh(str, res[word], length, lim);
      while (is_lim_sh(str[length], lim))
	length = length + 1;
    }
  res[total_words] = '\0';
  return (res);
}
