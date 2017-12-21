/*
** my_putstr.c for my_putstr in /home/buchse_a/Documents/Piscine-C-Jour_04
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Oct  3 09:57:27 2013 Antoine Buchser
** Last update Wed Oct  9 20:45:06 2013 Antoine Buchser
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
