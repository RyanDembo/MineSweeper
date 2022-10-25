#include "DebugButton.h"

DebugButton::DebugButton() {
	xPos = 0;
	yPos = 0;
	isActive = false;
	this->setTexture(TextureManager::getTexture("debug"));
	this->setPosition((float)xPos, (float)yPos);

	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}
DebugButton::DebugButton(int X, int Y) {



	xPos = X;
	yPos = Y;
	isActive = false;
	this->setTexture(TextureManager::getTexture("debug"));
	this->setPosition((float)xPos, (float)yPos);

	Rect = this->getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;
}

bool DebugButton::isClicked(int X, int Y) {
	bool test = Rect.contains(X, Y);
	return test;

}