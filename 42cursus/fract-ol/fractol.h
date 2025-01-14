/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruchoa <ruchoa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:30:28 by ruchoa            #+#    #+#             */
/*   Updated: 2023/08/02 20:14:40 by ruchoa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*		INCLUDES  */
# include <mlx.h> //libmlx
# include <libft.h> //libft
# include <libftprintf.h> //libft

/*		KEYS  */
# if __APPLE__ /*  MacOS Keys  */
#  define EVENT_CLOSE_BTN	17
#  define KEY_ESC			53
#  define KEY_SPACE			49
#  define KEY_ONE			18
#  define KEY_TWO			19
#  define MOUSE_LEFT_BTN	1
#  define MOUSE_WHEEL_UP	4
#  define MOUSE_WHEEL_DOWN	5
# else /*  Linux Keys  */
#  define EVENT_CLOSE_BTN	17
#  define KEY_ESC			65307
#  define KEY_SPACE			32
#  define KEY_ONE			49
#  define KEY_TWO			50
#  define MOUSE_LEFT_BTN	1
#  define MOUSE_WHEEL_UP	4
#  define MOUSE_WHEEL_DOWN	5
# endif

/*		 DIMENSIONS  */
# define WINDOW_TITTLE "42|RIO - fract-ol"
# define WINDOW_WIDTH		1000
# define WINDOW_HEIGHT		1000
# define MAX_ITERATIONS		50

/*		 FRACTAL SETS  */
# define MANDELBROT			109
# define JULIA				106

/*		STRUCTS  */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pixels;
	int		set;
	double	min_x_coord;
	double	max_x_coord;
	double	min_y_coord;
	double	max_y_coord;
	double	start_const_x;
	double	start_const_y;
	double	const_x;
	double	const_y;
	int		*color_table;
	int		change_color;
	int		color;
}	t_data;

/*		PROTOTYPES  */
double	ft_abs(double c);
double	ft_atof(char *argv);
void	ft_check_args(int argc, char **argv, t_data *exec);
void	ft_msg(void);
void	ft_init(t_data *exec);
void	ft_draw(t_data *exec);
void	ft_window_limits(t_data *exec);
void	ft_change_set(int keycode, t_data *exec);
int		ft_iterative_power(int nb, int power);
int		ft_check_fractal(t_data *exec, double nbr_real, double nbr_imaginary);

/*		EVENTS  */
int		ft_hooks(t_data *exec);
int		ft_key_events(int keycode, t_data *exec);
int		ft_mouse_events(int keycode, int x, int y, t_data *exec);

/*		ACTIONS  */
void	ft_zoom(t_data *exec, double ft_zoom);
void	ft_move(t_data *exec, double distance, char direction);
int		ft_close(t_data *exec);

/*		COLOR  */
void	ft_change_color(t_data *f, int color);
void	ft_set_color(t_data *exec);
void	ft_set_pixel_color(t_data *exec, int x, int y, int color);
int		ft_interpolate(int startcolor, int endcolor, double fraction);

/*		SETS  */
void	ft_julia_limits(t_data *exec);
int		ft_julia_shift(int x, int y, t_data *exec);
int		set_julia(t_data *exec, double nbr_real, double nbr_imaginary);
int		set_mandelbrot(double c_real, double c_imaginary);

#endif
