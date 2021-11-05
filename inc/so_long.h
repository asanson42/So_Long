/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:17 by asanson           #+#    #+#             */
/*   Updated: 2021/10/29 17:19:51 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <math.h>

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <fcntl.h>

# define BUFFER_SIZE 32

# define MLX_ERROR 1

/*
# define WIN_W 1280
# define WIN_H 720
*/

# define WIN_W 1920
# define WIN_H 1080

# define TEX_W 64
# define TEX_H 64

# define ORANGE_PIX 0xFF8000
# define BLUE_PIX 0x0000FF
# define WHITE_PIX 0xFFFFFF
# define GREEN_PIX 0xFF00 
# define RED_PIX 0xFF0000
# define BLACK_PIX 0x000000

typedef struct s_set
{
	int	player;
	int	exit;
}			t_set;

typedef struct s_sprite
{
	int		sp;
	int		*x;
	int		*y;
}			t_sprite;

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	t_sprite	sprite;
	t_set		set;
}			t_map;

typedef struct s_img
{
	void	*p;
	char	*ad;
	int		bp;
	int		ln;
	int		e;

	double	rtexx;
	double	rtexy;

	int		w;
	int		h;
}			t_img;

typedef struct s_player
{
	t_img	p;
	t_img	m;
	t_img	l;
	t_img	s;
}			t_player;

typedef struct s_main
{
	t_img	b;
	t_img	r;
	t_img	g;
	t_img	y;

	t_img	t;
	t_img	s;
}			t_main;

typedef struct s_box
{
	double	ax;
	double	ay;
	double	bx;
	double	by;
	double	cx;
	double	cy;
	double	dx;
	double	dy;
}			t_box;

typedef struct s_collider
{
	t_box	red;
	t_box	blue;
	t_box	green;
	t_box	yellow;
}			t_collider;

typedef struct s_data
{
	void		*mx;
	void		*wptr;

	t_img		mlx;

	t_map		map;

	double		rx;
	double		ry;

	double		rtexx;
	double		rtexy;

	t_collider	colbox;
	t_box		sp_box;

	double		ax;
	double		ay;
	double		bx;
	double		by;
	double		cx;
	double		cy;
	double		dx;
	double		dy;

	double		spax;
	double		spay;
	double		spbx;
	double		spby;
	double		spcx;
	double		spcy;
	double		spdx;
	double		spdy;

	double		px;
	double		py;
	int			diry;
	double		mvsd;

	char		**bm;

	t_player	r;
	t_player	b;
	t_player	g;
	t_player	y;

	t_img		play;
	t_img		move;
	t_img		left;
	t_img		mleft;

	t_img		w;
	t_img		f;
	t_img		s;
	t_img		e;
	t_img		x;

	t_main		m;
	int			end_screen;
	int			is_main;
	int			select_char;
	int			c_char;
	t_img		win;

	int			num_sprites;
	int			sprite_count;
	int			exit;
	int			finished;
	int			mvcount;
}				t_data;

// LIBFT
int		ft_strlen(char const *str);
void	*ft_memcpy(void *dest, void *src, size_t size);
char	*ft_strdup(char const *s1);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		find_index(char *str, char c);
int		get_line(char **stock, char **line, int i);
int		get_last_line(char **stock, char **line, int ret);
int		get_next_line(int fd, char **line);

// INIT STRUCTS
t_map	init_map(void);
t_box	init_box(void);
t_img	init_img(void);
void	init_img1(t_data *data);
void	init_img2(t_data *data);
void	init_cbox(t_data *data);
void	init_data(t_data *data);
t_data	init_all_data(void);

// PARSER
int		is_char(char c);
int		error_map(char **map, int x);
int		set_line(char *map, char *line);
int		get_all_sprites(char **map, t_map *info);
int		get_exit(char **map, t_map *info);

int		get_player(char **map, t_map *info);
int		verif_map(char **map, int x, int y);

int		ft_errors(char **strs, int size, char *com);

int		get_map(int fd, t_map *map);
int		set_map(int fd, t_map *map);
int		manag_map(char *file, t_map *map);

// RESIZE MAP
void	new_exit1(t_data *data, char **nmap, int x, int y);
void	new_exit2(t_data *data, char **nmap, int x, int y);
void	new_exit3(t_data *data, char **nmap, int x, int y);
void	new_exit4(t_data *data, char **nmap, int x, int y);
void	new_exit5(t_data *data, char **nmap, int x, int y);

void	new_exit(t_data *data, char **nmap, int x, int y);
void	new_render(t_data *data, char **nmap, int x, int y);
void	new_map1(t_map map, t_data *data, char **nmap);
char	**new_map(t_map map, t_data *data);

// TEXTURES
void	get_main_textures(t_data *d);
void	get_player_textures(t_data *d);
int		get_texture(t_data *d);

// MLX
void	get_ratio1(t_data *data);
void	get_ratio2(t_data *data);
void	get_colbox1(t_data *data);
void	get_colbox2(t_data *data);
void	get_all_ratio(t_data *data);

int		get_pixel(t_img *img, long int x, long int y);
void	img_pixel_put(t_img *img, int x, int y, int color);

void	init_colbox(t_data *data, t_box *box, t_box *sp);
void	dup_img(t_img *old, t_img *n);
void	choose_p(t_data *data, t_player *player, t_box *box);
void	choose_player(t_data *data);

t_img	mlx_resize_img(t_data *data, void *mlx, t_img img);
void	mlx_all_resize(t_data *data);

void	display_player(t_data *data, double x, double y);
void	display_sprites(t_data *data);
void	display_map(t_data *data);
void	display_image(t_data *data, t_img *img, int x, int y);

void	is_exitsprite(t_data *d);

void	keysym_main(t_data *data, int keysym);
void	keysym2(t_data *d);
void	keysym13(t_data *d);
void	keysym0(t_data *d);
void	keysym1(t_data *d);

void	render_background(t_data *data, int color);
int		get_jcolor(t_data *data, char c, int sx, int sy);
void	render_rect(t_data *data, int x, int y);
void	render_sp(t_data *data, int x, int y);
void	render_player(t_data *data, t_img img, double x, double y);

void	render_main(t_data *d);
int		render(t_data *d);

void	free_img(t_data *data, t_img *img);

int		handle_keypress(int keysym, t_data *data);
int		mlx_network(t_data d);
void	ft_exit(t_data *data);

#endif
