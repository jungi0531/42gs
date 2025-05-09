/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhong <juhong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:09:21 by juhong            #+#    #+#             */
/*   Updated: 2025/05/01 14:37:13 by juhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_conversion(char type, va_list args);
void	ft_print_char(char c, int *count);
void	ft_print_str(char *s, int *count);
void	ft_print_nbr(int n, int *count);
void	ft_print_unsigned(unsigned int n, int *count);
void	ft_print_hex(unsigned int n, int upper, int *count);
void	ft_print_ptr(uintptr_t ptr, int *count);

#endif
