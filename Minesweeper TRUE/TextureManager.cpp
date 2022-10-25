#include "TextureManager.h"
map< string, sf::Texture > TextureManager::pics;

void TextureManager::loadTexture(string name) {
	string path = "images/";
	path = path + name;
	path = path + ".png";


	pics[name].loadFromFile(path);

}

sf::Texture& TextureManager::getTexture(string textName) {
	return pics[textName];
}

void TextureManager::Clear() {
	pics.clear();
}

///// USE ONLY FOR USING RED NUMBERS LATER //////////////
void TextureManager::loadNumTexture(string name, sf::IntRect(int x, int y, int lenght, int width)) {
	string path = "images/";
	path = path + name;
	path = path + ".png";


	pics[name].loadFromFile(path);


}