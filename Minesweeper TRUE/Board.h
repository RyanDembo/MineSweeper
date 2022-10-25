#pragma once
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include"DebugButton.h"
#include <sstream>
#include <fstream>
#include"Test1Button.h"
#include"Test2Button.h"
#include"Test3Button.h"
#include"ClockNumbers.h"
#include"FaceButton.h"
class Board
{
public:

	Tile Set[25][16];

	DebugButton DebugButt;

	Test1Button T1Butt;
	Test2Button T2Butt;
	Test3Button T3Butt;
	
	ClockNumbers Digit1;
	ClockNumbers Digit2;
	ClockNumbers Digit3;

	FaceButton Face;



	Board();



	void drawinitialBoard(sf::RenderWindow& Mirror);



	////////need connect tle function in board class ///////////////////

	void connectTiles();

	Tile& getSelectedTile(int X, int Y);

	void Clear();

	void ReadFileData(string path);


	int getNumBombs();
	int getNumFlags();

	void Reset();
	void Victory();
	bool isVictory();
};

