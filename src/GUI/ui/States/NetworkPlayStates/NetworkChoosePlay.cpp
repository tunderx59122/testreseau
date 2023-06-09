#include "GUI/ui/States/NetworkPlayStates/NetworkChoosePlay.hpp"
#include <GUI/game/EntitySprite.hpp>
#include <Skill.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>

/*FAIRE LES MSG DE COMMUNICATION : "pos d pos" / "pos a pos"*/


NetworkChoosePlay::NetworkChoosePlay(SOCKET socket, StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace)
	: super(socket, machine, window, world, texture_manager, replace), _animationManager(), _actions(window), _movements(window), _spriteFactory(_world, texture_manager, _animationManager)
{
	for (auto& row : _world.getSprites())
	{
		for (auto& sprite : row)
		{
			if (sprite)
			{
				sprite->setOrigin(.0f, 9.5f);
			}
		}
	}
}

void NetworkChoosePlay::pause()
{
}

void NetworkChoosePlay::resume()
{
}



void NetworkChoosePlay::update()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				_world.clean();
				_machine.run(StateMachine::build<MenuState>(_machine, _window, _world, _textureManager, true));
			}
		}
	}

	_is_moving = false;

	auto [x, y] = _window.getSize();
	char message[] = "";

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		// Taking where the mouse is clicked. 
		int mouse_x = sf::Mouse::getPosition(_window).x;
		int mouse_y = sf::Mouse::getPosition(_window).y;

		int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50) * 50 + (0.24 * x);
		int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50) * 50 + (0.04 * y);

		int pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
		int pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);


		char str1;
		char str2;


		//creating message to give the choice made

		if (pos_grid_x < 10) {
			str1 = '0' + pos_grid_x + '/';
		}
		else {
			str1 = pos_grid_x + '/';
		}
		if (pos_grid_x < 10) {
			str2 = '0' + pos_grid_y + '/';
		}
		else {
			str2 = pos_grid_y + '/';
		}

		strcat(&str1, &str2);





		// If we have selected a character.
		if (_m_isCharacterSelected)
		{
			// Iterating in each Button sprite. 
			for (int i = 0; i < _actions.getSprites().size(); i++)
			{
				// Checking if a click is detected on One of the sprites
				if (_actions.getSprites()[i]->getGlobalBounds().contains(mouse_x, mouse_y))
				{

					if (i == 0) // Moove
					{
						// Stocking the zones where the character can go
						_movements.showMovingZones(_window, dynamic_cast<Character*>(currentEntity), _world.getGrid());
						_m_isMoovement = true;
						this->draw();

						// Click Blocker. 
						// Checking for a click on the grid.	
						bool wait = false;
						while (!wait) {
							sf::Vector2i vector = sf::Mouse::getPosition();
							wait = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
						}
						wait = false;
						// End Click blocker

						// Changing the position of the character
						// If we can move to the position we clicked on.

						pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
						pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);


						char str1_target;
						char str2_target;


						//creating message to give the choice made

						

						


						if ((currentEntity->canMove(_world.getGrid(), pos_grid_x, pos_grid_y)))
						{

							/*

							int pos_X_Init = window_click_x ;
							int pos_Y_Init = window_click_y;
							int pos_arrival_x = static_cast<int>(((sf::Mouse::getPosition(_window).x)));
							int pos_arrival_y = static_cast<int>(((sf::Mouse::getPosition(_window).y)));
							*/
							int pos_X_arrival = pos_grid_x * 50 + (0.24 * x);
							int pos_Y_arrival = pos_grid_y * 50 + (0.04 * y);

							std::cout << "character at position " << _world.getGrid()[currentEntity->getPosition().getX()][currentEntity->getPosition().getY()]->getPosition() << std::endl;

							std::cout << "before: " << currentEntity->getPosition() << '\n';
							std::cout << "sprite at " << _world[currentEntity->getPosition().getX()][currentEntity->getPosition().getY()] << '\n';

							currentSprite = _world[currentEntity->getPosition().getX()][currentEntity->getPosition().getY()];

							_is_moving = true;

							
							

							while (currentSprite->getPosition().x != pos_X_arrival || currentSprite->getPosition().y != pos_Y_arrival)
							{
								if (currentSprite->getPosition().x < pos_X_arrival)
								{
									currentSprite->setCurrentAnimation(7);
								}
								else if (currentSprite->getPosition().x > pos_X_arrival)
								{
									currentSprite->setCurrentAnimation(6);
								}
								else if (currentSprite->getPosition().y < pos_Y_arrival)
								{
									currentSprite->setCurrentAnimation(5);
								}
								else if (currentSprite->getPosition().y > pos_Y_arrival)
								{
									currentSprite->setCurrentAnimation(8);
								}

								currentSprite->loopCurrentAnimation(true);
								currentSprite->playAnimation();

								if (currentSprite->getPosition().x < pos_X_arrival)
								{
									while (currentSprite->getPosition().x != pos_X_arrival)
									{
										currentSprite->move(2.f, 0.f);
										this->draw();
									}
								}
								else if (currentSprite->getPosition().x > pos_X_arrival)
								{
									while (currentSprite->getPosition().x != pos_X_arrival)
									{
										currentSprite->move(-2.f, 0.f);
										this->draw();
									}
								}
								else if (currentSprite->getPosition().y < pos_Y_arrival)
								{
									while (currentSprite->getPosition().y != pos_Y_arrival)
									{
										currentSprite->move(0.f, 2.f);
										this->draw();
									}
								}
								else if (currentSprite->getPosition().y > pos_Y_arrival)
								{
									while (currentSprite->getPosition().y != pos_Y_arrival)
									{
										currentSprite->move(0.f, -2.f);
										this->draw();
									}
								}
							}

							currentSprite->stopAnimation();

							_is_moving = false;


							//envoie le changement de position d'un personnage


							if (pos_grid_x < 10) {
								str1_target = '0' + pos_grid_x + '/';
							}
							else {
								str1_target = pos_grid_x + '/';
							}
							if (pos_grid_x < 10) {
								str2_target = '0' + pos_grid_y;
							}
							else {
								str2_target = pos_grid_y;
							}

							strcat(&str1_target, &str2_target);

							char final_str[14] = "d/";
							strcat(final_str, &str1);
							strcat(final_str, &str1_target);

							sendMessage(this->_socket, final_str);

							//_world[currentEntity->getPosition().getX()][currentEntity->getPosition().getY()]->setPosition(pos_X_arrival, pos_Y_arrival);///.move(pos_X_Init - pos_X_arrival, pos_Y_Init - pos_Y_arrival);
							std::cout << "AUUUUGH" << std::abs((pos_grid_x + pos_grid_y) - (currentEntity->getPosition().getX() + currentEntity->getPosition().getY())) << std::endl;
							currentEntity->setNbMoves(std::abs((pos_grid_x + pos_grid_y) - (currentEntity->getPosition().getX() + currentEntity->getPosition().getY())));
							_world.getGrid().move(currentEntity->getPosition().getX(), currentEntity->getPosition().getY(), pos_grid_x, pos_grid_y);
							_world.update();
							std::cout << "beforee: " << currentEntity->getNbMoves() << '\n';
							//std::cout << "sprite at " << _world[currentEntity->getPosition().getX()][currentEntity->getPosition().getY()] << '\n';

							_m_isCharacterSelected = false;

						}

						_m_isMoovement = false;

					}
					if (i == 2) // First Attack
					{
						//Getting the current character as a character Class, and not an Entity. 
						// Getting the first skill of the character.
						characterSkill = currentEntity->getFirstSkill();


						// Drawing the zones where the character can attack.
						_movements.showAttackZones(_window, characterSkill, _world.getGrid());
						_m_isAttack = true;
						this->draw();



						// Click Looker. 
						// Checking for a click on the grid.
						bool wait = false;
						while (!wait) {
							sf::Vector2i vector = sf::Mouse::getPosition();
							wait = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
						}
						wait = false;

						// End Click Looker
						// Getting the position of the click on the grid.
						int Attack_click_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
						int Attack_click_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
						// Checking if there is a character on the grid.
						if (_world.getGrid()[Attack_click_x][Attack_click_y])
						{
							// Getting the target character on the grid as a character class, and not an Entity.
							Character* characterTarget = dynamic_cast<Character*>(_world.getGrid()[Attack_click_x][Attack_click_y]);

							if (currentEntity->getFirstSkill()->canActivate(_world.getGrid(), characterTarget))
							{
								std::cout << "You attack" << std::endl;
								// play animation and block the rest until it's done
								//currentSprite->setCurrentAnimation(9);
								//auto& anim = currentSprite->getCurrentAnimation();
								currentEntity->getFirstSkill()->activate(_world.getGrid(), characterTarget);
								playerDetector = (playerDetector + 1) % 2;

								_m_isAttack = false;
							}
							else
							{
								std::cout << "You can't attack your own character" << std::endl;
							}
						}
						else
						{
							std::cout << "You can't attack an empty case" << std::endl;
							_m_isAttack = false;
						}

						char str1_target;
						char str2_target;

						if (pos_grid_x < 10) {
							str1_target = '0' + Attack_click_x + '/';
						}
						else {
							str1_target = Attack_click_x + '/';
						}
						if (pos_grid_x < 10) {
							str2_target = '0' + Attack_click_y;
						}
						else {
							str2_target = Attack_click_y;
						}

						strcat(&str1_target, &str2_target);

						char final_str[14] = "a/";
						strcat(final_str, &str1);
						strcat(final_str, &str1_target);

						sendMessage(this->_socket, final_str);

					}// end Moove 2
					if (i == 5)
					{
						playerDetector = (playerDetector + 1) % 2;
						currentEntity->resetNbMoves();
						std::cout << "after: " << currentEntity->getNbMoves() << '\n';

					}
					break;

				}
				else {
					_m_isCharacterSelected = false;
				}
			}

			char buffer[14];

			receiveMessage(this->_socket, buffer, 14);


			std::string strx;
			char charx = buffer[2] + buffer[3];

			strx.assign(&charx);


			std::string stry;
			char chary = buffer[5] + buffer[6];

			stry.assign(&chary);




			int pos_x = atoi(strx.c_str());
			int pos_y = atoi(stry.c_str());


			charx = buffer[8] + buffer[9];

			strx.assign(&charx);


			chary = buffer[11] + buffer[12];

			stry.assign(&chary);


			int pos_final_x = atoi(strx.c_str());
			int pos_final_y = atoi(stry.c_str());
			


			if (buffer[0] == 'd') {

				Position pos = Position(pos_x, pos_y);

				int pos_X_arrival = pos_final_x * 50 + (0.24 * x);
				int pos_Y_arrival = pos_final_y * 50 + (0.04 * y);

				std::cout << "character at position " << _world.getGrid()[pos.getX()][pos.getY()]->getPosition() << std::endl;

				std::cout << "before: " << currentEntity->getPosition() << '\n';
				std::cout << "sprite at " << _world[pos.getX()][pos.getY()] << '\n';

				currentSprite = _world[pos.getX()][pos.getY()];

				_is_moving = true;




				while (currentSprite->getPosition().x != pos_X_arrival || currentSprite->getPosition().y != pos_Y_arrival)
				{
					if (currentSprite->getPosition().x < pos_X_arrival)
					{
						currentSprite->setCurrentAnimation(7);
					}
					else if (currentSprite->getPosition().x > pos_X_arrival)
					{
						currentSprite->setCurrentAnimation(6);
					}
					else if (currentSprite->getPosition().y < pos_Y_arrival)
					{
						currentSprite->setCurrentAnimation(5);
					}
					else if (currentSprite->getPosition().y > pos_Y_arrival)
					{
						currentSprite->setCurrentAnimation(8);
					}

					currentSprite->loopCurrentAnimation(true);
					currentSprite->playAnimation();

					if (currentSprite->getPosition().x < pos_X_arrival)
					{
						while (currentSprite->getPosition().x != pos_X_arrival)
						{
							currentSprite->move(2.f, 0.f);
							this->draw();
						}
					}
					else if (currentSprite->getPosition().x > pos_X_arrival)
					{
						while (currentSprite->getPosition().x != pos_X_arrival)
						{
							currentSprite->move(-2.f, 0.f);
							this->draw();
						}
					}
					else if (currentSprite->getPosition().y < pos_Y_arrival)
					{
						while (currentSprite->getPosition().y != pos_Y_arrival)
						{
							currentSprite->move(0.f, 2.f);
							this->draw();
						}
					}
					else if (currentSprite->getPosition().y > pos_Y_arrival)
					{
						while (currentSprite->getPosition().y != pos_Y_arrival)
						{
							currentSprite->move(0.f, -2.f);
							this->draw();
						}
					}
				}

				currentSprite->stopAnimation();






				if (_world.getGrid()[pos_final_x][pos_final_y])
				{
					// Getting the target character on the grid as a character class, and not an Entity.
					Character* characterTarget = dynamic_cast<Character*>(_world.getGrid()[pos_final_x][pos_final_y]);

					if (currentEntity->getFirstSkill()->canActivate(_world.getGrid(), characterTarget))
					{
						std::cout << "You attack" << std::endl;
						// play animation and block the rest until it's done
						//currentSprite->setCurrentAnimation(9);
						//auto& anim = currentSprite->getCurrentAnimation();
						currentEntity->getFirstSkill()->activate(_world.getGrid(), characterTarget);
						playerDetector = (playerDetector + 1) % 2;

						_m_isAttack = false;
					}
					else
					{
						std::cout << "You can't attack your own character" << std::endl;
					}
				}



			}




		}
		if (0 <= pos_grid_x && pos_grid_x < 20 && 0 <= pos_grid_y && pos_grid_y < 20)
		{
			if (_world.getGrid()[pos_grid_x][pos_grid_y])
			{
				if (playerDetector == 0 && dynamic_cast<Character*>(_world.getGrid()[pos_grid_x][pos_grid_y])->getPlayer() == 'B' || playerDetector == 1 && dynamic_cast<Character*>(_world.getGrid()[pos_grid_x][pos_grid_y])->getPlayer() == 'R')
				{
					currentEntity = dynamic_cast<Character*>(_world.getGrid()[pos_grid_x][pos_grid_y]);
					currentSprite = _world[pos_grid_x][pos_grid_y];

					currentCharacterName = currentEntity->getClass();
					//_actions.setText(dynamic_cast<Character*>(currentEntity));

					window_click_x = static_cast<int>(((sf::Mouse::getPosition(_window).x)));
					window_click_y = static_cast<int>(((sf::Mouse::getPosition(_window).y)));

					_m_isCharacterSelected = true;
				}

			}
		}
	}
}


void NetworkChoosePlay::draw()
{
	_window.clear();

	if (_is_moving)
	{
		currentSprite->update(_clock.restart());
	}

	_window.draw(_world);

	if (_m_isCharacterSelected && !_is_moving)
	{
		_window.draw(_actions);
	}

	if ((_m_isMoovement || _m_isAttack) && !_is_moving)
	{
		_window.draw(_movements);
	}

	_window.display();
}
