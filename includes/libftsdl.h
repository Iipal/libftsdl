/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 13:01:53 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_H
# define LIBFTSDL_H

# include "libftsdl_colors_math.h"
# include "libftsdl_macroses.h"
# include "libftsdl_errno.h"
# include "libvectors.h"

struct		s_sdl
{
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uint32_t	*pxls;
	TTF_Font	*font;
	SDL_Event	e;
};

# define SDL typedef struct s_sdl Sdl

SDL;

/*
**	Initialize SDL2.
**	\param sdl: Pointer to already allocated Sdl.
**	\param width: Window width what will created.
**	\param height: Window height what will created.
**	\param title: Title for window.
*/
bool		sdl_init(Sdl *const sdl,
				int32_t const width,
				int32_t const height,
				char const *title);

bool		sdl_create_window_without_borders(Sdl *const sdl,
				int32_t const width,
				int32_t const height,
				char const *title);
/*
**	Free all data in Sdl*.
*/
void		sdl_free(Sdl **sdl);

/*
**	mlx_pixelput implementation on SDL2 for copy workflow from MLX library.
**	\param surf: Surface in which will set color \param clr.
**	\param x: X position in surface->pixels.
**	\param y: Y position in surface->pixels.
**	\param clr: Color which will set on \param x \param y position.
**
**	Protected from segfault when x && y pixel doesnt exist on Surface,
**	and if Surface doesnt exist too.
*/
void		sdl_pixelput(SDL_Surface *const surf,
				__v2si const p, Color const clr);

SDL_Surface	*sdl_load_image(char const *path,
				SDL_PixelFormat const *format,
				SDL_Surface *dst);
SDL_Surface	*sdl_load_font(const Sdl *const sdl,
				char const *text,
				SDL_Color const text_color,
				SDL_Surface *dst);

#endif
