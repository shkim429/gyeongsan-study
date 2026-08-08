## *This project has been created as part of the 42 curriculum by sohuikim.* <br /> <br />


## **Description**
+ ### Overview
  #### The goal of this project is to implement a 2D game in which the player must collect all items placed on the map and then reach the exit to clear the game.  <br /> <br />
 

+ ### Objectives  
  #### Through this project, you will leran the fundamentals of basic graphics programming by using 42's graphical library, MiniLibx. <bar>
  #### You will also gain an understaning of how these core concepts work and operate. <br /> <br />


## **Instructions**
+ ### Comilaition
  #### Run 'make' to compile the program and generate the 'so_long' exectable. 
	``` c
	make
	```

+ ### Usage
  #### Run the executable with the path to a map file with the .ber extension as an argument.
  	``` c
	./so_long maps/test.ber
	```
  ---
  
	#### This project includes three different types of maps for testing purposes:
  > 
  > 1. A map that is not properly enclosed by walls
  > 2. **A map with invalid requried game elements**
  > + No player or more than on player
  > + No collectible items
  > + No exit or more than one exit
  > + Presence of unauthorized or unknwon elements
  > 3. A map where the player cannot collect all items or cannot reach the exit

  #### You can run the program using the provided maps, or create your onw .ber map file and test it yourself. <br /><br />


## Useful Concepts

#### The following key MiniLibX concepts were used in this project:

+ ### **MiniLibX**
  #### The insertion sort is a sorting algroithm that processes elements sequentially from the beginning of the array inserts each element into its correct position. <bar>
  #### Typically, the second element is chosen as the key and is compared with the previous elements to determine its proper position.

---

+ ### **Main Functions**
  #### **`mlx_init()`** : 
  #### Initializes the connection connection between the program and the display server (X-server). <br/> This fuction must be called before perforimg any graphical operations when using MiniLibX.<br/><br/>

  **`mlx_new_window()`** : 
  #### Requests the display system to create a new window. <br/> The create window serves as the main unit for displaying images and handling keyboard and mouse events.<br/><br/>
  
  **`mlx_new_image()`** : 
  #### Create an image pixel buffer in the program's memory to be used for rendering images onto the window.<br/><br/>

  **`mlx_put_image_to_window()`** : 
  #### Copies the pixel data stored in an image buffer to the window and displays it on the screen.<br/><br/>

  **`mlx_hook()`**: 
  #### Registers a function to be called when user events occur, such as key presses, mouse clicks, or window close events.<br/><br/>


## **Resources** <bar>
+ ### References <bar>
  #### - MiniLibX concepts:
  (https://harm-smits.github.io/42docs) <br/>
  (https://code-jh.tistory.com/28) <br/>
  (https://github.com/Gontjarow/MiniLibX) <br/>
  (https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181)

  #### - Understanding the concepts and mechanisms of DFS:
  (https://www.geeksforgeeks.org/dsa/difference-between-bfs-and-dfs/) <br/>
  (https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/) <br/><br/>


+ ### AI Usage  
  #### - AI was used to verify my understanding of MiniLibX functions and related concepts studied through blogs and documentation. <bar> 
  #### - AI was also used to interpret English documentation, compiler erros, and memory leak reports, as wells as to choose appropriate fuction and variable names. <bar>