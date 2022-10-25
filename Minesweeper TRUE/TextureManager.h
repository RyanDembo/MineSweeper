#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
using namespace std;

class TextureManager
{

	static map< string, sf::Texture > pics;
	
public :
	static void loadTexture(string name);

	static void loadNumTexture(string name, sf::IntRect(int x, int y , int lenght, int width));

	static sf::Texture& getTexture(string textName);

	static void Clear();

};

