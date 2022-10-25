#include "Board.h"
#include "Tile.h"
#include <random>
#include<iostream>
Board::Board() {

	DebugButt = DebugButton(512, 513);
	T1Butt = Test1Button(577, 513);
	T2Butt = Test2Button(642, 513);
	T3Butt = Test3Button(707, 513);

	Digit1 = ClockNumbers(0 , 513);
	Digit2 = ClockNumbers(21, 513);
	Digit3 = ClockNumbers(42, 513);

	Face = FaceButton(368, 513);

	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {

			Set[i][j] = Tile(i , j , (i * 32), (j * 32), false, false, true, false);

		}
	}


	/////////// randomize bomb placement ////////////
	random_device device;
	uniform_int_distribution<int> Xdist(0, 24);
	uniform_int_distribution<int> Ydist(0, 15);


	//device gives true random seed
	mt19937 generator(device());



	int goAgaine = 50;
	for (int k = 0; k < goAgaine; k++) {
		int randomX = Xdist(generator);

		int randomY = Ydist(generator);


		if (Set[randomX][randomY].hasBomb == false) {

			Set[randomX][randomY].hasBomb = true;

		}
		else {
			goAgaine++;

		}

	}

}


void Board::drawinitialBoard(sf::RenderWindow& Mirror) {
	if (DebugButt.isActive) {
		for (int i = 0; i < 25; i++) {

			for (int j = 0; j < 16; j++) {

				Set[i][j].showBombs();

				Set[i][j].drawInitialBackground(Mirror);

			}


		}

	}
	else {
		for (int i = 0; i < 25; i++) {

			for (int j = 0; j < 16; j++) {

				Set[i][j].hideBombs();
				Set[i][j].drawInitialBackground(Mirror);

			}


		}
	}

	Mirror.draw(DebugButt);

	Mirror.draw(T1Butt);
	Mirror.draw(T2Butt);
	Mirror.draw(T3Butt);

	Face.drawIt(Mirror);

	

	int numToDisp = (this->getNumBombs() - this->getNumFlags());

	
	char digits[4];


	//converts num into char array of correct size (always 3) says 4 because nullchar
	snprintf(digits, 4 , "%03d" , numToDisp);

	if (digits[0] == '-') {
		Digit1.showNeg();
	}
	else if (digits[0] == '0') {
		Digit1.showZero();
	}
	else if (digits[0] == '1') {
		Digit1.showOne();
	}
	else if (digits[0] == '2') {
		Digit1.showTwo();
	}
	else if (digits[0] == '3') {
		Digit1.showThree();
	}
	else if (digits[0] == '4') {
		Digit1.showFour();
	}
	else if (digits[0] == '5') {
		Digit1.showFive();
	}
	else if (digits[0] == '6') {
		Digit1.showSix();
	}
	else if (digits[0] == '7') {
		Digit1.showSeven();
	}
	else if (digits[0] == '8') {
		Digit1.showEight();
	}
	else if (digits[0] == '9') {
		Digit1.showNine();
	}


	if (digits[1] == '0') {
		Digit2.showZero();
	}
	else if (digits[1] == '1') {
		Digit2.showOne();
	}
	else if (digits[1] == '2') {
		Digit2.showTwo();
	}
	else if (digits[1] == '3') {
		Digit2.showThree();
	}
	else if (digits[1] == '4') {
		Digit2.showFour();
	}
	else if (digits[1] == '5') {
		Digit2.showFive();
	}
	else if (digits[1] == '6') {
		Digit2.showSix();
	}
	else if (digits[1] == '7') {
		Digit2.showSeven();
	}
	else if (digits[1] == '8') {
		Digit2.showEight();
	}
	else if (digits[1] == '9') {
		Digit2.showNine();
	}


	if (digits[2] == '0') {
		Digit3.showZero();
	}
	else if (digits[2] == '1') {
		Digit3.showOne();
	}
	else if (digits[2] == '2') {
		Digit3.showTwo();
	}
	else if (digits[2] == '3') {
		Digit3.showThree();
	}
	else if (digits[2] == '4') {
		Digit3.showFour();
	}
	else if (digits[2] == '5') {
		Digit3.showFive();
	}
	else if (digits[2] == '6') {
		Digit3.showSix();
	}
	else if (digits[2] == '7') {
		Digit3.showSeven();
	}
	else if (digits[2] == '8') {
		Digit3.showEight();
	}
	else if (digits[2] == '9') {
		Digit3.showNine();
	}



 
	Mirror.draw(Digit1);
	Mirror.draw(Digit2);
	Mirror.draw(Digit3);


}


