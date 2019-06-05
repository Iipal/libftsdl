/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsdl_colors_math.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/05/16 17:57:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTSDL_COLORS_MATH_H
# define LIBFTSDL_COLORS_MATH_H

# include "../../libft/includes/libft.h"
# include "libftsdl_colors_math_structs.h"
# include "libftsdl_colors_math_macroses.h"

# ifdef __APPLE__
#  include "../frameworks/SDL2.framework/Headers/SDL.h"
#  include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# endif
# ifdef __linux__
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_ttf.h>
# endif

COLOR;
FCOLOR;

extern int32_t	sdl_clr_inrange(const int32_t color);

extern Color	sdl_clr_bright_inc(Color src, const float_t percent);
extern Color	sdl_clr_bright_dec(Color src, const float_t percent);

extern Color	sdl_clr_div(Color src, const float_t div);
extern Color	sdl_clr_mul(Color src, const float_t mul);

extern void		sdl_clrs_swap(Color *a, Color *b);

Color			*sdl_clrs_gradient(Color start,
					const Color end, const size_t len);

extern Color	sdl_clrs_bright_inc(Color clr1,
					const Color clr2, const float_t percent);
extern Color	sdl_clrs_bright_dec(Color clr1,
					const Color clr2, const float_t percent);

extern Color	sdl_clrs_add(Color src, const Color add);
extern Color	sdl_clrs_sub(Color src, const Color sub);
extern Color	sdl_clrs_div(Color src, const Color div);
extern Color	sdl_clrs_mul(Color src, const Color mul);

#endif