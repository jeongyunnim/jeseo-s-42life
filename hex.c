void print_hex(long long n, int flag)
{
	char	hex[16];
	char	c;
	int		i;

	i = 0;
	if (n < 16)
	{
		if (n < 10)
			c = n + '0';
		else
			c = n - 10 + 'a';
		write(1, &c, 1);
	}
	else
	{
		print_hex(n / 16, flag);
		print_hex(n % 16, flag);
	}
}

char	*htoa(long long hex, int flag)
{
	size_t	len;
	long long	temp;
	char	*ret;

	temp = hex;
	len = 0;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * len + 3);
	if (ret == NULL)
		return (NULL);
	ret[0] = '0';
	ret[1] = 'x';
	ret[len + 1] = '\0';
	while (len > 0)
	{
		if ((hex % 16) < 10)
			ret[len + 1] = (hex % 16) + '0';
		else
			ret[len + 1] = (hex % 16) - 10 + 'a';
		hex /= 16;
		len--;
	}
	return (ret);
}
