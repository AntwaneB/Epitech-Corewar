/*
** my_strcat.c for my_strcat in /home/buchse_a/Documents/Piscine-C-Jour_07/ex_01
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Oct  8 09:59:31 2013 Antoine Buchser
** Last update Thu Feb 13 17:15:56 2014 Antoine Buchser
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  while (dest[j])
    j++;
  i = 0;
  while (src[i])
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
