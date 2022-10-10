/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-e <rcosta-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:49:04 by rcosta-e          #+#    #+#             */
/*   Updated: 2022/10/10 10:51:41 by rcosta-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i < n && && !j && s1[i] != '\0' && s2[i] != '\0')
	{
		j = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (i < n && !j && (s1[i] == '\0' || s2[i] == '\0'))
		j = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (j);
}
