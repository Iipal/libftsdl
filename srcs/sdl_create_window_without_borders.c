/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_create_window_without_borders.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:16:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/09 22:18:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

inline bool	sdl_create_window_without_borders(Sdl *sdl,
				const int32_t width,
				const int32_t height,
				const string title)
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
