#include "ClockNumbers.h"

ClockNumbers::ClockNumbers() {
	xPos = 0;
	yPos = 0;

	this->setTexture(TextureManager::getTexture("digits"));
	this->setPosition((float)xPos, (float)yPos);


	zero = sf::Rect<int>::Rect(0, 0, 21, 32);
	one = sf::Rect<int>::Rect(21, 0, 21, 32);
	two = sf::Rect<int>::Rect(42, 0, 21, 32);
	three = sf::Rect<int>::Rect(63, 0, 21, 32);
	four = sf::Rect<int>::Rect(84, 0, 21, 32);
	five = sf::Rect<int>::Rect(105, 0, 21, 32);
	six = sf::Rect<int>::Rect(126, 0, 21, 32);
	seven = sf::Rect<int>::Rect(147, 0, 21, 32);
	eight = sf::Rect<int>::Rect(168, 0, 21, 32);
	nine = sf::Rect<int>::Rect(189, 0, 21, 32);
	neg = sf::Rect<int>::Rect(210, 0, 21, 32);


}
ClockNumbers::ClockNumbers(int X, int Y) {
	xPos = X;
	yPos = Y;

	this->setTexture(TextureManager::getTexture("digits"));
	this->setPosition((float)xPos, (float)yPos);


	zero = sf::Rect<int>::Rect(0, 0, 21, 32);
	one = sf::Rect<int>::Rect(21, 0, 21, 32);
	two = sf::Rect<int>::Rect(42, 0, 21, 32);
	three = sf::Rect<int>::Rect(63, 0, 21, 32);
	four = sf::Rect<int>::Rect(84, 0, 21, 32);
	five = sf::Rect<int>::Rect(105, 0, 21, 32);
	six = sf::Rect<int>::Rect(126, 0, 21, 32);
	seven = sf::Rect<int>::Rect(147, 0, 21, 32);
	eight = sf::Rect<int>::Rect(168, 0, 21, 32);
	nine = sf::Rect<int>::Rect(189, 0, 21, 32);
	neg = sf::Rect<int>::Rect(210, 0, 21, 32);


	/*
	zero = sf::Rect<int>::Rect(xPos, yPos, 21, 32);
	one = sf::Rect<int>::Rect(xPos + 21, yPos, 21, 32);
	two = sf::Rect<int>::Rect(xPos + 42, yPos, 21, 32);
	three = sf::Rect<int>::Rect(xPos + 63, yPos, 21, 32);
	four = sf::Rect<int>::Rect(xPos + 84, yPos, 21, 32);
	five = sf::Rect<int>::Rect(xPos + 105, yPos, 21, 32);
	six = sf::Rect<int>::Rect(xPos + 126, yPos, 21, 32);
	seven = sf::Rect<int>::Rect(xPos + 147, yPos, 21, 32);
	eight = sf::Rect<int>::Rect(xPos + 168, yPos, 21, 32);
	nine = sf::Rect<int>::Rect(xPos + 189, yPos, 21, 32);
	neg = sf::Rect<int>::Rect(xPos + 210, yPos, 21, 32);
	*/
}

void ClockNumbers::showZero() {
	this->setTextureRect(zero);
}
void ClockNumbers::showOne() {
	this->setTextureRect(one);
}
void ClockNumbers::showTwo() {
	this->setTextureRect(two);
}
void ClockNumbers::showThree() {
	this->setTextureRect(three);
}
void ClockNumbers::showFour() {
	this->setTextureRect(four);
}
void ClockNumbers::showFive() {
	this->setTextureRect(five);
}
void ClockNumbers::showSix() {
	this->setTextureRect(six);
}
void ClockNumbers::showSeven() {
	this->setTextureRect(seven);
}
void ClockNumbers::showEight() {
	this->setTextureRect(eight);
}
void ClockNumbers::showNine() {
	this->setTextureRect(nine);
}
void ClockNumbers::showNeg() {
	this->setTextureRect(neg);
}
