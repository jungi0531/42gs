/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:12:37 by juhong            #+#    #+#             */
/*   Updated: 2025/01/27 21:37:38 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif
