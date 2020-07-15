Applying Pathfinding to Enemies
===============================

.. todo::

	Add a proper API for the pathfinding project
	to crossreference everything I mention here.

.. warning::

	This feature is largely experimental, and,
	due to inefficiencies in the implementation,
	causes slowdown exponentially as the algorithm
	is applied to more enemies.

CotB includes a custom implementation of the A*
pathfinding algorithm.

Requirements
------------

The following are required before
the pathfinding algorithm can be applied to
enemies.

- Initialized the game properly
- Working/loaded map populated with enemies

.. todo::

	Add crossreference for what "initializing the
	game properly" means.

Instructions
------------

1. Load your map file and create::

	MAP *my_map = map_load("path/to/map.txt");

2. Generate a navmap using the `int **map_gen_navmap(MAP *)` function::

	int **navmap = map_gen_navmap(my_map);

3. Loop over the entity list::

	for (int i = 1; i < my_map->num_ents; i++)
	{
		
	}

.. note::
	
	The player entity is always located at index 0 of the
	map's entity list.

4. Call the `enemy_move_toward(entity, navmap, target, map)` function
on each entity::

	for (int i = 1; i < my_map->num_ents; i++)
	{
		enemy_move_toward(my_map->ent_list[i], navmap, plr, my_map);
	}

.. todo::
	
	Make this an actual game engine API and add crossreference
	to explain the appearance of the 'plr' argument passed in
	the above code example.