void Board::connectTiles() {
	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {

			int BudyPos = j + 1;
			int BudyNeg = j - 1;


			int BudxPos = i + 1;
			int BudxNeg = i - 1;

			if (((BudyPos < 16) && (BudxPos < 25)) && ((BudyNeg >= 0) && (BudxNeg >= 0))  ) {

				Tile* tile1 = &Set[BudxPos][BudyPos];
				Tile* tile2 = &Set[BudxPos][BudyNeg];
				Tile* tile3 = &Set[BudxNeg][BudyPos];
				Tile* tile4 = &Set[BudxNeg][BudyNeg];

				Tile* tile5 = &Set[i][BudyPos];
				Tile* tile6 = &Set[i][BudyNeg];
				Tile* tile7 = &Set[BudxPos][j];
				Tile* tile8 = &Set[BudxNeg][j];




				Set[i][j].adjTiles.push_back(tile1);
				Set[i][j].adjTiles.push_back(tile2);
				Set[i][j].adjTiles.push_back(tile3);
				Set[i][j].adjTiles.push_back(tile4);
				Set[i][j].adjTiles.push_back(tile5);
				Set[i][j].adjTiles.push_back(tile6);
				Set[i][j].adjTiles.push_back(tile7);
				Set[i][j].adjTiles.push_back(tile8);


			}
			//top row
			else if (( j == 0 ) && (i != 0) && ( i != 24) ) {
				Tile* tile1 = &Set[BudxPos][j];
				Tile* tile2 = &Set[BudxNeg][j];
				Tile* tile3 = &Set[i][BudyPos];
				Tile* tile4 = &Set[BudxPos][BudyPos];
				Tile* tile5 = &Set[BudxNeg][BudyPos];
				

				Set[i][j].adjTiles.push_back(tile1);
				Set[i][j].adjTiles.push_back(tile2);
				Set[i][j].adjTiles.push_back(tile3);
				Set[i][j].adjTiles.push_back(tile4);
				Set[i][j].adjTiles.push_back(tile5);
			}
			///botom row
			else if ((j == 15) && (i != 0) && (i != 24)) {
				Tile* tile1 = &Set[BudxPos][j];
				Tile* tile2 = &Set[BudxNeg][j];
				Tile* tile3 = &Set[i][BudyNeg];
				Tile* tile4 = &Set[BudxPos][BudyNeg];
				Tile* tile5 = &Set[BudxNeg][BudyNeg];


				Set[i][j].adjTiles.push_back(tile1);
				Set[i][j].adjTiles.push_back(tile2);
				Set[i][j].adjTiles.push_back(tile3);
				Set[i][j].adjTiles.push_back(tile4);
				Set[i][j].adjTiles.push_back(tile5);

			}
			//left collumn
			else if ((i == 0) && (j != 0) && (j != 15)) {
				Tile* tile1 = &Set[BudxPos][j];
				Tile* tile2 = &Set[i][BudyPos];
				Tile* tile3 = &Set[i][BudyNeg];
				Tile* tile4 = &Set[BudxPos][BudyNeg];
				Tile* tile5 = &Set[BudxPos][BudyPos];


				Set[i][j].adjTiles.push_back(tile1);
				Set[i][j].adjTiles.push_back(tile2);
				Set[i][j].adjTiles.push_back(tile3);
				Set[i][j].adjTiles.push_back(tile4);
				Set[i][j].adjTiles.push_back(tile5);



			}
			//right collumn
			else if ((i == 24) && (j != 0) && (j != 15)) {
				Tile* tile1 = &Set[BudxNeg][j];
				Tile* tile2 = &Set[i][BudyPos];
				Tile* tile3 = &Set[i][BudyNeg];
				Tile* tile4 = &Set[BudxNeg][BudyNeg];
				Tile* tile5 = &Set[BudxNeg][BudyPos];


				Set[i][j].adjTiles.push_back(tile1);
				Set[i][j].adjTiles.push_back(tile2);
				Set[i][j].adjTiles.push_back(tile3);
				Set[i][j].adjTiles.push_back(tile4);
				Set[i][j].adjTiles.push_back(tile5);


			}
			// 4 corners
			//topleft
			else if ((i == 0) && (j == 0)) {
				Tile* tile1 = &Set[BudxPos][j];
				Tile* tile2 = &Set[BudxPos][BudyPos];
				Tile* tile3 = &Set[i][BudyPos];

				Set[i][j].adjTiles.push_back(tile1);
				Set[i][j].adjTiles.push_back(tile2);
				Set[i][j].adjTiles.push_back(tile3);
			}
			//topright
			else if((i == 24) && (j == 0)) {
			Tile* tile1 = &Set[BudxNeg][j];
			Tile* tile2 = &Set[BudxNeg][BudyPos];
			Tile* tile3 = &Set[i][BudyPos];

			Set[i][j].adjTiles.push_back(tile1);
			Set[i][j].adjTiles.push_back(tile2);
			Set[i][j].adjTiles.push_back(tile3);

			}

			//bot left
			else if ((i == 0) && (j == 15)) {
			Tile* tile1 = &Set[BudxPos][j];
			Tile* tile2 = &Set[BudxPos][BudyNeg];
			Tile* tile3 = &Set[i][BudyNeg];

			Set[i][j].adjTiles.push_back(tile1);
			Set[i][j].adjTiles.push_back(tile2);
			Set[i][j].adjTiles.push_back(tile3);

			}
			//bot right
			else if ((i == 24) && (j == 15)) {
			Tile* tile1 = &Set[BudxNeg][j];
			Tile* tile2 = &Set[BudxNeg][BudyNeg];
			Tile* tile3 = &Set[i][BudyNeg];

			Set[i][j].adjTiles.push_back(tile1);
			Set[i][j].adjTiles.push_back(tile2);
			Set[i][j].adjTiles.push_back(tile3);

			}

		}


	}

}

