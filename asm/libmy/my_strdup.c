/*
** my_strdup.c for my_strdup in /home/buchse_a/Documents/Piscine-C-Jour_08
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  9 10:10:44 2013 Antoine Buchser
** Last update Thu Dec 12 15:22:01 2013 Antoine Buchser
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  dest = malloc((my_strlen(src) + 1) * sizeof(*dest));
  if (dest == NULL)
    return (NULL);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
