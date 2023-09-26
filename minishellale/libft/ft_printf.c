/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:33:25 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/15 17:36:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printcore(char spec, va_list arguments)
{
	unsigned int	ret_sum_bytes;

	ret_sum_bytes = 0;
	if (spec == '%')
		ret_sum_bytes = ft_printchar('%');
	else if (spec == 'c')
		ret_sum_bytes = ft_printchar(va_arg(arguments, int));
	else if (spec == 's')
		ret_sum_bytes = ft_printstring(va_arg(arguments, char *));
	else if (spec == 'i' || spec == 'd')
		ret_sum_bytes = ft_printnum(va_arg(arguments, int));
	else if (spec == 'x' || spec == 'X')
		ret_sum_bytes = ft_printhexa(va_arg(arguments, long), spec);
	else if (spec == 'p')
		ret_sum_bytes = ft_printpointer(va_arg(arguments, unsigned long long));
	else if (spec == 'u')
		ret_sum_bytes = ft_printundec(va_arg(arguments, unsigned int));
	return (ret_sum_bytes);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		arguments;

	va_start(arguments, format);
	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == ft_chck(format[i + 1]))
			count += ft_printcore(format[i++ + 1], arguments);
		else if (format[i] == '%' && format[i + 1] != ft_chck(format[i + 1]))
		{
			write(1, "Spec Error", 11);
			count = 16;
			return (count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}
/*
int	main(void)
{
//	ft_printf("Print a char: %c.\n", 'c');
//	ft_printf("Print a string: %s.\n", "f13itman: \nCodename 47");
//	ft_printf("Print a positive i: %d.\n", 47);
//	ft_printf("Print a zero i: %d.\n", 0);
//	ft_printf("Print a negative i: %d.\n", -42);
//	ft_printf("Print a lower hex i: %x.\n", 477);
//	ft_printf("Print a UPPER hex: %X.\n", 477);
//	ft_printf("Print a zero hex: %x.\n", 0);
	ft_printf("Print a pointer: %p.\n", 16);
//	ft_printf("Print a %%");
	return (0);
}*/
