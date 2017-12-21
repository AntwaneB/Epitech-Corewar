/*
** my_put_nbr_rec.c for my_put_nbr in /home/buchse_a/Documents/Piscine-C-Jour_03
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Sun Oct  6 13:37:49 2013 Antoine Buchser
** Last update Mon Nov  4 10:36:38 2013 Antoine Buchser
*/

int	my_put_unnbr_rec(unsigned int nb, int tmp, int puissance)
{
  if (puissance > 0)
    {
      tmp = ((nb / puissance) % 10);
      tmp = tmp + '0';
      my_putchar(tmp);
      my_put_unnbr_rec(nb, 0, (puissance / 10));
    }
  return (0);
}

int	my_put_unnbr(unsigned int nb)
{
  int	tmp;
  int	puissance;
  int	i;

  puissance = 1;
  while ((nb / puissance) >= 10)
    puissance = puissance * 10;
  my_put_unnbr_rec(nb, 0, puissance);
  return (0);
}
