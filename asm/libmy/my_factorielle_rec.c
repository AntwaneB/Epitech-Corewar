/*
** my_factorielle_rec.c for my_factorielle_rec in /home/buchse_a/Documents/Piscine-C-Jour_05
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Fri Oct  4 09:41:21 2013 Antoine Buchser
** Last update Wed Oct  9 21:33:13 2013 Antoine Buchser
*/

int	my_factorielle_rec(int nb)
{
  if (nb > 1 && nb < 13)
    return (my_factorielle_rec(nb - 1) * nb);
  else if (nb == 1)
    return (1);
  else
    return (0);
}
