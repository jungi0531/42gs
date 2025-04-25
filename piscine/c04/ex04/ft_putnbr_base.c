/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:27 by juhong            #+#    #+#             */
/*   Updated: 2025/01/30 17:06:07 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		check_invalid_base(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = check_invalid_base(base);
	if (i == 0)
		return ;
	if (nbr == -2147483648)
	{
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base(-nbr, base);
	}
	else
	{
		if (nbr / i != 0)
			ft_putnbr_base(nbr / i, base);
		write(1, &base[nbr % i], 1);
	}
}

int	check_invalid_base(char *base)
{
	int	i;
	int	temp;
	int	count[150];

	i = 0;
	while (i < 150)
		count[i++] = 0;
	i = 0;
	while (base[i])
	{
		temp = base[i];
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (count[temp] != 0)
			return (0);
		count[temp]++;
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

#ifdef TEST

int	main(void)
{
	ft_putnbr_base(42, "poneyvif");
	return (0);
}

#endif
