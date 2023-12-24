#include "turn.h"
#include "generation.h"
#include "display.h"
#include "shots.h"

/**
 * @brief Execute a player's turn in the game.
 *
 * @param p_tab_Board An array of Board structures representing the game boards.
 */
void player_turn(Board* p_tab_Board){
	//Check parameters
	if (p_tab_Board == NULL){
		exit(19);
	}
	
	// Display board with shot fired by Player.
	printf("\n\nTirs déja réalisés : \n\n");
	displayBoard(p_tab_Board[0], 1, p_tab_Board[1]);
	
	// Player will shoot.
	// Check if shot is valid.
	int validshot = 0;
	int shotx;
	int shoty;
	int max_coordinate = p_tab_Board[0].size_matrix - 1;
	
	// Shot is valid of there is no issue.
	while (validshot == 0){
		validshot = 1;
		printf("\ncoordonée X de tir : ");
		// Checks the x coordinates.
		if (scanf("%d", &shotx) != 1 || shotx>max_coordinate || shotx<0){
			validshot = 0;
			printf("\nindex X should be an integer between 0 and %d\n", max_coordinate);
		}
		else{
			// Empty input buffer then checks the y coordinates.
			int empty;
			while (empty = getchar() != '\n');
			
			printf("\ncoordonée Y de tir : ");
			if (scanf("%d", &shoty) != 1 || shoty>max_coordinate || shoty<0){
				validshot = 0;
				printf("\nindex Y should be an integer between 0 and %d\n", max_coordinate);
			}
			
			// Cannot shoot where Player already shot, whether it is a miss or a hit.
			else if (is_water_shot(&p_tab_Board[0], shotx, shoty) == 0){
				validshot = 0;
				printf("\nAlready shot here !");
			}
			
			else if (is_wreck_shot(&p_tab_Board[0], shotx, shoty) == 0){
				validshot = 0;
				printf("\nAlready shot here !");
			}
		}
		
		int empty;
		while (empty = getchar() != '\n');
	}
	
	// We now have a valid shot. Check if hit or miss.
	boat_or_water_shot(&p_tab_Board[0], &p_tab_Board[1], shotx, shoty);
}

/**
 * @brief Execute the computer's turn in the game.
 *
 * @param p_tab_Board An array of Board structures representing the game boards.
 */
void computer_turn(Board* p_tab_Board){
	// Check parameters
	if (p_tab_Board == NULL){
		exit(20);
	}
	
	// Determination of eligible cells.
	int* listex_e; // List for the x coordinates.
	int* listey_e; // List for the y coordinates.
	int nb_eligible_cells = 0;
	int size_temp = p_tab_Board[1].size_matrix;
	
	// An upper bound of the number of eligible cells is size_matrix*size_matrix.
	listex_e = malloc(sizeof(int)*size_temp*size_temp);
	if (listex_e == NULL){
		exit(30);
	}
	listey_e = malloc(sizeof(int)*size_temp*size_temp);
	if (listey_e == NULL){
		exit(31);
	}
	
	// Cannot shoot where the computer already shot.
	for (int i=0; i<size_temp; i++){
		for (int j=0; j<size_temp; j++){
		int possible = 1;
			if (is_water_shot(&p_tab_Board[1], i, j) == 0){
				possible = 0;
			}
			if (is_wreck_shot(&p_tab_Board[1], i, j) == 0){
				possible = 0;
			}
			// If no issue, cell is eligible.
			if(possible == 1){
				listex_e[nb_eligible_cells] = i;
				listey_e[nb_eligible_cells] = j;
				nb_eligible_cells += 1;
			}	
			
		}
	}
	
	// Cell is choosen randomly.
	int c_randomint = rand() % nb_eligible_cells;
	int randx = listex_e[c_randomint];
	int randy = listey_e[c_randomint];
	
	// Temporary lists are freed.
	free(listex_e);
	free(listey_e);
	boat_or_water_shot(&p_tab_Board[1], &p_tab_Board[0], randx, randy);
}

