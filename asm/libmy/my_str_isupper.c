/*
** my_str_isupper.c for my_str_isupper in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 12:41:05 2013 Antoine Buchser
** Last update Sun Oct 27 15:40:35 2013 Antoine Buchser
*/

int	my_str_isupper(char *str)
{
  int	i;
  int	check;

  if (str[0] != '\0')
    {
      i = 0;
      check = 1;
      while (str[i] && check == 1)
	{
	  if (str[i] >= 'A' && str[i] <= 'Z')
	    check = 1;
	  else
	    check = 0;
	  i = i + 1;
	}
      return (check);
    }
  else
    return (1);
}
