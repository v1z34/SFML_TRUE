#include "Game.h"

Game::Game(void) : Basic("init"), timer_create_figure(0), isClickL(false), isClickR(false)
{

	while (wnd->isOpen())
	{
		timer_create_figure += time;
		Basic::Reset();					// Обновляем время
		debugger.Reset();				// Обновляем данные для вывода

		while (wnd->pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape) wnd->close();
				if(event.key.code == sf::Keyboard::H) debugger.Hide(true);
				if(event.key.code == sf::Keyboard::S) debugger.Hide(false);
			}

			if(event.type == sf::Event::Closed) wnd->close();

			if(event.type == sf::Event::MouseButtonPressed) 
			{
				if(event.key.code == sf::Mouse::Left ) isClickL = true;
				if(event.key.code == sf::Mouse::Right) isClickR = true;
			}

			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(event.key.code == sf::Mouse::Left ) isClickL = false;
				if(event.key.code == sf::Mouse::Right) isClickR = false;
			}
		}

		if(isClickL)
		{
			if(timer_create_figure > 10)
			{
				timer_create_figure = 0;
				vec_Quad.push_back(make_shared<Quad>(Quad(cur_p, v2f(2.5,2.5), texture->Quad, 2500)));
			}
		}

		if(isClickR)
		{
			if(timer_create_figure > 20)
			{
				timer_create_figure = 0;
				vec_Quad.push_back(make_shared<Quad>(Quad(cur_p, v2f(5,5), texture->Quad, 2500)));
			}
		}

		for(auto& it = vec_Quad.begin(); it != vec_Quad.end();)
		{
			auto& quad = *(*it);
			if(!quad.IsDead())
			{
				quad.Update();
				it++;
			}
			else it = vec_Quad.erase(it);
		}


		wnd->clear();

		for(auto& quad: vec_Quad) quad->Draw();
		debugger.Draw();
		wnd->draw(shpCursor);

		wnd->display();
	}
}


Game::~Game(void)
{
}
