#include "Basic.h"

sf::RenderWindow*		Basic::wnd;
sf::Clock				Basic::clock;
sf::Event				Basic::event;
sf::View				Basic::cam;
sf::Font*				Basic::font_freshman;
float					Basic::time;
float					Basic::time_in_pause;
float					Basic::time_enemy;
int						Basic::scr_W;
int						Basic::scr_H;
float					Basic::scr_1;
float					Basic::scr_1w;
v2f						Basic::cam_p;
v2f						Basic::cur_p;
Texture*				Basic::texture;
Audio*					Basic::audio;
enum Basic::GSTATE		Basic::gState;
bool					Basic::isPauseGame;
bool					Basic::isSound_Music_On;
bool					Basic::isSound_Effects_On;
bool					Basic::isVideo_Smoth_On;
bool					Basic::isVideo_VertSync_On;
uint					Basic::sound_Vol_Music;
uint					Basic::sound_Vol_Effects;
Shape					Basic::shpCursor;

sf::FloatRect Basic::GetVisible()
{
	return sf::FloatRect(float(cam_p.x - (scr_W/2)), float(cam_p.y - (scr_H/2)),  float(scr_W),  float(scr_H));
}

void Basic::Reset()
{
	time = float(clock.getElapsedTime().asMicroseconds() / 1000.f), clock.restart();
	time_enemy = time;
	if(!isPauseGame) time_in_pause = time;
	else time_in_pause = 0;
	cur_p = wnd->mapPixelToCoords(sf::Mouse::getPosition(*wnd));
	shpCursor.rotate(0.5*time);
	shpCursor.setPosition(cur_p);
}

v2f Basic::GetNormalizePosition(v2f pos, float dist, float angle)
{
	return pos + v2f(cosf(angle*PI/180.f),sinf(angle*PI/180.f))*dist;
}

void Basic::MoveToAngle(Shape &shape, float speed, float angle)
{
	const float A = angle * PI / 180.f;
	const float S = speed * time;
	shape.move(v2f(cosf(A),sinf(A))*S); 
}

float Basic::GetDistance(v2f p1, v2f p2)
{
	return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}

void Basic::ConstructShape(Shape& shp, v2f pos, v2f siz, IMG& png, const bool perc_pos)
{
	shp.setSize(siz*scr_1);
	shp.setOrigin(siz*scr_1/2.f);
	if(perc_pos) shp.setPosition(pos*scr_1);
	else shp.setPosition(pos);
	shp.setTexture(&png);
}

void Basic::ConstructShape(Shape& shp, v2f pos, v2f siz, const bool perc_pos)
{
	shp.setSize(siz*scr_1);
	shp.setOrigin(siz*scr_1/2.f);
	if(perc_pos) shp.setPosition(pos*scr_1);
	else shp.setPosition(pos);
}

void Basic::ConstructText(sf::Text& text, v2f pos, float siz, sf::String str, sf::Font* font, sf::Color col)
{
	text.setFont(*font);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(uint(siz*scr_1));
	text.setColor(col);
	text.setString(str);
	text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
	text.setPosition(pos);
}

float Basic::GetAngle(v2f p1, v2f p2)
{
	return atan2f(p2.y - p1.y, p2.x - p1.x) * (180/PI);
}

Basic::Basic(void* init)
{
	if(init == "init")
	{
		isPauseGame = false;
		gState = main_menu;
		scr_W = GetSystemMetrics(0); 
		scr_H = GetSystemMetrics(1);
		scr_1 = scr_H / 100.f;
		scr_1w = scr_W / 100.f;
		time_in_pause = 0;
		time = 0;

		texture = new Texture;
		audio = new Audio;
		ConstructShape(shpCursor, cur_p, v2f(3,3), texture->Cursor);
		texture->setSmoth(true);
		font_freshman = new sf::Font;
		font_freshman->loadFromFile("Resources/Font/freshman.ttf");

		wnd = new sf::RenderWindow(sf::VideoMode(scr_W,scr_H), "SFML Game Template", sf::Style::Default, sf::ContextSettings(0,0,24));
		cam.reset(sf::FloatRect(0, 0, float(scr_W), float(scr_H)));
		cam.setCenter(0,0);
		cam_p = cam.getCenter();
		cur_p = v2f(0,0);
		wnd->setView(cam);
		wnd->setMouseCursorVisible(false);
		wnd->setVerticalSyncEnabled(false);

		srand(::time(0));
		clock.restart();
	}
}

Basic::Basic(void){}
Basic::~Basic(void){}