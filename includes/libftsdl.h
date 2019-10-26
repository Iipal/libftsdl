/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:59:09 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/26 12:24:53 by tmaluh           ###   ########.fr       */
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
				char const *title)  NON_NULL((1,4));

bool		sdl_create_window(Sdl *const sdl,
				int32_t const width,
				int32_t const height,
				char const *title) NON_NULL((1,4));
bool		sdl_create_window_borderless(Sdl *const sdl,
				int32_t const width,
				int32_t const height,
				char const *title) NON_NULL((1,4));
/*
**	Free all data in Sdl*.
*/
void		sdl_free(Sdl **sdl)  NON_NULL((1));

/*
**	mlx_pixelput implementation on SDL2 for copy workflow from MLX library:
**	\param surf: Surface in which will set color \param clr.
**	\param x: X position in surface->pixels.
**	\param y: Y position in surface->pixels.
**	\param clr: Color which will set on
**	 \param x \param y position in \param surf.
**
**	Protected if \param surf doesn't exit and from segfault when position
**	 \param x && \param y isn't on \param surf.
*/
void		sdl_pixelput(SDL_Surface *const surf,
				__v2si const p, Color const clr) NON_NULL((1));

SDL_Surface	*sdl_load_image(char const *path, SDL_PixelFormat const *format)
				NON_NULL((1,2));
SDL_Surface	*sdl_load_font(const Sdl *const sdl,
				char const *text,
				SDL_Color const text_color) NON_NULL((1,2));
#endif
