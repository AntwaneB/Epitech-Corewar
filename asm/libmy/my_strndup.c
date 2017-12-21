/*
** my_strdup.c for my_strdup in /home/buchse_a/Documents/Piscine-C-Jour_08
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  9 10:10:44 2013 Antoine Buchser
** Last update Thu Feb 13 15:50:11 2014 Antoine Buchser
*/

#include <stdlib.h>

char	*my_strndup(char *src, int len)
{
  char	*dest;
  int	i;

  dest = malloc((len + 1) * sizeof(*dest));
  if (dest == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0' && i < len)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
