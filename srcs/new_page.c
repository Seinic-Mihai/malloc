/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_page.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:04:13 by mseinic           #+#    #+#             */
/*   Updated: 2017/11/23 20:13:37 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void	*new_page(size_t size)
{
	void	*ptr;

	ptr = mmap(0, PAGE_SIZE * size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	return (ptr);
}
