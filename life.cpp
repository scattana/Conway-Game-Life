// life.cpp
// main driver for 'Game of Life'
// CSE-20311 Lab 8, Part 2
// Seth Cattanach, Nov 2017

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

#include "lifeboard.h"

int main(int argc, char *argv[]) {
	// display welcome message
	cout << "\n\n---------------------------------" << endl;
	cout << "Welcome to the Game of Life!" << endl;
	cout << "---------------------------------\n\n" << endl;

	// set up blank board
	Lifeboard life;

	// declare variables to hold temp data
	int row, column;
	char command;

	// interactive mode... no arguments passed to main
	if(argc==1){
		cout << "\nEntering Interactive Mode...\n" << endl;
		cout << "Instructions:" << endl;
		cout<< "Enter 'a' followed by a pair of coordinates (0-39) to add a cell\n";
		cout<<"Enter 'r' followed by a pair of coordinates (0-39) to remove a cell\n";
		cout << "Enter 'n' to advance the game to the next iteration\n";
		cout << "Enter 'q' to quit the program\n";
		cout << "Enter 'p' to play the game continuously (CRTL-C to STOP)" << endl;
		cout << "------------------------------------------------------------"<<endl;
		cout << "Example: Enter 'a 2 0' to add a cell to position (2,0)\n" << endl;

		cout << "Please enter a command: ";
		cin >> command;
		if(command == 'a' || command == 'r'){
			cin >> row >> column;
		}

		// play the game in interactive mode
		while(command != 'q' && command != 'p'){
			if(command=='n'){
				life.update();
				life.printBoard();
			}
			if(command == 'a' || command == 'r'){
				life.setElement(command, row, column);
			}
			system("clear");
			life.printBoard();
			cout << "Please enter another command: ";
			cin >> command;
			if(command == 'a' || command == 'r') cin >> row >> column;
		} // end of 'while' loop

		if(command == 'p'){
			system("clear");
			// play forever!
			while(1==1){
				life.update();
				life.printBoard();
				usleep(150000);
				system("clear");
			}
		}

		if(command == 'q'){
			return 1;
		}

	} // end of outer 'if' statement controlling interactive mode

	// batch/auto mode
	if(argc==2){
		// get filename from argument
		string file;
		file = argv[1];
		string temp;
		char hold[2] = {' ',' '};
		int test;

		// create ifs object, open and read file, line by line
		ifstream ifs;
		ifs.open(file);


		// check for valid file; if not, prompt to enter valid file or exit
		while(!ifs){
			cout << "\nInvalid file name. Please enter valid file, ";
			cout << "or type 'quit' to exit the program: " << endl;
			getline(cin, file);
			if(file=="quit"||file=="Quit"||file=="QUIT"){
				return 1;
			}
			ifs.open(file);
		}


		while(ifs.peek() != 'p'){
			// get full line from stream
			getline(ifs, temp, '\n');
			command = temp[0];
			if(command == 'p') break;
			if(temp[3] == ' '){
				hold[0] = temp[2];
			}
			else{
				hold[0] = temp[2];
				hold[1] = temp[3];
			}
			// convert to row (int)
			row = atoi(hold);
			// now extract and convert column
			if(temp[3] == ' ' && temp.size() == 5){
				hold[0] = temp[4];
				hold[1] = ' ';
				column = atoi(hold);
			}
			if(temp[3] != ' ' && temp.size() == 6){
				hold[0] = temp[5];
				hold[1] = ' ';
				column = atoi(hold);
			}
			if(temp[3] == ' ' && temp.size() == 6){
				hold[0] = temp[4];
				hold[1] = temp[5];
				column = atoi(hold);
			}
			if(temp.size() == 7){
				hold[0] = temp[5];
				hold[1] = temp[6];
				column = atoi(hold);
			}
			life.setElement(command, row, column);

			// reset 'hold'
			hold[0] = ' ';
			hold[1] = ' ';

		}

		system("clear");
		life.printBoard();

		// once a 'p' is reached in the file, play continuously
		while(1==1){
			system("clear");
			life.printBoard();
			usleep(150000);
			life.update();
		}

	} // end of 'if' statement controlling batch mode

	return 0;

} // end of main
