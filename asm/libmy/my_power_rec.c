/*
** my_power_rec.c for my_power_rec in /home/buchse_a/Documents/Piscine-C-Jour_05
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Fri Oct  4 11:30:34 2013 Antoine Buchser
** Last update Fri Oct 11 16:37:49 2013 Antoine Buchser
*/

int	call_my_power_rec(int nb, int result, int power)
{
  if (power > 1)
    call_my_power_rec(nb, result * nb, power - 1);
  else
    return (result);
}

int	my_power_rec(int nb, int power)
{
  int	tmp;

  tmp = nb;
  if (power > 1)
    return (call_my_power_rec(nb, nb, power));
  else if (power == 0)
    return (1);
  else
    return (0);
}
