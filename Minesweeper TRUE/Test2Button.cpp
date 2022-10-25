#include "Test2Button.h"

Test2Button::Test2Button() {
	xPos = 0;
	yPos = 0;
	isActive = false;
	this->setTexture(TextureManager::getTexture("test_2"));
	this->setPosition((float)xPos, (float)yPos);


	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}
Test2Button::Test2Button(int X, int Y) {


	xPos = X;
	yPos = Y;
	isActive = false;
	this->setTexture(TextureManager::getTexture("test_2"));
	this->setPosition((float)xPos, (float)yPos);


	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}

bool Test2Button::isClicked(int X, int Y) {
	bool test = Rect.contains(X, Y);
	return test;

}

