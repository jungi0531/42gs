/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:24:27 by juhong            #+#    #+#             */
/*   Updated: 2025/01/26 15:27:48 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#ifdef TEST

int	main(void)
{
	int	div;
	int	mod;

	div = 0;
	mod = 0;
	ft_div_mod(13, 5, &div, &mod);
	return (0);
}

#endif
