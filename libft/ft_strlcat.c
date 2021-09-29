/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkawahar <tkawahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:47:10 by tkawahar          #+#    #+#             */
/*   Updated: 2020/07/03 11:24:30 by tkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t cat_space;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	cat_space = dstsize - dst_len;
	if (cat_space == 0)
		return (dst_len + src_len);
	else if (dst_len > dstsize)
		return (dstsize + src_len);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && cat_space != 1)
	{
		*dst++ = *src++;
		cat_space--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
