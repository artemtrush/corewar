/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:32:25 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/07 11:32:26 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_data(t_data *data)
{
	data->dump_arg = -2; // init to -2, -1 = error
	data->map = NULL;
	data->cycle = 0;
	data->num_of_proc = 0;
	data->cycle_to_die = CYCLE_TO_DIE;
	data->players = NULL;
	data->processes = NULL;
}
