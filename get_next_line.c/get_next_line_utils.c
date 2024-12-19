#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}


char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if(!s)
		return (NULL);
	while(s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
		str[i++] = s1[i];
	while(s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s1)] = '\0';
	free(s1);
	return (str);
}
