#pragma once
#include "Basic.h"

class Quad : public Basic
{
private:

	float timer_life;
	const float TIMER_LIFE;
	float speed;
	float angle;

public:

	Shape shape;

	Quad(v2f pos, v2f siz, IMG& img, float timer_life) : timer_life(timer_life), TIMER_LIFE(timer_life), angle(rand()%360), speed(0.05)
	{
		ConstructShape(shape, pos, siz, img, false);
		shape.setFillColor(sf::Color( rand()%122+122, rand()%122+122, rand()%122+122, 255 ));
	}

	virtual void Update()
	{
		timer_life -= time;
		if(timer_life < 0) timer_life = 0;
		shape.rotate(-0.1 * time);
		const sf::Color& c = shape.getFillColor();
		// TIMER LIFE не изменяется там получается значение от 1 до 0 плавно *255 = цвет прозрачности
		shape.setFillColor(sf::Color(c.r, c.g, c.b, ( timer_life / TIMER_LIFE ) * 255));
		MoveToAngle(shape, speed, angle);
	}

	virtual bool IsDead() const { return timer_life == 0; }
	virtual void Draw() { wnd->draw(shape); }
	virtual ~Quad(){}

};