/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:27:53 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/05 19:27:54 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*		allowed function:
**		open
**		read
**		lseek
**		write
**		close
**		malloc
**		realloc
**		free
**		perror
**		strerror
**		exit
*/

/* DO LIST:
** init 
**
**
*/

#include <../../libft/inc/libft.h>
#include <../../ft_printf/ft_printf.h>
#include <../../inc/op.h>




typedef struct	s_data
{
	int 		flags_dump;
	int			dump_arg;
		
}				t_data;

void			init_data(t_data *data);
void			destruct(t_data *data);
