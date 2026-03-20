*This project has been created as part of the 42 curriculum by aralves- and jdoutor-*

* Description

	The goal of this project is to work with a library we already know from previous projects (mlx) but instead of a 2D render we are now making a 3D render, this of course adds complexity to the project because of the math required, player movement, etc...

	The final result has to look like a 3D rendered scene with a camera representing the player, the player should be able to move in all directions, the walls have textures and each texture will load depending on the cardinal point the wall is facing (N,S,E,W).
	The "sky" and "ground" are not textures but RGB colors with the following format (0-255, 0-255, 0-255).

* Instructions

	To compile cub3D, you simply need to run make at the root of the repository.
	Afterwards the program takes one singular input (the map) which has to end in .cub.
	
	The map has to contain information and specific identifiers for it to be valid. The map has to be the last thing on the .cub file and it is represented by 0 (Empy space/floor), 1 (Walls) and one of the cardinal points which tells us which way the played will be facing on execution (N,S,E,W), it has to be closed by walls (1) for it to be valid.

	The needed identifiers can be separated by spaces, multiple empty lines and their order is unimportant.
	
	The identifiers are:

	SO, NO, EA, WE -> Representing the path to the specific texture for each side of the wall (again, cardinal points) It needs to be a .xpm file. 
	
	Example of use: 

	SO ./textures/ex1/texture_SO.xpm

	The other identifier is F, for floor and C for ceiling.

	They are represented in RGB 0-255 as explained above.
	
	Example: 

	F 255,255,255
	C 55,99,199

	So now to properly run a map we do something like the following:

	./cub3D <path/to/map>

	With a correct map we will be presented with a 3D Rendered scene, this scene will have walls a ceiling and a floor, you will be facing the way you chose on the map and you will be able to walk around using (WASD) for movement and Left (<-) and Right (->) arrow keys for camera movement.
	
	Currently the game supports wall collisions only, that means you have no proper way to finish the game, to close it you can do so by either pressing the ESC key or the X arrow on the top right of the window.

* Resources

	https://harm-smits.github.io/42docs/libs/minilibx
	https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13
	https://hackmd.io/@nszl/H1LXByIE2