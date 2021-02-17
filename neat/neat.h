// guiprada@gmail.com  Guilherme Cunha Prada 2017-2020 : )
// zlib license

#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
//////////////////////////////////////////////////////////////////////// structs

typedef struct vec2_struct neat_vec2;
struct vec2_struct {
	double x;
	double y;
};

typedef struct window_struct neat_window;
struct window_struct {
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	bool			hidden;
};

typedef struct sprite_struct neat_sprite;
struct sprite_struct {
	SDL_Texture*		texture;
	SDL_Rect			source_rect;
	SDL_Rect			pos_rect;
	neat_vec2			pos;
	SDL_Point			anchor_point;
	neat_vec2			anchor;
	bool				anchor_set;
	double				rotation;
	neat_vec2			scale;
	SDL_RendererFlip	flip;
	neat_window*		window;
};

typedef struct neat_texture_struct	neat_texture;
struct neat_texture_struct {
	SDL_Texture*	texture;
	neat_window*	window;
};
////////////////////////////////////////////////////////////////////// functions

int					neat_start();
// returns 0 on sucess, diferent errors are coded so look it up

void				neat_stop();
// return 0 on sucess

neat_window*		neat_window_create(const char*, int, int, int, int);
// NULL on error, you have to free_context() it!

void				neat_window_destroy(neat_window*);

void                neat_sprite_render(neat_sprite*);
void				neat_sprite_init(neat_sprite*, neat_texture*);
neat_sprite*		neat_sprite_create(neat_texture*);
void				neat_sprite_destroy(neat_sprite*);
void				neat_sprite_set_scale(neat_sprite*, double, double);
void				neat_sprite_set_anchor(neat_sprite*, double, double);
void				neat_sprite_set_rotation(neat_sprite*, double);
void				neat_sprite_move(neat_sprite*, double, double);
void				neat_sprite_move_to(neat_sprite*, double, double);
void				neat_sprite_set_source_rect(neat_sprite*, int, int, int, int);
void				neat_sprite_set_source_rect_and_anchor(neat_sprite*, int, int, int, int, int, int);

void				neat_SDL_Rect_fill(neat_window*, SDL_Color*, SDL_Rect*);

SDL_Rect			neat_SDL_rect_create(int, int, int, int);
SDL_Point			neat_SDL_Point_create(int, int);
SDL_Point			neat_SDL_Point_create_from_neat_vec2(neat_vec2*);
neat_vec2			neat_vec2_create(double, double);

neat_texture*		neat_texture_create(neat_window*, const char*);
neat_texture*		neat_texture_create_from_text(neat_window*, TTF_Font*, SDL_Color, const char*);
void				neat_texture_destroy(neat_texture*);