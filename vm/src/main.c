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
	ft_printf(USAGE);
	exit(1);
}

static void		read_dump_arg(t_data *data, char *av)
{	
	if (av && data->dump_arg == -2)
	{
		if ((data->dump_arg = ft_atoi_ptv(av)) == -1)
			ft_usage();
	}
	else
	{
		ft_usage();
	}
}

/*
**	read_flags() -- read flags from all $valid_position in STDIN
**	read $flags_arguments followed by $valid_position
*/

void		read_flags(t_data *data, char **av, int ar, int *i)
{
	if (!ft_strcmp("-dump", av[*i])) // read -dump flag + dump_arg
	{
		read_dump_arg(data, av[++(*i)]);
	}
	else if (('1' < av[*i][1] && av[*i][1] < '4') && (av[*i][2] == '\0'))
	{
		read_player(data, av[*i], ft_atoi(av[*i]));
		//read_player(data, av[*i], ft_atoi(av[++(*i)])); how we should read [-n number]?
	}
	else
		ft_usage(); // if flag shitfull
}

void		read_args(t_data *data, char **av, int ar)
{
	int		i;

	i = 1;
	while (i < ar)
	{
		if (av[i][0] == '-')
		{
			read_flags(data, av, ar, &i);
		}
		else
			read_player(data, av[i], -1); //
		++i;
	}
}

int			main(int ar, char **av)
{
	t_data data;

	if (ar > 1)
	{
		init_data(&data);
		read_args(&data, av, ar);
	}
	else
		ft_usage();
	return (0);
}
