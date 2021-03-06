/*
THIS FILE IS LICENSED UNDER THE GNU GPLv3

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
				- The freedom to run the program, for any purpose.
				- The freedom to study how the program works, and adapt it to your needs.
				- The freedom to redistribute copies so you can help your neighbor.
				- The freedom to improve the program, and release
				your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#ifndef CLASSES_H
# define CLASSES_H
# include "defines.hpp"
# include <raylib.h>

class player;
class entity;
class item;
class inventory;
class map;
class game;

class entity {
	public:
	Texture2D	tex;
	char		*name;
	short		lvl;
	short		hp;
	short 		dmg;
	entity (void);
	int entity_load_texture(char *path);
	int	draw_entity(int x, int y);
};

class item {
	private:
	void	(*effect_player)(player *plyr);
	Texture2D item_texture;
	public:
	char	**description;
	char	**e_description;
	char **gen_description(void);
	item (void);
};

class inventory {
	private:
	item	items[6];
	int		items_count;
	public:
	inventory (void);
	void add_item(item to_add);
	void remove_item(int id);
	item use_item(int id);
};

class player : entity {
	inventory inv;
};

class renderer {
	private:
	Texture2D	frame;
	public:
	int			camera_pos_x, camera_pos_y, render_distance;
	bool		changed;
	void set_changed(void);
	int set_render_pos(int x, int y, map *map);
	int	render(map *map);
	Image gen_image(map *map, int width, int height);
	renderer(void);
};

class map {
	public:
	char	**map_data;
	int		map_height;
	int		map_width;
	Image	img_floor;
	Image	img_wall;
	int	load_map_images(void);
	char **init_map(void);
	char **map_generate(void);
	void print_map(void);
	void border_walls(void);
	int draw_to_image(Image dst, Image src, int x, int y);
	map(int x, int y);
};

class game {
	public:
	int	s_height;
	int	s_width;
	map level;
	renderer camera;
	// player plyr;
	game(void);
};

#endif // CLASSES_H
