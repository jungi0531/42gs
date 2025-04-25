/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:28:08 by juhong            #+#    #+#             */
/*   Updated: 2025/01/26 15:32:52 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

#ifdef TEST

int	main(void)
{
	int	a;
	int	b;

	a = 13;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	return (0);
}

#endif
