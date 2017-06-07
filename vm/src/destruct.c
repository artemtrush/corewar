/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:33:07 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/07 11:33:08 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		destruct(t_data *data)
{

}

void		exit_error(t_data *data)
{
	destruct(data);
	printf("ERROR\n"); // ft_
	exit(0);
}
