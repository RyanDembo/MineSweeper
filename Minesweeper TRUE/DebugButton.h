#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class DebugButton : public sf::Sprite
	
{
public:
	int xPos;
	int yPos;
	bool isActive;

	sf::IntRect Rect;
	//= Set[i][j].Revealed.getTextureRect();

	//Reactangle.top = Set[i][j].yPos;
	//Reactangle.left = Set[i][j].xPos;

	DebugButton();
	DebugButton(int X, int Y);

	bool isClicked(int X, int Y);


};

