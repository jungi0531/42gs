/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:35:58 by juhong            #+#    #+#             */
/*   Updated: 2025/02/03 15:35:49 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_sort(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int	i;

	ft_sort(argc, argv);
	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort(int argc, char *argv[])
{
	int		i;
	int		ii;
	char	*temp;

	temp = "";
	i = 1;
	while (i < argc - 1)
	{
		ii = i + 1;
		while (ii < argc)
		{
			if (ft_strcmp(argv[i], argv[ii]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[ii];
				argv[ii] = temp;
			}
			ii++;
		}
		i++;
	}
}
