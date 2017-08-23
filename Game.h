#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // �������� �������, ���� ����� �� �������������
#include "Basic.h"
#include "Debugger.h"
#include "Quad.h"

class Game : public Basic //���������
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

