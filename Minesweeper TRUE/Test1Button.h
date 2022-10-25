#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Test1Button : public sf::Sprite
	
{
public:
	int xPos;
	int yPos;
	bool isActive;

	sf::IntRect Rect;

	Test1Button();
	Test1Button(int X, int Y);

	bool isClicked(int X, int Y);
};

