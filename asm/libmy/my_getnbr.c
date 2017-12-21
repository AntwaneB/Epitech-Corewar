/*
** my_getnbr.c for my_getnbr in /home/buchse_a/Documents/Piscine-C-Jour_04
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Oct  3 11:01:01 2013 Antoine Buchser
** Last update Wed Apr  9 13:32:23 2014 Antoine Buchser
*/

int	my_morethanint(char *str, int nb_moins)
{
  char	*max_int;
  int	i;
  int	check;

  max_int = (nb_moins % 2) ? "2147483648" : "2147483647";
  i = 0;
  if (my_nb_lenght_char(str) < 10)
    return (0);
  else if (my_nb_lenght_char(str) == 10)
    {
      check = 1;
      while (i < my_nb_lenght_char(str) && check == 1)
	{
	  if (str[i] > max_int[i])
	    check = 2;
	  else if (str[i] < max_int[i])
	    check = 0;
	  else if (str[i] == max_int[i])
	    check = 1;
	  i = i + 1;
	}
      return ((check < 2) ? 0 : 1);
    }
  else
    return (1);
}

int	my_nb_lenght_char(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= 48 && str[i] <= 58)
    i = i + 1;
  return (i);
}

int	my_nbmoins(char *str)
{
  int	nb_moins;
  int	i;

  nb_moins = 0;
  i = 0;
  while (str[i] == 45 || str[i] == 43)
    {
      if (str[i] == 45)
	nb_moins = nb_moins + 1;
      i = i + 1;
    }
  return (nb_moins);
}

int	my_nbsignes(char *str)
{
  int	i;

  i = 0;
  while (str[i] == '+' || str[i] == '-')
    i = i + 1;
  return (i);
}

long	my_getnbr(char *str)
{
  long	result;
  int	i;
  int	j;
  int	nb_moins;

  result = 0;
  nb_moins = my_nbmoins(str);
  str = str + my_nbsignes(str);
  i = 0;
  while (i < my_nb_lenght_char(str))
    {
      result = result * 10 + str[i] - '0';
      i = i + 1;
    }
  if (nb_moins % 2 != 0)
    result = -result;
  return (result);
}
