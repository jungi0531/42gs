/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:54:32 by juhong            #+#    #+#             */
/*   Updated: 2025/02/07 20:14:37 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *src);
int					ft_strlen(char *str);

#ifdef TEST

int	main(int ac, char *av[])
{
	int					i;
	struct s_stock_str	*temp;

	temp = ft_strs_to_tab(ac - 1, av + 1);
	i = 0;
	while (i < ac - 1)
	{
		printf("%s\n", temp[i].str);
		printf("%d\n", temp[i].size);
		printf("%s\n", temp[i].copy);
		i++;
	}
	return (0);
}

#endif

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*temp;

	temp = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		temp[i].str = av[i];
		temp[i].size = ft_strlen(av[i]);
		temp[i].copy = ft_strdup(av[i]);
		i++;
	}
	temp[i].str = NULL;
	return (temp);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = 0;
	return (temp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
