/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseinic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:38:42 by mseinic           #+#    #+#             */
/*   Updated: 2017/12/01 14:48:25 by mseinic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int main(void)
{
    int *tt;

    tt = (int *)malloc(1 * sizeof(int));
    printf("size = [%d]\nstatus = [%d]\nptr = [%p]\n",*tt , *(tt + 1), (tt));
	printf("t_data size = [%d]\n", sizeof(t_data));
	return (0);
}