Tile& Board::getSelectedTile(int X, int Y) {

	cout << "mouse cord is : " << X << " , " << Y << endl;

	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {

			sf::IntRect Reactangle = Set[i][j].Revealed.getTextureRect();

			Reactangle.top = Set[i][j].yPos;
			Reactangle.left = Set[i][j].xPos;
			//cout << Reactangle.width << endl;

			if (Reactangle.contains(X, Y)) {
				

				return Set[i][j];


			}
		}
	}


	cout << "error, clicked out of bounds" << endl;

	return Set[0][0];
}

void Board::Clear() {
	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {

			Set[i][j].Clear();

		}
	}
}

void Board::ReadFileData(string name) {
	
	this->Clear();
	
	string path = "boards/";
	path = path + name;
	path = path + ".brd";
	

	string line;
	ifstream boardFile;

	boardFile.open(path);

	bool test = boardFile.is_open();

	if (test) {
		

		 
		for (int j = 0; j < 16; j++) {

			for (int i = 0; i < 25; i++) {

				char readChar = boardFile.get();

				if (readChar == '0') {
					Set[i][j].hasBomb = false;


				}
				else if (readChar == '1') {
					Set[i][j].hasBomb = true; 
				}
				else {
					i--;
					

					cout << "MISSED : " << readChar << endl;
				}

			}
		}

		connectTiles();

		this->Face.isHappy = true;
		this->Face.isLose = false;
		this->Face.isWin = false;
	}

}

int Board::getNumBombs() {
	int count = 0;

	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {
			if (Set[i][j].hasBomb) {
				count++;
			}
		}

	}
	return count;
}
int Board::getNumFlags() {
	int count = 0;

	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {
			if (Set[i][j].showFlag) {
				count++;
			}
		}

	}
	return count;
}

void Board::Reset() {
	this->Clear();


	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {
			                                            //hasBomb   showFlag   showHidden hasNum
			//Set[i][j] = Tile(i, j, (i * 32), (j * 32), false, false, true, false);
			Set[i][j].hasBomb = false;
			Set[i][j].showFlag = false;
			Set[i][j].showHidden = true;
			Set[i][j].hasNum = false;
		}
	}


	/////////// randomize bomb placement ////////////
	random_device device;
	uniform_int_distribution<int> Xdist(0, 24);
	uniform_int_distribution<int> Ydist(0, 15);


	//device gives true random seed
	mt19937 generator(device());



	int goAgaine = 50;
	for (int k = 0; k < goAgaine; k++) {
		int randomX = Xdist(generator);

		int randomY = Ydist(generator);


		if (Set[randomX][randomY].hasBomb == false) {

			Set[randomX][randomY].hasBomb = true;

		}
		else {
			goAgaine++;

		}

	}


	connectTiles();
	this->Face.isHappy = true;
	this->Face.isLose = false;
	this->Face.isWin = false;

	//this->DebugButt.isActive = false;
}

void Board::Victory() {
	this->DebugButt.isActive = false;

	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {
			if (Set[i][j].hasBomb) {
				Set[i][j].showFlag = true;
			}
		}

	}

	this->Face.isHappy = false;
	this->Face.isLose = false;
	this->Face.isWin = true;
}


bool Board::isVictory() {
	int count = 0;
	for (int i = 0; i < 25; i++) {

		for (int j = 0; j < 16; j++) {
			if (!(Set[i][j].hasBomb) && Set[i][j].showHidden == false) {
				

				count++;

			}
		}

	}

	//400 is total num of tiles
	if (count == (400 - this->getNumBombs())) {
		return true;


	}
	else {
		return false;
	}
}