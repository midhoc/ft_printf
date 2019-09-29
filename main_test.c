// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_test.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/05/06 11:00:38 by vmanzoni          #+#    #+#             */
// /*   Updated: 2019/09/26 15:54:40 by hmidoun          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "ft_printf.h"

// void	compare_printf()
// {
// 	char buf[2048];

// 	ft_printf("-----------------------------------COMPARE FT_PRINTF----------------------------------}\n\n");
// 	ft_printf("			PRINTF		|	FT_PRINTF\n");
// 	ft_printf("--------------------------------------------------------------------------------------}\n");

// 	ft_printf("-blabla-:");
// 	sprintf(buf, "		{blabla}");
// 	ft_printf("%s		{blabla}\n", buf);

// 	ft_printf("noflag:");
// 	sprintf(buf, "			{%%}");
// 	ft_printf("%s			{%%}\n", buf);

// //	ft_printf("flag_h:");
// //	sprintf(buf, "			{%h}");
// //	ft_printf("%s			{%h}\n", buf);

// 	ft_printf("%%c:");
// 	sprintf(buf, "			{%c}", 'A');
// 	ft_printf("%s			{%c}\n", buf, 'A');

// 	ft_printf("%%s:");
// 	sprintf(buf, "			{%s}", "azerty");
// 	ft_printf("%s		{%s}\n", buf, "azerty");

// 	ft_printf("%%d:");
// 	sprintf(buf, "			{%d}", 123);
// 	ft_printf("%s			{%d}\n", buf, 123);

// 	ft_printf("2_char:");
// 	sprintf(buf, "			{%c}{%c}", 'A', 'B');
// 	ft_printf("%s			{%c}{%c}\n", buf, 'A', 'B');

// 	ft_printf("1_char wc (10):");
// 	sprintf(buf, "		{%10c}", 'A');
// 	ft_printf("%s		{%10c}\n", buf, 'A');

// 	ft_printf("2_int:");
// 	sprintf(buf, "			{%d{%d}", 123, 456);
// 	ft_printf("%s		{%d{%d}\n", buf, 123, 456);

// 	ft_printf("2_float:");
// 	sprintf(buf, "		{%f{%f}", 3.1415, 1.23);
// 	ft_printf("%s	{%f{%f}\n", buf, 3.1415, 1.23);

// 	ft_printf("2_str:");
// 	sprintf(buf, "			{%s{%s}", "123", "456");
// 	ft_printf("%s		{%s{%s}\n", buf, "123", "456");

// 	ft_printf("1int_1str:");
// 	sprintf(buf, "		{%d{%s}", 123, "456");
// 	ft_printf("%s		{%d{%s}\n", buf, 123, "456");

// 	ft_printf("1str_1int:");
// 	sprintf(buf, "		{%s{%d}", "123", 456);
// 	ft_printf("%s		{%s{%d}\n", buf, "123", 456);

// 	ft_printf("return value:");
// 	sprintf(buf, "	{%d}", sprintf(buf, "Test"));
// 	ft_printf("%s			{%d}\n", buf, ft_printf("Test"));

// 	ft_printf("wildcard (10):");
// 	sprintf(buf, "		{%*s}", 10, "spaces");
// 	ft_printf("%s		{%*s}\n", buf, 10, "spaces");

// 	ft_printf("wildcard_left (11):");
// 	sprintf(buf, "	{%-*s}", 11, "spaces");
// 	ft_printf("%s		{%-*s}\n", buf, 11, "spaces");

// 	ft_printf("wildcard int (12):");
// 	sprintf(buf, "	{%*d}", 12, 123);
// 	ft_printf("%s		{%*d}\n", buf, 12, 123);

// 	ft_printf("wildcard V2 (13):");
// 	sprintf(buf, "	{%13d}", 123);
// 	ft_printf("%s		{%13d}\n", buf, 123);

// 	ft_printf("precision:");
// 	sprintf(buf, "		{%-15.4f}", 3.141592);
// 	ft_printf("%s	{%-15.4f}\n", buf, 3.141592);

// 	ft_printf("%%05d :");
// 	sprintf(buf, "			{%05d}", 123);
// 	ft_printf("%s			{%05d}\n", buf, 123);

// 	ft_printf("%%5d :");
// 	sprintf(buf, "			{%5d}", 123);
// 	ft_printf("%s			{%5d}\n", buf, 123);

// 	ft_printf("%%+5d :");
// 	sprintf(buf, "			{%+5d}", 123);
// 	ft_printf("%s			{%+5d}\n", buf, 123);

// 	ft_printf("%% 5d:");
// 	sprintf(buf, "			{% 5d}", 123);
// 	ft_printf("%s			{% 5d}\n", buf, 123);

// 	ft_printf("%%+5d :");
// 	sprintf(buf, "			{%+5d}", 123);
// 	ft_printf("%s			{%+5d}\n", buf, 123);

// 	ft_printf("%%+05d :");
// 	sprintf(buf, "			{%+05d}", -123);
// 	ft_printf("%s			{%+05d}\n", buf, -123);

// 	ft_printf("%%d :");
// 	sprintf(buf, "			{%d}", -123);
// 	ft_printf("%s			{%d}\n", buf, -123);

// 	ft_printf("%%+05d :");
// 	sprintf(buf, "			{%+05d}", 123);
// 	ft_printf("%s			{%+05d}\n", buf, 123);

// 	ft_printf("%%.4d :");
// 	sprintf(buf, "			{%.4d}", 1/3);
// 	ft_printf("%s			{%.4d}\n", buf, 1/3);

// 	ft_printf("%%3.4f :");
// 	sprintf(buf, "			{%3.4f}", 1.23456789);
// 	ft_printf("%s			{%3.4f}\n", buf, 1.23456789);

// 	ft_printf("%%3.4f :");
// 	sprintf(buf, "			{%3.4f}", 1234.56789);
// 	ft_printf("%s			{%3.4f}\n", buf, 1234.56789);

// 	ft_printf("%%+.3f :");
// 	sprintf(buf, "			{%+.3f}", 2.5);
// 	ft_printf("%s			{%+.3f}\n", buf, 2.5);

// 	ft_printf("bugged:");
// 	sprintf(buf, "			{%%s}");
// 	ft_printf("%s			{%%s}\n", buf);

// 	ft_printf("\n\n-------------------------------------TEST FT_PRINTF------------------------------------}\n\n");

// 	ft_printf("%%.3e:");
// 	sprintf(buf, "			{%.3e}", 3.141592);
// 	ft_printf("%s		{%.3e}\n", buf, 3.141592);
// }

// int		main(/*int ac, char **av*/)
// {
// 	compare_printf();
// 	return (0);
// }
