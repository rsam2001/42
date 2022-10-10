
#include <unistd.h>

void	minus_number_and_other_stuff(int *nb, int *k, int *nc)
{
	char	minus;

	minus = '-';
	if (*nb < 0)
	{
		write(1, &minus, 1);
		*nb = 0 - *nb;
	}
	*k = 0;
	*nc = *nb;
	while (*nc / 10 >= 1)
	{
		*nc = *nc / 10;
		*k = *k + 1;
	}
	*k = *k - 1;
}

void	writer(int nb, int *i, int k)
{
	int		j;
	char	newline;
	char	final;

	newline = '\n';
	j = 0;
	final = nb % 10 + '0';
	write(1, &final, 1);
	while (j <= k)
	{
		write(1, &i[j], 1);
		j++;
	}
	write(1, &newline, 1);
}

void	ft_putnbr(int nb)
{
	int	j;
	int	k;
	int	nc;
	int	i[10];

	if (nb < -2147483647)
	{
		write (1, "-2147483648", 11);
	}
	else
	{
		minus_number_and_other_stuff(&nb, &k, &nc);
		j = 0;
		while (nb / 10 >= 1)
		{
			i[k - j] = nb % 10 + '0';
			nb = nb / 10;
			j++;
		}
		writer(nb, i, k);
	}
}
/*
int main(void)
{
ft_putnbr(98342938);
}
*/
