/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:31:11 by ochayche          #+#    #+#             */
/*   Updated: 2017/06/14 20:31:12 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint		big_to_little_endian(uint n)
{
    uint     res;
    res = 0;
    res = res | (n >> 24);
    res = res & 255;
    res = res | ((n >> 8) & 65280);
    res = res | (n << 24);
    res = res | ((n << 8) & 16711680);
    return (res);
}

int			check_magic(int fd)
{
    ssize_t err;
    uint     magic;
    err = read(fd, &magic, 4);//mozhno perepisat` dlya int != 4, poka tak nadezhney
	if (err == -1 || err != 4)
	{
		return (0);
	}
	printf("magic before %x\n", magic);//TODO
	magic = big_to_little_endian(magic);
	printf("magic after %x\n", magic);//TODO
	if (magic != COREWAR_EXEC_MAGIC)
	{
		printf("magic FAIL!!\n");//TODO
	    return (0);
	}
	printf("magic OK!!\n");//TODO
	return (1);
}

void		open_error(t_data *data, char *str)
{
	ft_printf("Can't read source file %s\n", str);
	//TODO free everything correctly: other players and their content
	exit(2);
}


static char		*cut_string(char *buf)
{
	char *str;

	str = ft_strdup(buf);
	if (str == NULL)
	{
		return (NULL);
	}
	return (str);
}

char		*read_name(int fd)
{
	char 		*buf;
	char		*name;
	ssize_t 	err;
	
	buf = ft_strnew(PROG_NAME_LENGTH);
	if (buf == NULL)
	{
		return (NULL);
	}
	err = read(fd, buf, PROG_NAME_LENGTH);
	if (err == -1 || err != PROG_NAME_LENGTH)
	{
		ft_strdel(&buf);
		return (NULL);
	}
	lseek(fd, sizeof(char) * 4, SEEK_CUR);
/* verbose  ************************************/
	printf("read == %zd\n", err);
	printf("name == [%s]\n", buf);
/* ******************************************* */
	name = cut_string(buf);
	ft_strdel(&buf);
	return (name);
}


int			read_size(int fd)
{
	int		prog_size;
	int		err;
	
	err = read(fd, &prog_size, 4);//mozhno perepisat` dlya int != 4, poka tak nadezhney
	if (err == -1 || err != 4)
	{
		return (-1);
	}
	prog_size = big_to_little_endian(prog_size);


/* verbose ************************************  */
	printf("size prog [%d]\n", prog_size);
/* ********************************************* */


	return (prog_size);
}

char		*read_comment(int fd)
{
	char 		*buf;
	ssize_t 	err;	
	char		*comment;

	buf = ft_strnew(COMMENT_LENGTH);
	if (buf == NULL)
	{
		return (NULL);
	}
	err = read(fd, buf, COMMENT_LENGTH);
	if (err == -1 || err != COMMENT_LENGTH)
	{
		ft_strdel(&buf);
		return (NULL);
	}
	lseek(fd, sizeof(char) * 4, SEEK_CUR);



/* verbose *******************************/
	printf("read == %zd\n", err);
	printf("comment == [%s]\n", buf);
/*****************************************/	

	comment = cut_string(buf);
	ft_strdel(&buf);
	return (comment);
}


char		*read_byte_code(int fd, int prog_size, char *str)
{
	int		err;
	char	*buf;

	printf("allocated %d byte\n", prog_size);
	buf = ft_strnew((size_t)prog_size + 1);
	
	err = read(fd, buf, prog_size + 1);
	printf("err = %d\n", err);
	if (err == -1 || prog_size > CHAMP_MAX_SIZE)
	{
		ft_strdel(&buf); //init buf to NULL
	}
	else if (err != prog_size )
	{
		ft_strdel(&buf); //init buf to NULL
		ft_printf("Error: File %s has a code size that differs from what its header says\n", str); //TODO mske to ft_printf
	}	
/* verbose ********************************************************/
	if (buf)
	{
		for (int i = 0; i < prog_size ; ++i)
		{
			printf("%02x ", ((uchar *)buf)[i]);
		}
		printf("\n");
	}
/*****************************************************************/
	return (buf);
}

t_player	*malloc_player_node(int n)
{
	t_player *tmp;

	tmp = (t_player *)malloc(sizeof(t_player));
	if (tmp == NULL)
	{
		return (NULL);
	}
	tmp->player_id = n - 1;
	tmp->alive = 0;
	tmp->name = NULL;
	tmp->prog_size = 0;
	tmp->comment = NULL;
	tmp->last_live = 0;
	tmp->lives_in_curr = 0;
	tmp->byte_code = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	read_player(t_data *data, char *str, int n)
{
	int fd;
	t_player *node;
	int prog_size;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		open_error(data, str);
	}
	node = malloc_player_node(n);
	if (node == NULL)
	{
		ft_printf("Not enough memory\n");
		//TODO free everything correctly: other players and their content
		exit(2);
	}
	if (!check_magic(fd) || !(node->name = read_name(fd))
	 || ((node->prog_size = read_size(fd)) == -1) || !(node->comment = read_comment(fd))
	 || !(node->byte_code = (uchar *)read_byte_code(fd, node->prog_size, str)))
	{
		printf("ERROR INVALID_player\n");//TODO
		//free everything in the node
		//free everything in the list of players
		exit(1);
	}
	else
	{
		printf("valid_player\n");
	}
	
	if (data->players != NULL)
	{
		node->next = data->players;
	}
	data->players = node;

	close(fd);
}
