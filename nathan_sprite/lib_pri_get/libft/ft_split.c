/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndziadzi <ndziadzi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:26:59 by ndziadzi          #+#    #+#             */
/*   Updated: 2024/10/14 15:40:08 by ndziadzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	f_index(const char *s, char c, size_t index)
{
	while (s[index] != '\0')
	{
		if (s[index] == c)
			return (index);
		index++;
	}
	return (index);
}

static size_t	string_c(char const *s, char c)
{
	size_t		cc;
	size_t		strings;

	cc = 0;
	strings = 0;
	while (s[cc] != '\0')
	{
		while (s[cc] == c && s[cc] != '\0')
			cc++;
		if (s[cc] != c && s[cc] != '\0')
			strings++;
		while (s[cc] != c && s[cc] != '\0')
			cc++;
	}
	return (strings);
}

static char	**loop_logic(char **array, char const *s, char c, size_t cc)
{
	size_t	created;

	created = 0;
	while (s[cc] != '\0')
	{
		while (s[cc] == c && s[cc] != '\0')
			cc++;
		if (s[cc] != '\0' && s[cc] != c)
		{
			array[created] = ft_substr(s, cc, f_index(s, c, cc) - cc);
			if (array[created] == NULL)
			{
				while (created > 0)
					free (array[--created]);
				free (array);
				return (NULL);
			}
			created++;
			cc = f_index(s, c, cc);
		}
	}
	array[created] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	cc;
	size_t	s_count;
	char	**array;

	cc = 0;
	if (s == NULL)
		return (NULL);
	s_count = string_c(s, c);
	array = (char **)ft_calloc(s_count + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (loop_logic(array, s, c, cc) == NULL)
		return (NULL);
	return (array);
}

// int main(void)
// {
//  	char *s = "      split       this for   me  !       ";
//  	char **result = ft_split(s, ' ');
// 	size_t n = 0;
// 	while (n < ft_strlen(*result))
// 	{
// 		printf("'%s'\n", result[n]);
// 		n++;
// 	}
// 	free (result);
// 	return (0);
// }