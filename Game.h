#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // Скрывает консоль, если нужна то закомментируй
#include "Basic.h"
#include "Debugger.h"
#include "Quad.h"

class Game : public Basic //изменение
{
private:

	Debugger debugger;
	vector<shared_ptr<Quad>> vec_Quad;
	float timer_create_figure;
	bool isClickL, isClickR;

public:

	Game(void);
	~Game(void);
};

