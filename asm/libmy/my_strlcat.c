/*
** my_strlcat.c for my_strlcat in /home/buchse_a/Documents/Piscine-C-Jour_07/ex_01
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Oct  8 09:59:31 2013 Antoine Buchser
** Last update Sun Oct 27 15:41:24 2013 Antoine Buchser
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;
  char	*segfault;

  if (size > my_strlen(dest))
    *segfault = *segfault;
  else
    return (my_strlen(size) - my_strlen(dest) - 1);
}
