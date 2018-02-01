int		strstart(char *str, char *start)
{
	int		i;

	i = 0;
	while(str[i] && start[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	if (start[i])
		return (0);
	return (1);
}