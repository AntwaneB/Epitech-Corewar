/*
** my_strstr.c for my_strstr in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 09:59:47 2013 Antoine Buchser
** Last update Sun Oct 27 15:46:30 2013 Antoine Buchser
*/

int	my_strcmp2(char *str, char *to_find)
{
  int	i;
  int	check;

  i = 0;
  check = 1;
  while (i < my_strlen(to_find) && check == 1)
    {
      if (str[i] == to_find[i])
	check = 1;
      else
	check = 0;
      i = i + 1;
    }
  return (check);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	check;

  check = 0;
  i = 0;
  while (i < my_strlen(str) && check == 0)
    {
      if (my_strcmp2(str + (i * sizeof(char)), to_find) == 1)
	{
	  return (str + (i * sizeof(char)));
	  check = 1;
	}
      i = i + 1;
    }
  return (0);
}
