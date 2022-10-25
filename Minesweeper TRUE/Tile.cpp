#include "Tile.h"

Tile::Tile(int Xarry, int Yarry, int XPOS, int YPOS, bool bomb, bool flag, bool SHOWHIDDEN, bool NUM) {

	xArry = Xarry;
	yArry = Yarry;
	xPos = XPOS;
	yPos = YPOS;
	hasBomb = bomb;
	showFlag = flag;
	showHidden = SHOWHIDDEN;
	hasNum = NUM;


	Flag.setTexture(TextureManager::getTexture("flag"));
	Flag.setPosition((float)xPos , (float )yPos);

	Hidden.setTexture(TextureManager::getTexture("tile_hidden"));
	Hidden.setPosition((float)xPos, (float)yPos);

	xFactor.setPosition((float)xPos, (float)yPos);


	Revealed.setTexture(TextureManager::getTexture("tile_revealed"));
	Revealed.setPosition((float)xPos, (float)yPos);




	//this->setPosition(sf::Vector2f(float(xPos), float(yPos)));
}


Tile::Tile() {
	xArry = 0;
	yArry = 0;
	xPos = 0;
	yPos = 0;
	hasBomb = false;
	showFlag = false;
	showHidden = false;
	hasNum = false;
}

int Tile::getNumTilesWithBombs() {
	int count = 0;

	for (unsigned int i = 0; i < adjTiles.size(); i++) {
		if (adjTiles[i]->hasBomb == true) {
			count++;
		}

	}

	return count;

}

void Tile::drawInitialBackground(sf::RenderWindow&  mirror) {

	mirror.draw(Revealed);

	int adjBombCount = this->getNumTilesWithBombs();

	if (hasBomb == true) {
		xFactor.setTexture(TextureManager::getTexture("mine"));

	
		mirror.draw(xFactor);
	}
	else if (adjBombCount == 1) {
		xFactor.setTexture(TextureManager::getTexture("number_1"));

		hasNum = true;
		mirror.draw(xFactor);

	}
	else if (adjBombCount == 2) {
		xFactor.setTexture(TextureManager::getTexture("number_2"));
		hasNum = true;

		mirror.draw(xFactor);


	}
	else if (adjBombCount == 3) {
		xFactor.setTexture(TextureManager::getTexture("number_3"));
		hasNum = true;

		mirror.draw(xFactor);


	}
	else if (adjBombCount == 4) {
		xFactor.setTexture(TextureManager::getTexture("number_4"));
		hasNum = true;

		mirror.draw(xFactor);


	}
	else if (adjBombCount == 5) {
		xFactor.setTexture(TextureManager::getTexture("number_5"));

		hasNum = true;
		mirror.draw(xFactor);


	}
	else if (adjBombCount == 6) {
		xFactor.setTexture(TextureManager::getTexture("number_6"));
		hasNum = true;

		mirror.draw(xFactor);


	}
	else if (adjBombCount == 7) {
		xFactor.setTexture(TextureManager::getTexture("number_7"));

		hasNum = true;
		mirror.draw(xFactor);


	}
	else if (adjBombCount == 8) {
		xFactor.setTexture(TextureManager::getTexture("number_8"));
		hasNum = true;

		mirror.draw(xFactor);


	}

	if (showHidden) {
		mirror.draw(Hidden);
	}

	if (showFlag) {
		mirror.draw(Flag);
	}

}

void Tile::revealAll() {
	if (this->showHidden==false) {

	}
	else {
		this->showHidden = false;
		for (unsigned int i = 0; i < adjTiles.size(); i++) {
			if (adjTiles[i]->hasNum == false && adjTiles[i]->hasBomb == false && adjTiles[i]->showFlag == false) {
				adjTiles[i]->revealAll();


			}
			else if (adjTiles[i]->hasNum == true && adjTiles[i]->hasBomb == false && adjTiles[i]->showFlag == false) {
				adjTiles[i]->showHidden = false;
			}

		}
	}
}

void Tile::Clear() {
	hasBomb = false;
	showFlag = false;
	showHidden = true;
	hasNum = false;

	adjTiles.clear();

}

void Tile::showBombs() {

	if (this->hasBomb ==true) {
		showHidden = false;
	}

}

void Tile::hideBombs() {
	if (this->hasBomb == true) {
		showHidden = true;
	}
}