#include "./includes/ft_printf.h"
int main()
{
	//double x = 0.15555555556858;

	#define M ("%U", 4294967296)
	// double	k = 1.81;
	// get_s_e_m(k, &t);
	// izan(&t, 52, 5, 0);
// 	printf("%.55f\n",x);
// for(int i = 0 ; i < 10; i++)
// 	printf("%.55f\n", x *= (float)10);

	//printf("\n%.100lf",k);
	// unsigned long long int p = 1;
	// for (int i=0; i < 50; i++ )
	// 	printf("%llu\n", p*=5);

//("{%+0.-3d}", 0);
//		"{%+03d}", 0
	// 	"{% 03d}", 0

 int c = ft_printf M;
 printf("\n");
int i = printf M;

printf("\n%d\t%d\n",c ,i);
//ft_putstr(0);
	return(0);
}
