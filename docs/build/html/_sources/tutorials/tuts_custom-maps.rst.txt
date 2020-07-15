Creating Custom Maps
====================

Welcome to the tutorial for creating custom maps
for CotB!

How Loading Maps Works
----------------------

All CotB maps are stored as raw text files. CotB reads
each character of the map file and loads tile data.
Loaded tiles are based on the characters in the map file.

The following map characters are supported:

+----+------------------+
+Char+ Tile             +
+====+==================+
+ #  + Wall tile        +
+----+------------------+
+ .  + Floor tile       +
+----+------------------+
+ \- + Empty Space tile +
+----+------------------+
+ \+ + Door tile        +
+----+------------------+
+ e  + Enemy tile       +
+----+------------------+

.. note::

	The floor tile character is only by convention. CotB
	recognizes any character not already taken as
	walkable floor tiles.

.. note::

	The player, represented by a '@' character, is
	**always** placed in the top left corner of the map.
	Do not put a '@' character in any map files.

Creating a Simple Map
---------------------

.. todo::
	
	Add more robust step by step guide to creating a simple map.

Example simple map file:

.. image:: ./res/simple_map.png

Creating a Complex Map
----------------------

.. todo::
	
	Add more robust step by step guide to creating a complex map.

Creating more complex maps is also possible. In order
to make more complex maps, you will use the Empty Space
character which isn't drawn to the in-game screen.

Example: The following map file

.. image:: ./res/complex_map.png

will be drawn to the screen as

.. image:: ./res/complex_map_rendered.png
