/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:10:02 by juhong            #+#    #+#             */
/*   Updated: 2025/01/28 15:26:37 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
void	ft_upperlower(char *str, int i, int *capitalizing);
int		ft_char_is_numeric(char c);
int		ft_char_is_alpha(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	capitalizing;

	i = 0;
	capitalizing = 1;
	while (str[i])
	{
		if (ft_char_is_alpha(str[i]))
		{
			while (ft_char_is_alpha(str[i]))
				ft_upperlower(str, i++, &capitalizing);
			capitalizing = 1;
		}
		else if (ft_char_is_numeric(str[i]))
		{
			while (ft_char_is_numeric(str[i]))
				i++;
			capitalizing = 0;
			if (ft_char_is_alpha(str[i]) == 0)
				capitalizing = 1;
		}
		else
			i++;
	}
	return (str);
}

void	ft_upperlower(char *str, int i, int *capitalizing)
{
	if (*capitalizing == 1)
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] -= 32;
		(*capitalizing) = 0;
	}
	else if (*capitalizing == 0 && ('A' <= str[i] && str[i] <= 'Z'))
	{
		str[i] += 32;
	}
}

int	ft_char_is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_char_is_alpha(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

#ifdef TEST

int	main(void)
{
	return (0);
}

#endif
