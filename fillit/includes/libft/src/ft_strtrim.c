/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnelson <gnelson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:45:57 by gnelson           #+#    #+#             */
/*   Updated: 2019/09/15 23:36:08 by gnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_abort(void)
{
	char	*abort;

	abort = NULL;
	abort = (char*)malloc(sizeof(char) * 1);
	*abort = '\0';
	return (abort);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	unsigned int	i;

	start = 0;
	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_abort());
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i] != '\0')
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i != 0)
		i--;
	i++;
	if (i <= start)
		return (ft_abort());
	len = i - start;
	return (ft_strsub(s, start, len));
}
