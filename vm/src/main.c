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


/*
**	read_flags() -- read flags from all $valid_position in STDIN
**	read arguments followed by $valid_position
*/

void		read_flags(t_data *data, char **av, int ar)
{
	int		i;

	i = 1;
	while (i < ar)
	{
		if (av[i][0] == '-')
		{
			if (!ft_strcmp("-dump", av[i]))
			{
				ft_printf("zawlo!\n"); //dell
				read_dump_arg(data, av[i + 1]);
			}
		}
		// else  // dell
		// {
		// 	exit_error();
		// }
		++i;
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
	else /// @todo: print usage if flag is shitfull
		ft_usage();
	return (0);
}
