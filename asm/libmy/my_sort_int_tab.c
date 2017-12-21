/*
** my_sort_int_tab.c for my_sort_int_tab in /home/buchse_a/Documents/Piscine-C-Jour_04
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Oct  3 11:18:41 2013 Antoine Buchser
** Last update Wed Oct  9 21:30:01 2013 Antoine Buchser
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	case_actuelle;
  int	tmp;

  case_actuelle = 0;
  while (case_actuelle < size)
    {
      i = 1;
      while (case_actuelle + i <= size)
	{
	  if (tab[case_actuelle + i] < tab[case_actuelle])
	    {
	      tmp = tab[case_actuelle];
	      tab[case_actuelle] = tab[case_actuelle + i];
	      tab[case_actuelle + i] = tmp;
	    }
	  i = i + 1;
	}
      case_actuelle = case_actuelle + 1;
    }
}
