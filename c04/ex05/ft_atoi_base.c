#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	error_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void    get_number(char *str, char *number)
{
        char    sign;
        int     i;
        int     countsign;

        i = 0;
        countsign = 0;
        while (*str >= 9 && *str <= 13 || *str == ' ')
                str++;
        while (*str == '+' || *str == '-')
        {
                if (*str == '-')
                        countsign += 1;
                str++;
        }
        if (countsign % 2 != 0)
        {
                number[0] = '-';
                i = 1;
        }
        while (*str != '\0')
        {
                number[i] = *str;
                i++;
                str++;
        }
        number[i] = '\0';
}

int	ft_atoi_base(char *str, char *base)
{
	int		nb;
	int		i;
	int		j;
	char	final[15];
	int		error;

	nb = 0;
	j = 0;
	get_number(str, final);
	error = error_base(base);
	if (error == 1)
	{
		while (final[j] != '\0')
		{
			i = 0;
			while (base[i] != '\0')
			{
				if (final[j] == base[i])
				nb = nb * ft_strlen(base) + i ;
				i++;
			}
			j++;
		} 
	}
	else
		return (0);
	return (nb);
}
#include <stdio.h>
int main()
{
	int a = ft_atoi_base("	\n   --1000000", "01");
	printf("%d", a);
}
