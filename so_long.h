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

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_char
{
	int		l_x;
	int		l_y;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_cur;
}	t_char;

typedef struct s_map
{
	char	**mappin;
	char	**control;
	int		w;
	int		h;
	int		cb;
	int		gate_x;
	int		gate_y;
	int		p_cnt;
	int		end_cnt;
	int		coin_cnt;
}	t_map;

typedef struct s_win
{
	t_map	*map;
	t_char	*chr;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*block_bg;
	void	*c_bg;
	void	*end_bg;
	int		height;
	int		width;
}	t_win;

int		walk(int keycode, void *param);
void	putchr(t_win *pnc, int keycode);
char	*read_file(char	*path, t_map *map);
t_map	*read_map(char *path);
void	put_element(char c, t_win *pnc, int x, int y);
void	render_map(t_win *pnc);
int		close_frame(void *param);
void	player_control(t_win *pnc);
void	get_img(t_win *pnc, int x, int y);
void	wall_control(t_win *pnc);
void	map_size_control(t_win	*pnc);
void	end_control(t_win *pnc);
void	endln_control(char line);
void	coin_control(t_win *pnc);
void	file_control(char *path);
void	char_control(t_win *pnc);
int		valid(t_win *map);
void	recursive_c(t_win *ret, int y, int x);
int		coin_c(t_win *ret);
int		exit_c(t_win *ret);
void	xpm_control(void);
void	xpm_control_two(void);
void	path_checker(char *path);
void	starend(char **dest, const char *src);
int		close_frame_two(void *param);
void	readmapp(t_win *pnc, char *path);
int		free_map(void *param);

#endif
