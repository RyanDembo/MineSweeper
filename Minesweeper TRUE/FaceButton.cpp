#include "FaceButton.h"
FaceButton::FaceButton() {
	xPos = 0;
	yPos = 0;
	isHappy = true;
	isLose = false;
	isWin = false;

	Happy.setTexture(TextureManager::getTexture("face_happy"));
	Happy.setPosition((float)xPos, (float)yPos);

	Lose.setTexture(TextureManager::getTexture("face_lose"));
	Lose.setPosition((float)xPos, (float)yPos);

	Win.setTexture(TextureManager::getTexture("face_win"));
	Win.setPosition((float)xPos, (float)yPos);

}
FaceButton::FaceButton(int X, int Y) {

	xPos = X;
	yPos = Y;
	isHappy = true;
	isLose = false;
	isWin = false;

	Happy.setTexture(TextureManager::getTexture("face_happy"));
	Happy.setPosition((float)xPos, (float)yPos);

	Lose.setTexture(TextureManager::getTexture("face_lose"));
	Lose.setPosition((float)xPos, (float)yPos);

	Win.setTexture(TextureManager::getTexture("face_win"));
	Win.setPosition((float)xPos, (float)yPos);


}



void FaceButton::drawIt(sf::RenderWindow& mirror) {
	if (isHappy) {
		mirror.draw(Happy);
	}
	else if (isLose) {
		mirror.draw(Lose);
	}
	else if (isWin) {
		mirror.draw(Win);
	}
}

bool FaceButton::isClicked(int X, int Y) {
	sf::IntRect Rect = Happy.getTextureRect();
	Rect.top = yPos;
	Rect.left = xPos;

	bool test = Rect.contains(X, Y);
	return test;

}