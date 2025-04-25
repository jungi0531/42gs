/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:46:25 by juhong            #+#    #+#             */
/*   Updated: 2025/03/29 13:16:16 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int		i;
	char	c;

	c = 'a';
	i = 0;
	while (i < 26)
	{
		ft_putchar(c);
		c++;
		i++;
	}
}

#ifdef TEST

int	main(void)
{
	ft_print_alphabet();
	return (0);
}

#endif
