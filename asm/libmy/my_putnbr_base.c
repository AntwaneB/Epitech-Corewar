/*
** my_putnbr_base.c for my_putnbr_base in /home/buchse_a/Documents/Piscine-C-Jour_06
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Mon Oct  7 17:06:27 2013 Antoine Buchser
** Last update Wed Apr  9 13:52:17 2014 Antoine Buchser
*/

void	my_put_zeros(int nbr)
{
  if (nbr == 0)
    my_putstr("00");
  else if (nbr < 16)
    my_putchar('0');
}

int	my_putnbr_base(int nbr, char *base)
{
  int	result[10];
  int	i;

  if (nbr < 0)
    {
      nbr = -nbr;
      my_putchar('-');
    }
  i = 0;
  if (!my_strcmp(base, "0123456789abcdef")
      || !my_strcmp(base, "0123456789ABCDEF"))
    my_put_zeros(nbr);
  while (nbr != 0)
    {
      result[i] = nbr % my_strlen(base);
      nbr = nbr / my_strlen(base);
      i = i + 1;
    }
  i = i - 1;
  while (i >= 0)
    {
      my_putchar(base[result[i]]);
      i = i - 1;
    }
}
