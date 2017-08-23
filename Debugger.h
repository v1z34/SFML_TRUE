#pragma once
#include "Basic.h"

class Debugger : public Basic
{
private:

	sf::Text text;
	bool isHide;

public:

	void Reset();
	void Hide(bool isHide);
	void Draw();

	Debugger(void);
	~Debugger(void);
};

