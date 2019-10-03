/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 01:05:21 by hmidoun           #+#    #+#             */
/*   Updated: 2019/10/03 02:47:23 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft.h"
# define H 0
# define L 1
# define J 2
# define Z 3
# define T 4
# define L_ 5
# define HH 6
# define LL 7

typedef struct	s_ft_printf
{
	char	buff[1000];
	int		length_buff;
	int		n_buff;
	int		op_mns;
	int		op_pls;
	int		op_0;
	int		op_sp;
	int		op_htg;
	int		precision;
	int		width;
	int		type;
	int		length;
}				t_ft_printf;

int				get_width_precision(char **str, t_ft_printf *tst);
int				get_option(char **str, t_ft_printf *tst);
int				get_lengths(char **str, t_ft_printf *tst);
int				get_type(char **str, t_ft_printf *tst);
int				get_format(char **str, t_ft_printf *tst);

void			type_d(t_ft_printf *tst, va_list argv);
void			put_d(t_ft_printf *tst, long long int nbr);

void			type_u(t_ft_printf *tst, va_list argv);
void			put_u(t_ft_printf *tst, unsigned long long int nbr);

void			type_s(t_ft_printf *tst, va_list argv);
void			type_s_l(t_ft_printf *tst, va_list argv);
void			type_s_op(t_ft_printf *tst, int i, char *c);
void			type_s_op_mns(t_ft_printf *tst, int i, char *c);
void			type_s_l_op(t_ft_printf *tst, int i, int *c);
void			type_s_l_op_mns(t_ft_printf *tst, int i, int *c);

void			type_c(t_ft_printf *tst, va_list argv);
void			type_c_l(t_ft_printf *tst, va_list argv);
void			type_c_(t_ft_printf *tst, va_list argv);
void			type_per(t_ft_printf *tst);

void			type_o(t_ft_printf *tst, va_list argv);
void			put_o(t_ft_printf *tst, unsigned long long int nbr);

void			type_x(t_ft_printf *tst, va_list argv, int flag_up);
void			put_x(t_ft_printf *tst, unsigned long long int nbr,
						int flag_up);

void			ft_putchar_buff(char c, t_ft_printf *tst);
void			ft_print_buff(t_ft_printf *tst);
void			ft_putchar_buff(char c, t_ft_printf *tst);
void			ft_putstr_buf(char const *str, t_ft_printf *tst);
void			ft_putnbr_unsigned_buf(unsigned long long int nb,
										t_ft_printf *tst);

void			type_f(t_ft_printf *tst, va_list argv);
void			put_f(t_ft_printf *tst, long double nbr);
char			*ftoa(long double nbr, int c, t_ft_printf *tst);
void			round_float(t_ft_printf *tst, long double *nbr);
int				count_digit_f(t_ft_printf *tst, long double nbr);
int				put_sign_f(t_ft_printf *tst, long double nbr, int flag);
#endif
