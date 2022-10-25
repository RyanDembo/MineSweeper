#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Board.h"
#include <iostream>

using namespace std;

int main()
{
	///// LOAD ALL TEXTURES ///////////////
	TextureManager::loadTexture("digits");
	TextureManager::loadTexture("debug");
	TextureManager::loadTexture("face_happy");
	TextureManager::loadTexture("face_lose");
	TextureManager::loadTexture("face_win");
	TextureManager::loadTexture("flag");
	TextureManager::loadTexture("mine");
	TextureManager::loadTexture("number_1");
	TextureManager::loadTexture("number_2");
	TextureManager::loadTexture("number_3");
	TextureManager::loadTexture("number_4");
	TextureManager::loadTexture("number_5");
	TextureManager::loadTexture("number_6");
	TextureManager::loadTexture("number_7");
	TextureManager::loadTexture("number_8");
	TextureManager::loadTexture("test_1");
	TextureManager::loadTexture("test_2");
	TextureManager::loadTexture("test_3");
	TextureManager::loadTexture("tile_hidden");
	TextureManager::loadTexture("tile_revealed");






	sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
	

	//////////// BUILD THE BOARD BEFORE LOOPING FOR EVENT //////////////////

	//////////// cant 

	Board Game = Board();
	Game.connectTiles();
	
	
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed) {

				auto mousePos = sf::Mouse::getPosition(window); // vector2i

				int mouseX = mousePos.x;
				int mouseY = mousePos.y;


				//flag stuff
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && Game.Face.isHappy) {
					
					if (mouseY < 512) {

						
						Tile& selectedOne = Game.getSelectedTile(mouseX, mouseY);
						if(selectedOne.showHidden == true){

							if (selectedOne.showFlag == false) {
							selectedOne.showFlag = true;

							//counter stuff here
							}
							else if (selectedOne.showFlag == true) {
							selectedOne.showFlag = false;

							// counter stuff here
							}
						} 

					}

				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (mouseY < 512 && Game.Face.isHappy) {


						Tile& selectedOne = Game.getSelectedTile(mouseX, mouseY);
						
						if (selectedOne.hasBomb == true && selectedOne.showFlag == false) {

							//cout << "ENTER GAME OVER SEQUENCE" << endl;
							Game.Face.isHappy = false;
							Game.Face.isWin = false;
							Game.Face.isLose = true;

							Game.DebugButt.isActive = true;


						}



						if (selectedOne.showFlag == false && selectedOne.hasNum == true) {
							selectedOne.showHidden = false;
						}
						else if (selectedOne.showFlag == false) {
							selectedOne.revealAll();
						}


						///check if victory///


						if (Game.isVictory()) {
							Game.Victory();
						}



					}

					if (mouseY >= 512) {

						// debug buttons	

						if (Game.DebugButt.isClicked(mouseX, mouseY) && (Game.DebugButt.isActive == false)) {
							
							Game.DebugButt.isActive = true;

						}
						else if (Game.DebugButt.isClicked(mouseX, mouseY) && (Game.DebugButt.isActive == true)) {
							Game.DebugButt.isActive = false;
						}

						/// test buttons

						if (Game.T1Butt.isClicked(mouseX, mouseY)) {

							Game.ReadFileData("testboard1");

						}
						else if (Game.T2Butt.isClicked(mouseX, mouseY)) {

							Game.ReadFileData("testboard2");


						}
						else if (Game.T3Butt.isClicked(mouseX, mouseY)) {

							Game.ReadFileData("testboard3");


						}

						////face

						if (Game.Face.isClicked(mouseX, mouseY)) {
							

								Game.Reset();


						}


					}

				}

			}
		}

		///////////////////////clear////////////////

		window.clear();



		//////////////////// draw ////////////////////
		

		Game.drawinitialBoard(window);


		 ///////////////////////
		window.display();
	}


	TextureManager::Clear();

	return 0;
}