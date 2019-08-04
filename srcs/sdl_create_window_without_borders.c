/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_create_window_without_borders.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:16:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 12:56:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_create_window_without_borders(Sdl *const sdl,
			int32_t const width,
			int32_t const height,
			char const *title)
{
	FREE(sdl->w, SDL_DestroyWindow);
	NOM_F(SDL_GetError(),
		sdl->w = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS));
	NO(SDL_GetError(), sdl->wsurf = SDL_GetWindowSurface(sdl->w),
		SDL_DestroyWindow(sdl->w), false);
	IFDOM(E_SURFPXL, !(sdl->pxls = sdl->wsurf->pixels),
		SDL_DestroyWindow(sdl->w));
	return (true);
}
