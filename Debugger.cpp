#include "Debugger.h"

Debugger::Debugger()
{
	isHide = false;
	Debugger::Reset();
	Reset();
}

void Debugger::Hide(bool isHide)
{
	this->isHide = isHide;
}

void Debugger::Reset()
{
	const sf::FloatRect& tRect = text.getGlobalBounds();
	const sf::FloatRect& cRect = GetVisible();
	ConstructText( text, v2f((cam_p.x - cRect.width / 2.f) + tRect.width / 2.f, ( cam_p.y - cRect.height / 2.f) + tRect.height / 2.f), 1.5f,
		"Cursor: X = " + to_string(int(cur_p.x)) + ": Y = " + to_string(int(cur_p.y)) + "\n" + 
		"Time: " + to_string(double(time)) + "\n" +
		"Distance of the cursor to the view camera = " + to_string( GetDistance(cam_p, cur_p) ) + "\n" +
		"Press [H - Hide] : [S - Show]",
		font_freshman, sf::Color::Yellow);
}

void Debugger::Draw()
{
	if(!isHide) wnd->draw(text);
}

Debugger::~Debugger(void)
{
}
