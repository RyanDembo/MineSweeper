#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
using namespace std;
class Tile 
{
public:
	int xArry;
	int yArry;


	int xPos;
	int yPos;
	bool hasBomb;
	bool showFlag;
	bool showHidden;
	bool hasNum;

	vector<Tile*> adjTiles;

	sf::Sprite Flag;

	sf::Sprite Hidden;

	sf::Sprite xFactor;

	sf::Sprite Revealed;


	Tile();
	Tile(int Xarry, int Yarry, int XPOS, int YPOS, bool bomb, bool flag, bool SHOWHIDDEN, bool NUM);

	void drawInitialBackground(sf::RenderWindow& mirror);

	int getNumTilesWithBombs();

	
	void revealAll();
	void Clear();

	void showBombs();
	void hideBombs();

};

