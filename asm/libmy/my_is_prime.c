/*
** my_is_prime.c for my_is_prime in /home/buchse_a/Documents/Piscine-C-Jour_05
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Fri Oct  4 15:37:25 2013 Antoine Buchser
** Last update Wed Oct  9 21:33:45 2013 Antoine Buchser
*/

int	my_is_prime(int nb)
{
  int	nb_check;
  int	is_prime;

  if (nb < 2)
    return (0);
  else
    {
      nb_check = 2;
      is_prime = 1;
      while (nb_check < nb)
	{
	  if (nb % nb_check == 0)
	    is_prime = 0;
	  nb_check = nb_check + 1;
	}
      return (is_prime);
    }
}
