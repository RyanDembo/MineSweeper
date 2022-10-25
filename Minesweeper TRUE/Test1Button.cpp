#include "Test1Button.h"
Test1Button::Test1Button() {
	xPos = 0;
	yPos = 0;
	isActive = false;
	this->setTexture(TextureManager::getTexture("test_1"));
	this->setPosition((float)xPos, (float)yPos);


	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}
Test1Button::Test1Button(int X, int Y) {


	xPos = X;
	yPos = Y;
	isActive = false;
	this->setTexture(TextureManager::getTexture("test_1"));
	this->setPosition((float)xPos, (float)yPos);


	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}

bool Test1Button::isClicked(int X, int Y) {
	bool test = Rect.contains(X, Y);
	return test;

}

