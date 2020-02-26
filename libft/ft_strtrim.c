/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:15:04 by jandre            #+#    #+#             */
/*   Updated: 2019/11/04 18:14:14 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_match(const char a, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_matchbegin(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	if (!(ft_match(s1[i], set)))
		return (0);
	while (ft_match(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_matchend(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	if (!(ft_match(s1[i], set)))
		return (ft_strlen(s1));
	while (ft_match(s1[i], set))
		i--;
	return (i + 1);
}

static size_t	ft_lenmatch(const char *s1, const char *set)
{
	if (ft_matchbegin(s1, set) && (ft_matchbegin(s1, set) != ft_strlen(s1)))
		return (ft_matchend(s1, set) - ft_matchbegin(s1, set));
	else if (ft_matchbegin(s1, set))
		return (ft_strlen(s1 + ft_matchbegin(s1, set)));
	else if (ft_matchend(s1, set))
		return (ft_matchend(s1, set));
	else
		return (ft_strlen(s1));
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(char) * (ft_lenmatch(s1, set) + 1))))
		return (NULL);
	i = ft_matchbegin(s1, set);
	j = 0;
	while (j < ft_lenmatch(s1, set))
	{
		result[j] = s1[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}
