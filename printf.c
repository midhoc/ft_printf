#include "ft_printf.h"

void	init_struct(t_ft_printf *tst)
{
	tst->op_mns = 0;
	tst->op_pls = 0;
	tst->op_0 = 0;
	tst->op_sp = 0;
	tst->op_htg = 0;
	tst->width = -1;
	tst->precision= -1;
	tst->length = -1;
	tst->type = -1;
}

int write_format(t_ft_printf *tst, va_list argv)
{
	if (tst->type == 0 || tst->type == 1)
		type_d(tst, argv);
	else if (tst->type == 3)
		type_u(tst, argv);
	else if (tst->type == 7)
		type_s(tst, argv);
	else if (tst->type == 6)
		type_c(tst, argv);
	else if (tst->type == 10)
		type_per(tst, argv);
	else if (tst->type == 9)
		ft_putnbr(va_arg(argv, double));
	else if (tst->type == 2 || tst->type == 11)
		type_o(tst, argv);
	else if (tst->type == 4 || tst->type == 8)
		type_x(tst, argv, 0);
	else if (tst->type == 5)
		type_x(tst, argv, 1);
	return(1);
}

int		ft_printf(const char * str, ... )
 {
	va_list argv;
	t_ft_printf	tst;
	int	c;

	c = 0;
	va_start(argv, str);
	while(*str)
	{
		if (*str == '%')
		{
			init_struct(&tst);
			if(get_format(&(str),&tst))
				write_format(&tst, argv);
			//printf("+ : %d\n- : %d\n' ' : %d\n0 : %d\n# : %d\nw : %d\np : %d\nf : %d\nt : %d\n",
			//tst.op_pls, tst.op_mns, tst.op_sp, tst.op_0, tst.op_htg, tst.width, tst.precision, tst.length, tst.type);

		}
		else
		{
			ft_putchar(*str);
			str++;
		}
	}
	va_end(argv);
	return(1);
 }

// void		get_s_e_m(double f, t_ft_float *flt)
// {
// 	int						i;
// 	unsigned long long int	t;

// 	i = 63;
// 	ft_bzero(flt->t, sizeof(flt->t));
// 	t =  *(unsigned long long int*)&f;
// 	if ((t << (64-(i+1))) >> 63)
// 		flt->sign = 1;
// 	while (--i > 51)
// 	{
// 		flt->exp *= 2;
// 		if ((t << (64-(i+1))) >> 63)
// 			flt->exp++;
// 	}
// 	flt->exp -= 1023;
// 	while (i >= 0)
// 	{
// 	//	printf("%d\n",51 -i);
// 		if ((t << (64-(i+1))) >> 63)
// 			flt->t[51 - i] = 1;
// 		i--;
// 	}
// 	//  for(i = 0; i < 52; i++)
// 	//  	printf("%d : %d\n",51 -i, flt->t[i]);
// 	// ft_putchar('\n');
// 	// ft_putnbr(flt->sign);
// 	// ft_putchar('\n');
// 	// ft_putnbr(flt->exp);
// 	// ft_putchar('\n');
// }

// #include <math.h>//!////////////
// void		izan(t_ft_float *flt, int i, int p_5, unsigned long long int s)
// {
// 	int r;
// 	unsigned long long int k;

// 	r = s % 10;
// 	k = s / 10;
// 	if (--i > 0)
// 	{
// 		k += flt->t[i] * pow(5, i) * pow(2, flt->exp - 1023);
// 		ft_putnbr(r);
// 		izan(flt, i, p_5 * 5, k);
// 	}
// 	else if (i == 0)
// 	{
// 		 k += pow(2, flt->exp - 1023);
// 		ft_putnbr(r);
// 		izan(flt, --i, p_5 * 5, k);
// 	}
// 	printf("\n%llu\n",s);
// }

int main()
{
	int x = 0;
	#define M ("%o", 0);
	// double	k = 1.81;
	// get_s_e_m(k, &t);
	// izan(&t, 52, 5, 0);



	//printf("\n%.100lf",k);
	// unsigned long long int p = 1;
	// for (int i=0; i < 50; i++ )
	// 	printf("%llu\n", p*=5);

//("{%+0.-3d}", 0);
//		"{%+03d}", 0
	// 	"{% 03d}", 0

ft_printf M
printf("\n");
printf M
//ft_putstr(0);
	return(0);
}

