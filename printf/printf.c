/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:55:28 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/15 18:00:53 by kejebane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_Flags t_Flags;
struct s_Flags
{
	int		width;
	int		precision;
	int		period;
	char	format_id;
};

int		is_in(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		flag_init(t_Flags *flags)
{
	flags->width = 0;
	flags->periodd = 0;
	flags->precision = 0;
	flags->format_id = 0;
}

int		ft_atoi(char *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res);
}
		

char	*save_width(t_Flags *flags, char *s)
{
	int		i;

	i = 0;
	while (is_in(s[i], "0123456789") == 1)
		i++;
	res  = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (is_in(s[i], "0123456789") == 1)
	{
		res[i] = s[i];
		i++;
	}
	res = '\0';
	flags->width = ft_atoi(res);
	return (res);
}

int		flag_init(t_Flags *flag, char *s)
{
	int		i;
	int		current;

	i = 0;
	while (is_in(s[i], ".0123456789") == 1
			&& is_in(s[i], "sdx") == 0)
	{
		save_width(flags, s);
		//ICI
		




int		ft_printf(const char *s, ...)
{
	int			i;
	va_list		va;
	int			count;
	t_Flags		flags;

	i = 0;
	va_start(va, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			flag_init(&flags, s + i);
