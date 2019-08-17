/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_create_window_borderless.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:16:18 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/17 15:28:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_create_window_borderless(Sdl *const sdl,
			int32_t const width,
			int32_t const height,
			char const *title)
{
	if (sdl->w)
		SDL_DestroyWindow(sdl->w);
	if (!(sdl->w = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_BORDERLESS)))
		return false;
	if (!(sdl->wsurf = SDL_GetWindowSurface(sdl->w)))
	{
		SDL_DestroyWindow(sdl->w);
		return false;
	}
	if (!(sdl->pxls = sdl->wsurf->pixels))
	{
		SDL_DestroyWindow(sdl->w);
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", E_SURFPXL);
		return false;
	}
	return true;
}
