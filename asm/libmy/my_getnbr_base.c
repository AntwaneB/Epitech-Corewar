/*
** my_getnbr_base.c for my_getnbr_base in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  9 17:26:44 2013 Antoine Buchser
** Last update Thu Nov  7 13:44:54 2013 Antoine Buchser
*/

int	get_pos_b(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
        return (i);
      i = i + 1;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	result;
  int	baselength;
  int	strlength;
  int	fact;

  if (str[0] == '-')
    return (-my_getnbr_base(str + 1, base));
  fact = 1;
  baselength = my_strlen(base);
  strlength = my_strlen(str) - 1;
  result = 0;
  while (strlength >= 0)
    {
      result = result + get_pos_b(str[strlength], base) * fact;
      fact = baselength * fact;
      strlength = strlength - 1;
    }
  return (result);
}
