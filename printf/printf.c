/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kejebane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:55:28 by kejebane          #+#    #+#             */
/*   Updated: 2021/10/15 19:29:11 by kejebane         ###   ########.fr       */
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
	flags->period = 0;
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
		

char	*save_width(t_Flags *flags, char *s, int *j)
{
	int		i;

	i = 0;
	while (is_in(s[i], "0123456789") == 1)
		i++;
	res  = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (is_in(s[*j], "0123456789") == 1)
		res[i++] = s[*j++];
	res = '\0';
	return (res);
}

int		flag_assign(t_Flags *flags, char *s, int *i)
{
//	int		i;
	int		current;
	char	*width_str;

//	i = 0;
	while (is_in(s[*i], ".0123456789") == 1
			&& is_in(s[*i], "sdx") == 0)
	{
		width_str = save_width(flags, s + *i, i);
		flags->width = ft_atoi(width_str);
		if (s[*i] == '.')
		{
			flags.period == 1;
			*i++;
		}
		free(width_str);
		width_str = save_width(flags, s + *i, i);
		flags->prcision = ft_atoi(width_str);
		free(width_str);
		*i++;
	}
	if (is_in(s[*i], "sdx") == 1)
		flags->format_id = s[*i];
	return (0);
}

int		wyd_all(va_list va, t_Flags *flags)
{
	int		q;

	q = 0;
	if (flags->format_id == 's')
	{
		str = va_arg(va, char *);
		while (str[q])
			write(1, &str[q++], 1);
	}
//	if (flags->format_id == 'x')
//	if (flags->format_id == 'd')
	return (0);
}

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
			flags_init(&flags);
			flag_assign(&flags, s + i, &i);
			wyd_all(va, &flags);
			//WIDTH AND PRECISION PROCESSING MISSING
		}
		else
			ft_putchar(s[i]);
		i++;
	}
	return (0);
}
