/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 15:24:11 by rvan-der          #+#    #+#             */
/*   Updated: 2016/03/04 16:06:27 by rvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_word(char const *str, char c, int pos)
{
	while (str[pos] != '\0' && str[pos] == c)
		pos++;
	return (pos);
}

static int		word_length(char const *str, char c, int pos)
{
	int			i;
	int			j;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
			{
				i++;
				j++;
			}
			if (count == pos - 1)
				return (j);
		}
		else
			while (str[i] != '\0' && str[i] == c)
				i++;
	}
	return (-1);
}

static int		count_words(char const *str, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			while (str[i] != '\0' && str[i] == c)
				i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**words;
	int			wds;
	int			i;
	int			j;
	int			k;

	wds = count_words(s, c);
	if ((words = (char**)malloc(sizeof(char*) * (wds + 1))) == NULL)
		return (NULL);
	i = -1;
	k = 0;
	while (++i < wds)
	{
		if ((words[i] = (char*)malloc(sizeof(char) * \
				(word_length(s, c, i) + 1))) == NULL)
			return (NULL);
		k = find_word(s, c, k) - 1;
		j = -1;
		while (s[++k] != '\0' && s[k] != c)
			words[i][++j] = s[k];
		words[i][++j] = '\0';
	}
	words[i] = NULL;
	return (words);
}
