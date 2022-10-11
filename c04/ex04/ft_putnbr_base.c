#include <unistd.h>
void	writer(char s)
{
	write(1, &s, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	error_base(char *str)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[0] == '\0' || len == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);

}
void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	error;

	error = error_base(base);
	len = ft_strlen(base);
	if (error == 1)
	{
		if (nbr < 0)
		{
			writer('-');
			nbr *= -1;
		}
		if (nbr < len)
			writer(base[nbr]);
		if (nbr >= len)
		{
			ft_putnbr_base(nbr / len, base);
			ft_putnbr_base(nbr % len, base);
		}
	}
}

int main()
{
	ft_putnbr_base(64, "0123456789abcdef");
	return 0;
}
