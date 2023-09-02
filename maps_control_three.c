/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ultils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zalkan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:02:04 by zalkan            #+#    #+#             */
/*   Updated: 2023/02/18 16:02:06 by zalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_control(void)
{
	int	fd_back;
	int	fd_bg;
	int	fd_block;
	int	fd_coin;

	fd_back = open("./img/back_char.xpm", O_RDWR);
	fd_bg = open("./img/bg.xpm", O_RDWR);
	fd_block = open("./img/block.xpm", O_RDWR);
	fd_coin = open("./img/coin.xpm", O_RDWR);
	if (fd_back <= 0 || fd_bg <= 0 || fd_block <= 0 || fd_coin <= 0)
	{
		ft_printf("XPM dosyası açılamadı\n");
		close(fd_back);
		close(fd_bg);
		close(fd_block);
		close(fd_coin);
		system("leaks so_long");
		exit(1);
	}
	close(fd_back);
	close(fd_bg);
	close(fd_block);
	close(fd_coin);
}

void	xpm_control_two(void)
{
	int	fd_endgate;
	int	fd_front;
	int	fd_left;
	int	fd_right;

	fd_endgate = open("./img/endgate.xpm", O_RDWR);
	fd_front = open("./img/front_char.xpm", O_RDWR);
	fd_left = open("./img/left_char.xpm", O_RDWR);
	fd_right = open("./img/right_char.xpm", O_RDWR);
	if (fd_endgate <= 0 || fd_front <= 0 || fd_left <= 0 || fd_right <= 0)
	{
		ft_printf("XPM dosyası acilamadi\n");
		close(fd_endgate);
		close(fd_front);
		close(fd_left);
		close(fd_right);
		system("leaks so_long");
		exit(1);
	}
	close(fd_endgate);
	close(fd_front);
	close(fd_left);
	close(fd_right);
}

void	path_checker(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e'
		|| path[len - 3] != 'b' || path[len - 4] != '.')
	{
		ft_printf(".ber hatası\n");
		system("leaks so_long");
		exit(1);
	}
}

void	starend(char **dest, const char *src)
{
	char	*new_str;
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;

	if (*dest == NULL)
		*dest = ft_strdup(src);
	else
	{
		dest_len = ft_strlen(*dest);
		src_len = ft_strlen(src);
		total_len = dest_len + src_len;
		new_str = (char *)malloc(total_len + 1);
		if (new_str)
		{
			ft_strlcpy(new_str, *dest, total_len + 1);
			ft_strlcat(new_str, src, total_len + 1);
			free(*dest);
			*dest = new_str;
		}
	}
}
