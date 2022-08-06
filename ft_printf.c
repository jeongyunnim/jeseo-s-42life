/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:51 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/06 16:10:13 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ptoa(void *ptr, int flag)
{
	unsigned long long	casting_ptr;

	casting_ptr = (unsigned long long)ptr;
	return (ft_htoa(casting_ptr, flag));
}

static int	converse_char(va_list ap, int c, int *count)
{
	char	*print_str;
	char	print_char;

	print_str = 0;
	if (c == 'c')
	{
		print_char = va_arg(ap, int);
		*count += write(1, &print_char, 1);
		return (0);
	}
	else if (c == 's')
		print_str = ft_strdup(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		print_str = ft_itoa(va_arg(ap, int));
	else if (c == 'x' || c == 'X' || c == 'p')
		print_str = ft_htoa(va_arg(ap, int), c);
	else if (c == 'p')
		print_str = ft_ptoa(va_arg(ap, void *), 'x');
	if (print_str == NULL)
		return (-1);
	*count += write(1, print_str, ft_strlen(print_str));
	free(print_str);
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
			count += write(1, ar, ft_strlen(ar));
		else if (ar[++i] != '%')
		{
			if (converse_char(ap, ar[i], &count) != 0)
				return (write(2, "-1", 2));
		}
		else
			count += write(1, "%", 1);
		i++;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// 	char p_c = 'a';
// 	char p_s[] = "hi my name is jeongyun\n";
// 	int p_i = 0x17;
// 	int	hex = 100;
// 	int count;

// 	count = ft_printf("%%%c%i%s%p", 'a', 017, p_s, p_s);
// 	printf("ft: %d\n", count);
// 	count = printf("%%%c%d%s%p", 'a', 017, p_s, p_s);
// 	printf("or: %d\n", count);
// 	return (0);
// }

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
