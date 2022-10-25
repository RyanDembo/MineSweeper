#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class Test2Button : public sf::Sprite
{
public:

	int xPos;
	int yPos;
	bool isActive;

	sf::IntRect Rect;

	Test2Button();
	Test2Button(int X, int Y);

	bool isClicked(int X, int Y);

};

