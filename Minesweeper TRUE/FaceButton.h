#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
class FaceButton
{
public:
	int xPos;
	int yPos;


	sf::Sprite Happy;
	sf::Sprite Lose;
	sf::Sprite Win;

	bool isHappy;
	bool isLose;
	bool isWin;

	FaceButton();
	FaceButton(int X, int Y);

	bool isClicked(int X, int Y);

	void drawIt(sf::RenderWindow& mirror);


};

