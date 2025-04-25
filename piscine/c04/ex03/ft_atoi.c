/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:42:43 by juhong            #+#    #+#             */
/*   Updated: 2025/02/11 20:25:43 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 0;
	result = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (minus % 2 == 1)
		return (-result);
	return (result);
}

#ifdef TEST

int	main(int argc, char *argv[])
{
	(void)argc;
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}

#endif
