/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:23:52 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/17 15:54:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftsdl.h"

bool	sdl_init(Sdl *const sdl,
				int32_t const width,
				int32_t const height,
				char const *title)
{
	if (0 > SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", SDL_GetError());
		return false;
	}
	if (0 > TTF_Init())
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", TTF_GetError());
		return false;
	}
	if (0 > IMG_Init(IMG_INIT_JPG))
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n", IMG_GetError());
		return false;
	}
	;
	if (!sdl_create_window_borderless(sdl, width, height, title))
		return false;
	return true;
}
