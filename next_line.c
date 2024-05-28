#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(const char *src)
{
	if(!src)
		return NULL;
	size_t	len = ft_strlen(src) + 1;
	char	*dst = malloc(len);
	
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len = ft_strlen(s1);
	size_t	s2_len = ft_strlen(s2);
	char	*s = malloc((s1_len + s2_len + 1));

	if (!s1 || !s2)
		return (NULL);
	if (!s)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcpy((s + s1_len), s2);
	free(s1);
	return (s);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *line;
	char  *newLine;
	int endLine;
	int readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return NULL;
	line = ft_strdup(buf);
	while (1)
	{
		if ((newLine = ft_strchr(line, '\n')))
			break;
		if (!(readed = read(fd, buf, BUFFER_SIZE)))
			break;
		if (readed == -1)
			return (free(line), NULL);
		buf[readed] = '\0';
		line = ft_strjoin(line, buf);
		if(!line)
			return NULL;
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return NULL;
	}
	if (newLine)
	{
		endLine = newLine - line + 1;
		ft_strcpy(buf, newLine + 1);
	}else
	{
		endLine = ft_strlen(line);
		buf[0] = '\0';
	}
	line[endLine] = '\0';
	return line;
}
#include <stdio.h>
#include <fcntl.h>
#include <fcntl.h>

void	f()
{
	system("leaks a.out");
}
int main()
{
	// atexit(f);
    int id = open("hello.txt" , O_CREAT, O_RDWR, 0777);
	char *s;

	s = get_next_line(id);
    printf("%s", s);
	free(s);
	s = get_next_line(id);
    printf("%s", s);
	free(s);
	s = get_next_line(id);
    printf("%s", s);
	free(s);
	s = get_next_line(id);
    printf("%s", s);
	free(s);
	s = get_next_line(id);
    printf("%s", s);
	free(s);
	return (0);
}