#pragma once
#include <Windows.h>
#include "Texture.h"
#include "Audio.h"
#define PI 3.14159

typedef unsigned int uint;
typedef sf::Vector2f v2f;
typedef sf::Vector2i v2i;
typedef sf::Keyboard Key;
typedef sf::RectangleShape Shape;

class Basic
{
public:

	Basic(void);					// ������ ����������� ���������� ���� ������������ ��� ��������� ������� � ����� ����� ������
	Basic(void* init);				// ����������� ������������� !���������� 1 ��� ��� ������� ���������
	~Basic(void);
	static void Reset();			// ������������ ����� � ������� ������� � �������� �����

	// ������������ (������) ��� ������ - perc_pos false ���� ����� ���������� ����� ������� �������
	// � ������ perc_pos true ������ ������ � ������� � ���������� ����������� �� ������ ������
	static void ConstructShape(Shape& shp, v2f pos, v2f siz, IMG& png, const bool perc_pos = true);
	static void ConstructShape(Shape& shp, v2f pos, v2f siz, const bool perc_pos = true);

	// ����������� ��� ������ siz �������� �� ���������� ����������� 3-4 ���������� ������
	// ����� ����� � ���������� ������� � ����������� �����������
	static void ConstructText(sf::Text& text, v2f pos, float siz, sf::String str, sf::Font* font, sf::Color col = sf::Color());
	
public:

	static sf::RenderWindow* wnd;					// ���� ����
	static sf::Clock clock;							// ���-���
	static sf::Event event;							// �������
	static sf::View cam;							// ������ ����
	static sf::Font *font_freshman;					// �����
	static Shape shpCursor;							// ���� �������

	static float time;								// �����
	static float time_in_pause;						// ����� ������� ������ ���� ���� �� �����
	static float time_enemy;						// ����� �� �������� ������� �����, ���� �������� ����� ������� ������ �� ����������
	static int scr_W;								// ������ ���������� ������
	static int scr_H;								// ������ ���������� ������
	static float scr_1;								// ���� ������� ������ ������
	static float scr_1w;							// ���� ������� ������ ������
	static v2f cam_p;								// ������� ������
	static v2f cur_p;								// ������� �������
	static Texture* texture;						// ����� ����� �������
	static Audio* audio;							// ����� ����� ������ � ������
	static enum GSTATE {main_menu, game} gState;	// ��������� ����
	static bool isPauseGame;						// ���� ���� �� �����

	static bool isSound_Music_On;					// ���-���� ������
	static bool isSound_Effects_On;					// ���-���� ������
	static bool isVideo_Smoth_On;					// �������� �����������
	static bool isVideo_VertSync_On;				// �������� ������������ ������������� (��� ������ �� - ����������� � 60 ���)
	static uint sound_Vol_Music;					// ��������� ������
	static uint sound_Vol_Effects;					// ��������� �������� ��������

public:

	static float GetDistance(v2f p1, v2f p2);							// ���������� ���������� �� ����� p1 �� ����� p2
	static sf::FloatRect GetVisible();									// ���������� ������� � ������ ������ ����
	static v2f GetNormalizePosition(v2f pos, float dist, float angle);	// ���������� ����� �� pos �� ���������� dist � ������� angle
	static float GetAngle(v2f p1, v2f p2);								// ���������� ���� �� p1 � p2

	static void MoveToAngle(Shape &shape, float speed, float angle);	// ������� ������ � ������� ����
};