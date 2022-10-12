/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:42:51 by jeseo             #+#    #+#             */
/*   Updated: 2022/10/07 19:52:06 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	print_char(char c, int *ret)
{
	*ret += write(1, &c, 1);
}

void	print_string(char *str, int *ret)
{
	while (*str !='\0')
	{
		*ret += write(1, str, 1);
		str++;
	}
}

void	recursive_print(long long num, int binary, int *ret, char conversion)
{
	char	p_num;

	if (num < binary)
	{
		if (num > 9)
			p_num = 'a' + num - 10;
		else
			p_num = num + '0';
		if (conversion == 'X')
			p_num -= 32;
		*ret += write(1, &p_num, 1);
	}
	else
	{
		recursive_print(num / binary, binary, ret, conversion);
		recursive_print(num % binary, binary, ret, conversion);
	}
}

void	print_hex(long long	p, int *ret, char conversion)
{
	if (conversion == 'p')
		*ret += write(1, "0x", 2);
	recursive_print(p, 16, ret, conversion);
}

int	converse(char conversion, va_list ap, int *ret)
{
	if (conversion == 'c')
		print_char(va_arg(ap, int), ret);
	else if (conversion == 's')
		print_string(va_arg(ap, char *), ret);
	else if (conversion == 'p')
		print_hex(va_arg(ap, long long), ret, conversion);
	else if (conversion == 'i' || conversion == 'd')
		recursive_print(va_arg(ap, int), 10, ret, conversion);
	else if (conversion == 'x' || conversion == 'X')
		print_hex(va_arg(ap, int), ret, conversion);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		ret; // 리턴은 write() 반환 값을 담아 줄 것이다.
	va_list	ap;
	char	print_char;

	va_start(ap, format);
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			converse(*format, ap, &ret);
			format++;
		}
		ret += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (ret);
}

int main()
{
	char *s = "hihi";
	int a, b;

	a = printf("printf\nc = %s\np = %p\nint: %d/%x/%X\n", s, s, 10, 10, 10);
	b = ft_printf("printf\nc = %s\np = %p\nint: %d/%x/%X\n", s, s, 10, 10, 10);
	printf("ori: %d\nmy: %d\n", a, b);
	return (0);
}
