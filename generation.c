#include "generation.h"

Board generate_Board(int size, int* tab_boat_size, int* tab_boats, int g_nb_size_boat, int _total_nb_boat){
	// Check parameters.
	if (size <= 0|| g_nb_size_boat <= 0|| _total_nb_boat <= 0){
		exit(1);
	}
	if (tab_boat_size == NULL || tab_boats == NULL){
		exit(2);
	}
	
	// Assignment of struct Board variables.
	Board newBoard;
	newBoard.size_matrix = size;
	newBoard.s_tab_boat_size = tab_boat_size;
	newBoard.s_tab_nb_boats = tab_boats;
	newBoard.s_nb_size_boats = g_nb_size_boat;
	newBoard.b_total_nb_boats = _total_nb_boat;
	newBoard.current_nb_boats = 0;
	newBoard.nb_water_shot = 0;
	newBoard.nb_wreck_shot = 0;

	newBoard.matrix = malloc(sizeof(int*)*size);
	for (int i=0; i<size; i++){
		newBoard.matrix[i] = malloc(sizeof(int)*size);
		if (newBoard.matrix[i] == NULL){
			exit(6);
		}
	}

	if (newBoard.matrix == NULL){
			exit(40);
		}
	
	// All cells are initially set to 0.
	for(int r=0; r < size; ++r){
		for(int s=0; s < size; ++s){
			newBoard.matrix[r][s] = 0;
		}
	}
	
	// Not all shot will be water shot, but size*size is an upper bound of the number of water shots.
	newBoard.water_shot_x = malloc(sizeof(int)*size*size);
	if (newBoard.water_shot_x == NULL){
			exit(20);
		}
	newBoard.water_shot_y = malloc(sizeof(int)*size*size);
	if (newBoard.water_shot_y == NULL){
			exit(21);
		}
	newBoard.wreck_shot_x = malloc(sizeof(int)*size*size);
	if (newBoard.wreck_shot_x == NULL){
			exit(22);
		}
	newBoard.wreck_shot_y = malloc(sizeof(int)*size*size);
	if (newBoard.wreck_shot_y == NULL){
			exit(23);
		}
	newBoard.tab_boats = malloc(sizeof(Boat)*_total_nb_boat);
	if (newBoard.tab_boats == NULL){
			exit(23);
		}
	
	return newBoard;
}

void ajouter_bateau(Board* newBoard, int posx, int posy, int a_size_boat, int a_orientation){
	// Check parameters.
	if (newBoard == NULL){
		exit(5);
	}
	if (a_orientation != 0 && a_orientation != 1){
		exit(6);
	}
	int pos_max = newBoard->size_matrix-1;
	if (posx < 0 || posx > pos_max){
		exit(7);
	}
	if (posy < 0 || posy > pos_max){
		exit(8);
	}
	
	// Assignment of struct Boat variables.
	Boat newBoat;
	newBoat.x = posx;
	newBoat.y = posy;
	newBoat.size = a_size_boat;
	newBoat.orientation = a_orientation;
	newBoat.hit = 0;
	
	// Initalisation of the lists of coordinates.
	newBoat.tab_cell_x = malloc(sizeof(int)*a_size_boat);
	if (newBoat.tab_cell_x == NULL){
			exit(10);
		}
	newBoat.tab_cell_y = malloc(sizeof(int)*a_size_boat);
	if (newBoat.tab_cell_y == NULL){
			exit(11);
		}
	
	// Different cells for the two possible orientations.
	if (a_orientation == 0){ // 0 is horizontal.
		for (int i=0; i<a_size_boat; i++){
			newBoat.tab_cell_x[i] = posx; // Assignation of the coordinates.
			newBoat.tab_cell_y[i] = posy + i;
			newBoard->matrix[posx][posy + i] = 1;
		}
	}
	else{
		for (int i=0; i<a_size_boat; i++){
			newBoat.tab_cell_x[i] = posx + i;
			newBoat.tab_cell_y[i] = posy;
			newBoard->matrix[posx + i][posy] = 1;
		}
	}
	
	// Add boat to the list of boats.
	newBoard->tab_boats[newBoard->current_nb_boats] = newBoat;
}

