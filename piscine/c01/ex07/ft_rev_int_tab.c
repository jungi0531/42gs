/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:59:05 by juhong            #+#    #+#             */
/*   Updated: 2025/01/26 17:13:36 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

#ifdef TEST

int	main(void)
{
	int	array[6];
	int	i;

	i = 0;
	while (i < 6)
	{
		array[i] = i + 1;
		i++;
	}
	ft_rev_int_tab(array, 6);
	return (0);
}

#endif
