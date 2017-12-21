/*
** sum_params.c for sum_params in /home/buchse_a/Documents/Piscine-C-Jour_08/ex_03
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  9 10:36:07 2013 Antoine Buchser
** Last update Sun Oct 27 19:45:06 2013 Antoine Buchser
*/

#include <stdlib.h>

char	*sum_params(int argc, char **argv)
{
  int	size;
  int	i;
  char	*dest;

  i = 0;
  size = 0;
  while (i < argc)
    {
      size = size + my_strlen(argv[i]) + 1;
      i = i + 1;
    }
  dest = malloc(size * sizeof(char));
  if (dest == NULL)
    return (0);
  i = 0;
  size = 0;
  while (i < argc)
    {
      my_strcpy(dest + size, argv[i]);
      size = size + my_strlen(argv[i]) + 1;
      my_strcpy(dest + size - 1, "\n");
      i = i + 1;
    }
  dest[size - 1] = '\0';
  return (dest);
}
