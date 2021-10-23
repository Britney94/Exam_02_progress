/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:52 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/13 19:00:05 by kejebane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(char **line)
{
	size_t		i;
	size_t		reader;
	char		buff[1];

	i = 0;
	reader = read(0, buff, 1);
	if (reader != 0 && rader != -1)



