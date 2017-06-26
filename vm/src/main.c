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

static void		ft_usage(t_data *data)
{
	ft_printf(USAGE);
	//TODO free the malloced players if any
	exit(1);
}

static void		read_dump_arg(t_data *data, char *str)
{	
	if (str && data->dump_arg == -2)
	{
		if ((data->dump_arg = ft_atoi_ptv(str)) == -1)
		{
			ft_usage(data);
		}
	}
	else
	{
		ft_usage(data);
	}
}

/*
**	read_flags() -- read flags from all $valid_position in STDIN
**	read $flags_arguments followed by $valid_position
*/

static void		read_flags(t_data *data, char **av, int ar, int *i)
{
	if (!ft_strcmp("-dump", av[*i])) // read -dump flag + dump_arg
	{
		++(*i);
		read_dump_arg(data, av[*i]);
	}
	else if (!ft_strcmp("-n", av[*i]))
	{
		++(*i);
		if (av[*i] && ('1' <= av[*i][0] && av[*i][0] <= '4') && (av[*i][1] == '\0'))
		{
			++(*i);
			read_player(data, av[*i], ft_atoi(av[(*i) - 1]));
		}
		else
		{
			ft_usage(data); // if flag invalid
		}
	}
	else if (!ft_strcmp("-v", av[*i]))
	{
		if (data->visual_flag == 0)
		{
			++(*i);
			data->visual_flag = 1;
		}
		else
		{
			ft_usage(data);
		}
	}
	else
	{
		ft_usage(data); // if flag invalid
	}
}

static void		read_args(t_data *data, char **av, int ar)
{
	int			i;

	i = 1;
	while (i < ar)
	{
		if (av[i][0] == '-')
		{
			read_flags(data, av, ar, &i);
		}
		else
		{
			read_player(data, av[i], -1); //
		}
		++i;
	}
	//TODO sort linked list of players
}

int				main(int argc, char **argv)
{
	t_data		data;
	
	if (argc > 1)
	{
		init_data(&data);
		read_args(&data, argv, argc);
		//TODOcreate linked list of processes
		// if (data.players == NULL || data.processes == NULL)  //TODO if struct with players is null, give usage
		// {
		// 	ft_usage(&data);
		// }
		start(&data);
	}
	else
	{
		ft_usage(&data);
	}
	return (0);
}
