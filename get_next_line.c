/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:19:17 by rvan-der          #+#    #+#             */
/*   Updated: 2016/04/25 19:40:05 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>
//#include <sys/syslimits.h>
#include <stdio.h>

char		*get_line(char **line)
{
	int				i;
	char			*ret;

	ret = NULL;
	if (*line != NULL)
	{
		//printf("get_line: line = %s\n", *line);
		i = 0;
		while ((*line)[i] != '\n' && (*line)[i] != 26 && (*line)[i] != '\0')
			i++;
		if ((ret = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
			return (NULL);
		i = -1;
		while ((*line)[++i] != '\n' && (*line)[i] != 26 && (*line)[i] != '\0')
			ret[i] = (*line)[i];
		ret[i] = '\0';
		//printf("get_line: ret = %s\n", ret);
		if ((*line)[i] != '\0')
			*line = ft_strcpy(*line, (*line) + i + 1);
		else
			ft_strclr(*line);
		//printf("after cpy: line = %s\n", *line);
	}
	return (ret);
}

int			parse_line(char **line, char *buff)
{
	int				i;
	char			*old_line;

	//printf("parse: line = %s\n", *line);
	if (buff[0] != '\0')
	{
		//printf("join: buff = %s\n", buff);
		old_line = *line;
		*line = ft_strjoin(*line, buff);
		//printf("joined: line = %s\n", *line);
		free(old_line);
	}
	i = -1;
	while ((*line)[++i] != '\0')
		if ((*line)[i] == '\n' || (*line)[i] == 26)
			return (1);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char		*saved_files[500];
	char			buff[BUFF_SIZE];
	int				ret;

	if (fd == -1)
		return (-1);
	if (saved_files[fd] == NULL)
	{
		//printf("alloc\n");
		if ((saved_files[fd] = (char*)malloc(sizeof(char))) == NULL)
			return (-1);
		saved_files[fd][0] = '\0';
	}
	ft_strclr((char*)buff);
	while (!parse_line(&(saved_files[fd]), (char*)buff) &&\
			(ret = read(fd, buff, BUFF_SIZE - 1)) != 0)
		buff[ret] = '\0';
	if ((*line = get_line((&saved_files[fd]))) == NULL)
		return (-1);
	if (ret != BUFF_SIZE - 1 && saved_files[fd][0] == '\0')
	{
		free(saved_files[fd]);
		saved_files[fd] = NULL;
		return (0);
	}
	return (1);
}
