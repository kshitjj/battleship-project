#include <iostream>
#include <string>
using namespace std;

int main(){
	// position of the ships on 2x2 board
	bool gameBoard[5][5] = {
		{0, 1, 0, 0, 1},
		{0, 1, 1, 0 ,0},
		{0, 0, 0, 0 ,0},
		{1, 0, 0, 0 ,0},
		{0, 0, 0, 0 ,1}
	};

	// introduction to the game
	cout << "Welcome to battleship(CLI edition)" << endl;
	cout << "To play the game, You need to input 2 coordinates(x,y)" << endl;
	cout << "These input are the coordinate you attack. So, let's get started" << endl;
	
	// showing visuals to the user
	string visualShownToUser[5][5] = {
		{"-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-"},
		{"-", "-", "-", "-", "-"}
	};

	int hit = 0;
	int numberOfTurns = 0;
	//game code
	while(hit < 6){
		// taking the x, y coordinate for the attack
		int x, y;
		cout << "Enter the x coordinate?(0-4) ";
		cin >> x;

		cout << "Enter the y coordinate?(0-4) ";
		cin >> y;
		
		// if the position is true, then it's a hit and hit gets incremented. 
		// If not number of turns get incremented
		if (gameBoard[x][y]) {
			gameBoard[x][y] = false;
			cout << "----Hit!----" << endl;
			visualShownToUser[x][y] = "X";
			for (int i = 0; i < 5; i++) {
				cout << "|";
				for (int j = 0; j < 5; j++) {
					cout << visualShownToUser[i][j] << "|";
				}
				cout << endl;
			}
			cout << endl;
			hit++;
			numberOfTurns++;
		} else {
			cout << "----You missed!----" << endl;
			visualShownToUser[x][y] = "O";
			for (int i = 0; i < 5; i++) {
				cout << "|";
				for (int j = 0; j < 5; j++) {
					cout << visualShownToUser[i][j] << "|";
				}
				cout << endl;
			}
			cout << endl;
			numberOfTurns++;
		}	
	}
	cout << endl << "Thanks for playing! You won in " << numberOfTurns << " turns" << endl;
	return 0;

}
