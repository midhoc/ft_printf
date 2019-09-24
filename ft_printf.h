/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:05:21 by hmidoun           #+#    #+#             */
/*   Updated: 2019/09/23 00:19:10 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft/includes/libft.h"

# define H 0
# define L 1
# define J 2
# define Z 3
# define T 4
# define L_ 5
# define HH 6
# define LL 7


typedef struct s_ft_printf
{
	int	op_mns;
	int	op_pls;
	int	op_0;
	int	op_sp;
	int	op_htg;
	int	precision;
	int	width;
	int	type;
	int	length;
}				t_ft_printf;

int		get_width_precision(char **str, t_ft_printf *tst);
int		get_option(char **str, t_ft_printf *tst);
int		get_lengths(char **str, t_ft_printf *tst);
int		get_type(char **str, t_ft_printf *tst);
int		get_format(char **str, t_ft_printf *tst);

int		type_d(t_ft_printf *tst, va_list argv);



int		count_digit_d(t_ft_printf *tst, long long int nbr);
#endif
