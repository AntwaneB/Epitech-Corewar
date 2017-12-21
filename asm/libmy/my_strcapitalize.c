/*
** my_strcapitalize.c for my_strcapitalize in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 12:41:05 2013 Antoine Buchser
** Last update Mon Oct  7 13:47:35 2013 Antoine Buchser
*/

int	my_isalphanumeric(char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  else if (c >= 'A' && c <= 'Z')
    return (1);
  else if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (i == 0)
	{
	  if (str[i] >= 'a' && str[i] <= 'z')
	    str[i] = str[i] - 32;
	}
      else
	{
	  if (my_isalphanumeric(str[i - 1]) == 0)
	    {
	      if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	      else if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] = str[i] + 32;
	    }
	}
      i = i + 1;
    }
  return (str);
}
