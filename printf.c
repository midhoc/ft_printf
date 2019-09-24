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
	int c;

	c = va_arg(argv, int);
	ft_putnbr(c);
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
			//printf("\n******************\n");
			init_struct(&tst);
			if(get_format(&(str),&tst))
				type_d(&tst, argv);
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

int main()
{
	#define M "{%010d}", 42

//		"{%+03d}", 0
	// 	"{% 03d}", 0
	//ft_putnbr(LONG_MAX);
	//ft_printf("%p\n",190,16);
	//ft_printf("%ld\n%d\n", 214748364700, 15);
// ft_putnbr(printf("{%#+d}", 0));
// ft_putnbr(printf("{%++d}", 0));
// ft_putnbr(printf("{%-+d}", 0));
// ft_putnbr(printf("{% +d}", 0));
// ft_putnbr(printf("{%0+d}", 0));
//ft_printf("%s\n",25,"11111\066666",5);
//printf("%lld\n%lld\n", LONG_MIN + 1, LONG_MAX );
//ft_putnbr((short int)2147483647);
ft_printf(M);
printf("\n");
printf(M);
	// ft_printf("%d\n",19.5);
	// ft_printf("%d\n",19.5);
	// ft_printf("%d\n",19.5);
	// ft_printf("%d\n",19.5);
	// ft_printf("%d\n",19.5);
	return(0);
}
