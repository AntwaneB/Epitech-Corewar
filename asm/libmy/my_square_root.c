/*
** my_square_root.c for my_square_root in /home/buchse_a/Documents/Piscine-C-Jour_05
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Fri Oct  4 15:33:33 2013 Antoine Buchser
** Last update Fri Oct  4 16:11:30 2013 Antoine Buchser
*/

int	my_square_root(int nb)
{
  int	nb_check;
  int	result_is_int;

  result_is_int = 0;
  nb_check = 1;
  while (nb_check <= nb || result_is_int == 1)
    {
      if (nb_check * nb_check == nb)
	{
	  result_is_int == 1;
	  return (nb_check);
	}
      nb_check = nb_check + 1;
    }
  if (result_is_int == 0)
    return (0);
}
