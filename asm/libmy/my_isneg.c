/*
** my_isneg.c for my_isneg in /home/buchse_a/Documents/Piscine-C-Jour_03
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Wed Oct  2 13:00:31 2013 Antoine Buchser
** Last update Wed Oct  2 17:11:58 2013 Antoine Buchser
*/

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
}
