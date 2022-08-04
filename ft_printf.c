/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:51 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/04 20:22:54 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converse_char(va_list ap, char c, int *count)
{
	char	*print_str;
	char	print_char;

	if (c == 'c')
	{
		print_char = va_arg(ap, int);
		*count += write(1, &print_char, 1);
	}
	else if (c == 's')
	{
		print_str = strdup(va_arg(ap, char *));
		*count += write(1, print_str, ft_strlen(print_str));
		free(print_str);
	}
	else if (c == 'd' || c == 'i')
	{
		print_str = ft_itoa(va_arg(ap, int));
		*count += write(1, print_str, ft_strlen(print_str));
		free(print_str);
	}
	return (0);
}

int	ft_printf(const char *ar, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, ar);
	while (ar[i])
	{
		if (ar[i] != '%')
			write(1, ar, ft_strlen(ar));
		else if (ar[++i])
			converse_char(ap, ar[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}

int main()
{
	char p_c = 'a';
	char p_s[] = "hi my name is jeongyun\n";
	int p_i = 2147483647;
	int	hex = 100;
	int count;

	count = ft_printf("%c%d%s", 'a', p_i, p_s);
	printf("ft: %d\n", count);
	count = printf("%c%d%s", 'a', p_i, p_s);
	printf("or: %d\n", count);
	return (0);
}

/* 
int vout(int max, ...);
 
int main(void)
{
	vout(2, "Sat", "Sun");
	printf("\n");
	vout(3, "Mon", "Tues", "Wed");
	printf("hello world!\n");
	ft_printf("hello world!\n");
	return (0);
}
 
int vout(int max, ...)
{
   va_list arg_ptr;
   int args;
   char *day;
   va_start(arg_ptr, max);
   args = 0;
   while(args < max)
   {
      day = va_arg(arg_ptr, char *);
      printf("Day: %s\n", day);
      args++;
   }
   va_end(arg_ptr);
   return (0);
}
*/
