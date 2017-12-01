/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_page.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:04:13 by mseinic           #+#    #+#             */
/*   Updated: 2017/12/01 14:57:16 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	*new_page(size_t size)
{
	void	*ptr;
    size_t  i;

    i = PAGE_SIZE * size;
    ptr = mmap(0, i, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
    while (i-- > 0)
        ((char*)ptr)[i] = '\0';
    return (ptr);
}
