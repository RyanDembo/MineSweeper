#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class ClockNumbers : public sf::Sprite
{
public:
	int xPos;
	int yPos;

	sf::IntRect zero;
	sf::IntRect one;
	sf::IntRect two;
	sf::IntRect three;
	sf::IntRect four;
	sf::IntRect five;
	sf::IntRect six;
	sf::IntRect seven;
	sf::IntRect eight;
	sf::IntRect nine;
	sf::IntRect neg;

	ClockNumbers();
	ClockNumbers(int X, int Y);

	void showZero();
	void showOne();
	void showTwo();
	void showThree();
	void showFour();
	void showFive();
	void showSix();
	void showSeven();
	void showEight();
	void showNine();
	void showNeg();





};

