/*
** my_strncat.c for my_strncat in /home/buchse_a/Documents/Piscine-C-Jour_07/ex_01
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Oct  8 09:59:31 2013 Antoine Buchser
** Last update Tue Oct  8 11:56:01 2013 Antoine Buchser
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  while (dest[0] != '\0')
    {
      dest = dest + 1;
      j = j + 1;
    }
  i = 0;
  while (i < nb)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i + 1] = '\0';
  dest = dest - j;
  return (dest);
}
