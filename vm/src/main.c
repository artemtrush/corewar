/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:22:14 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/05 19:22:15 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_usage(void)
{
	ft_printf("usage:\n./corewar [-dump nbr_cycles] \
	[[-n number] champion1.cor] ...\n");
}

int			ft_atoi_ptv(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		if (res > 214748364 || (res == 214748364 && str[i] >= '8'))
			return (-1);
		res = res * 10 + str[i] - '0';
		++i;
	}
	return (res);
}



void		read_dump_arg(t_data *data, char *av)
{	
	if (av)
		data->dump_arg = ft_atoi_ptv(av);
	if (data->dump_arg == -1)
	{
		ft_usage();
		exit(1);
	}	
}


void		read_flags(t_data *data, char **av, int ar)
{
	int		i;

	i = 0;
	while (++i < ar)
	{
		if (*av[i] == '-')
		{
			if (!ft_strcmp("-dump", av[i]))
			{
				ft_printf("zawlo!\n");
				read_dump_arg(data, av[i + 1]);
			}
		}
	}
}



int			main(int ar, char **av)
{

	t_data data;

	if (ar > 1)
	{
		init_data(&data);
		read_flags(&data, av, ar);
	}
	else
		ft_usage();
	return (0);
}
