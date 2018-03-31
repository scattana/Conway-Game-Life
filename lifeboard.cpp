// lifeboard.cpp
// implementation of lifeboard class
// CSE-20311 Lab 8, Part 2
// Seth Cattanach, Nov 2017

#include <iostream>
#include "lifeboard.h"
using namespace std;

// default implementation of Lifeboard class
Lifeboard::Lifeboard(){
	// make the border of the board all O's
	for(int i=0; i<41; i++){
		board[40][i] = 'O';
		board[i][40] = 'O';
	}
	// make the inside of the board all spaces
	for(int j=0; j<40; j++){
		for(int k=0; k<40; k++){
			board[j][k] = ' ';
		}
	}

}

// destructor
Lifeboard::~Lifeboard() {}

// printBoard method to display the board
void Lifeboard::printBoard(){
	for(int i=0; i<41; i++){
		for(int j=0; j<41; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

// update method
void Lifeboard::update(){
	// define 'future' board same as an empty Lifeboard object
	Lifeboard future;
	// loop through every position on the board and check rules
	int dead = 0, alive = 0;
	for(int i=0; i<40; i++){
		for(int j=0; j<40; j++){
			// count number of dead and alive neighbors
			if(board[i][j-1]=='X') alive++;
			if(board[i][j-1]==' ') dead++;
			if(board[i-1][j-1]=='X') alive++;
			if(board[i-1][j-1]==' ') dead++;
			if(board[i-1][j]=='X') alive++;
			if(board[i-1][j]==' ') dead++;
			if(board[i-1][j+1]=='X') alive++;
			if(board[i-1][j+1]==' ') dead++;
			if(board[i][j+1]=='X') alive++;
			if(board[i][j+1]==' ') dead++;
			if(board[i+1][j+1]=='X') alive++;
			if(board[i+1][j+1]==' ') dead++;
			if(board[i+1][j]=='X') alive++;
			if(board[i+1][j]==' ') dead++;
			if(board[i+1][j-1]=='X') alive++;
			if(board[i+1][j-1]==' ') dead++;

			// a dead cell with exactly three neighbors becomes alive
			if(board[i][j]==' ' && alive==3) future.board[i][j] = 'X';

			// a live cell with 2 or 3 neighbors survives
			if(board[i][j]=='X'&&(alive==2||alive==3)){
				future.board[i][j]='X';
			}

			// a live cell with more than 3 or fewer than 2 neighbors dies
			if(board[i][j]=='X' &&  alive>3) future.board[i][j] = ' ';
			if(board[i][j]=='X' && alive<2) future.board[i][j] = ' ';

			// reset dead ana live count
			dead = 0;
			alive = 0;



		} // end of inner for loop
	} // end of outer for loop

	// future board becomes board
	for(int i=0; i<40; i++){
		for(int j=0; j<40; j++){
			board[i][j] = future.board[i][j];
		}
	}





} // end of 'update' method

void Lifeboard::setElement(char comm, int row, int col){
	// add or remove the specified element from the board

	// use inputted command and coordinates to add/remove element from old board
	if(comm == 'a'){
		board[row][col] = 'X';
	}
	if(comm == 'r'){
		board[row][col] = ' ';
	}
} // end of 'setElement' method

