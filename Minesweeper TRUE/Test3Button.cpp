#include "Test3Button.h"
Test3Button::Test3Button() {
	xPos = 0;
	yPos = 0;
	isActive = false;
	this->setTexture(TextureManager::getTexture("test_3"));
	this->setPosition((float)xPos, (float)yPos);


	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}
Test3Button::Test3Button(int X, int Y) {


	xPos = X;
	yPos = Y;
	isActive = false;
	this->setTexture(TextureManager::getTexture("test_3"));
	this->setPosition((float)xPos, (float)yPos);


	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}

bool Test3Button::isClicked(int X, int Y) {
	bool test = Rect.contains(X, Y);
	return test;

}