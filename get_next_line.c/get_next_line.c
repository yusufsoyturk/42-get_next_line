#include "get_next_line.h"

char	*ft_write_line(char *letter)
{
	char *line;
	int	i;

	i = 0;
	if (!letter)
		return (NULL);
	while (letter[i] != '\0' || letter[i] != "\n")
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (letter[i] != '\0' || letter[i] != "\n")
	{
		line[i] = letter[i];
		i++;
	}
	return (line);
}
char	*ft_after_line(char *letter)
{
	char	*after_line;
	int		i;
	int 	j;

	j = 0;
	i = 0;
	if (!letter)
		return (NULL);
	while (letter[i] != '\0' || letter[i] != "\n")
		i++;
	i++;
	after_line = malloc(sizeof(char) * (letter - i + 1));
	if (!after_line)
		return (NULL);
	while (letter[i] != '\0')
	{
		after_line[j] == letter[i];
		i++;
		j++;
	}
	after_line[j + 1] = '\0';
	return (after_line);
}

char	*ft_read_fd(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	bytes = 1;
	tmp = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	while(!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char *str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_fd(fd, str);
	if (!str)
		return (NULL);
	line = ft_write_line(str);
	str = ft_after_line(str);
	return (line);
}