/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:23:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/24 14:14:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_init(Sdl *const sdl,
				int32_t const width,
				int32_t const height,
				char const *title)
{
	bool	ret = true;

	if (0 > SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Log("%s\n", SDL_GetError());
		ret = false;
	}
	if (0 > TTF_Init())
	{
		SDL_Log("%s\n", TTF_GetError());
		ret = false;
	}
	sdl->font = TTF_OpenFont(FPS_FONT, FPS_FONT_SIZE);
	if (!sdl->font)
	{
		SDL_Log("%s\n", TTF_GetError());
		ret = false;
	}
	if (0 > IMG_Init(IMG_INIT_JPG))
	{
		SDL_Log("%s\n", IMG_GetError());
		ret = false;
	}
	if (!sdl_create_window(sdl, width, height, title))
		ret = false;
	return ret;
}
