/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <hjg020531@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:40:47 by juhong            #+#    #+#             */
/*   Updated: 2025/02/05 20:55:36 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG	"I have an odd number of arguments.\n"
# define EVEN(nbr) (nbr % 2 == 0)

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
