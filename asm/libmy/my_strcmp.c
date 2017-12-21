/*
** my_strcmp.c for my_strcmp in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 09:59:47 2013 Antoine Buchser
** Last update Thu Feb 27 20:56:29 2014 Antoine Buchser
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	check;

  i = 0;
  check = 1;
  while (i < my_strlen(s2) && i < my_strlen(s1) && check == 1)
    {
      if (s1[i] == s2[i])
	check = 1;
      else
	check = 0;
      i = i + 1;
    }
  if (check == 1 && my_strlen(s2) == my_strlen(s1))
    return (0);
  else if (my_strlen(s2) > my_strlen(s1))
    return (s2[i - 1]);
  else if (my_strlen(s1) > my_strlen(s2))
    return (s1[i - 1]);
  else
    return (s1[i - 1] - s2[i - 1]);
}
