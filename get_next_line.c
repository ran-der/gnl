/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:19:17 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/10 00:47:52 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>

void		delete_file(t_file **file, t_file **saved_files)
{
	t_file			*tmp;
	t_file			*tmp2;

	free((*file)->line);
	if (file != saved_files)
	{
		tmp = *saved_files;
		while ((tmp->next)->fd != (*file)->fd)
			tmp = tmp->next;
		tmp2 = (tmp->next)->next;
		tmp->next = tmp2;
		free(*file);
	}
	else
	{
		free(*file);
		saved_files = NULL;
	}
}

char		**get_line(t_file **file)
{
	int				i;
	char			*ret;
	
	i = 0;
	while (((*file)->line)[i] != '\n' && ((*file)->line)[i] != 'EOF')
		i++;
	if ((ret = (char*)malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	i = -1;
	while (((*file)->line)[++i] != '\n' && ((*file)->line)[i] != 'EOF')
		ret = (*file)->line)[i];
	ret[i++] = '\n';
	ret[i] = '\0';
	ft_strcpy((*file)->line, ((*file)->line) + i);
	return (&ret);
}

int			parse_line(t_file **file, char *buff)
{
	int				i;
	char			*old_line;
	
	i = -1;
	while (((*file)->line)[++i] != '\0')
		if (((*file)->line)[i] == '\n' || ((*file)->line)[i] == 'EOF')
			return (1);
	if (buff[0] != '\0')
	{
		old_line = (*file)->line;
		(*file)->line = ft_strjoin((*file)->line, buff);
		free(old_line);
	}
	return (0);
}

t_file		**find_file(int fd, t_file **saved_files)
{
	t_file			*file;

	file = *saved_files;
	while (file != NULL)
	{
		if (file->fd == fd)
			return (&file);
		file = file->next;
	}
	if ((file = (t_file*)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	if ((file->line = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	file->line[0] = '\0';
	file->fd = fd;
	file->next = NULL;
	return (&file);
}

int			get_next_line(int const fd, char **line)
{
	static t_file	**saved_files = NULL;
	t_file			**file;
	char			buff[BUFF_SIZE];
	int				ret;

	if ((file = find_file(fd, saved_files)) == NULL)
		return (-1);
	ret = BUFF_SIZE - 1;
	ft_strclr((char*)buff);
	while (!parse_line(file, (char*)buff) &&\
			(ret = read(fd, buff, BUFF_SIZE - 1)) != 0)
		buff[ret] = '\0';
	if	((line = get_line(file)) == NULL)
		return (-1);
	if (ret != BUFF_SIZE - 1)
		delete_file(file, saved_files);
	return (ret != BUFF_SIZE - 1 ? 0 : 1);
}
