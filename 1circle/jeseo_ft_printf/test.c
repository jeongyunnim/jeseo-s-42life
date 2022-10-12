#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

// int	what_is_va_arg(char *a, ...)
// {
// 	va_list	ap;
// 	int		i;

// 	i = 0;
// 	va_start(ap, a);
// 	while (a[i])
// 	{
// 		if(a[i] != '%')
// 			write(1, &a[i], 1);
// 		else if (a[++i])
// 		{
// 			char c = va_arg(ap, int) + '0';
// 			write(1, &c, 1);
// 		}
// 		i++;
// 	}
// 	return (i);
//}

int main()
{
	// what_is_va_arg("is it right?%d%d%d%d%s\n", 2, 3, 4, 5, "string");
	int a;
	void *b;

	printf("%llx\n", (unsigned long long)-1);
	printf("%p", (void *)ULONG_MAX);
	return (0);
}
