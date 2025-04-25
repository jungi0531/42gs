/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:14:42 by juhong            #+#    #+#             */
/*   Updated: 2025/01/27 18:12:40 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	ii;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		ii = i + 1;
		while (ii < size)
		{
			if (tab[i] > tab[ii])
			{
				temp = tab[i];
				tab[i] = tab[ii];
				tab[ii] = temp;
			}
			ii++;
		}
		i++;
	}
}

#ifdef TEST

int	main(void)
{
	int	array[5];

	array[0] = 3;
	array[1] = 4;
	array[2] = 1;
	array[3] = 5;
	array[4] = 2;
	ft_sort_int_tab(array, 5);
	return (0);
}

#endif
