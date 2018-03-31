// lifeboard.h
// header file for Lifeboard class
// Lab 8, Part 2, CSE-20311 fall 2017
// Seth Cattanach, Nov 2017


class Lifeboard {
	public:
		Lifeboard();
		~Lifeboard();
		char getSpot(int, int);
		void update();
		void setElement(char, int, int);
		void printBoard();
	private:
		// 41 includes the right and bottom borders
		char board[41][41];
};
