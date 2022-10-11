int	ft_iterative_factorial(int nb)
{
	unsigned int factorial;

	factorial = 1;
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	if (nb < 0)
	{
		return (0);
	}
	return (factorial);
}
