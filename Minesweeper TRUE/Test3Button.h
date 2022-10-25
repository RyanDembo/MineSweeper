#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Test3Button : public sf::Sprite
	
{
public:

	int xPos;
	int yPos;
	bool isActive;

	sf::IntRect Rect;

	Test3Button();
	Test3Button(int X, int Y);

	bool isClicked(int X, int Y);
};

