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

	Basic(void);					// Пустой конструктор вызывается путём наследования для получения доступа к полям этого класса
	Basic(void* init);				// Конструктор инициализации !ВЫЗЫВАЕТСЯ 1 РАЗ ПРИ ЗАПУСКЕ ПРОГРАММЫ
	~Basic(void);
	static void Reset();			// Обрабатываем время и позицию курсора в основном цикле

	// Конструкторы (Методы) для шейпов - perc_pos false если нужна конкретная точка позиции объекта
	// В случае perc_pos true объект втанет в позицию в процентном соотношении от высоты экрана
	static void ConstructShape(Shape& shp, v2f pos, v2f siz, IMG& png, const bool perc_pos = true);
	static void ConstructShape(Shape& shp, v2f pos, v2f siz, const bool perc_pos = true);

	// Конструктор для текста siz настроен на процентное соотношение 3-4 подходящий размер
	// Текст встаёт в конкретную позицию с настроенной оцентровкой
	static void ConstructText(sf::Text& text, v2f pos, float siz, sf::String str, sf::Font* font, sf::Color col = sf::Color());
	
public:

	static sf::RenderWindow* wnd;					// Наше окно
	static sf::Clock clock;							// Тик-так
	static sf::Event event;							// События
	static sf::View cam;							// Камера вида
	static sf::Font *font_freshman;					// Шрифт
	static Shape shpCursor;							// Шейп курсора

	static float time;								// Время
	static float time_in_pause;						// Время которое тикает если игра на паузе
	static float time_enemy;						// Время от которого зависят враги, если например нужно сделать эффект их замедления
	static int scr_W;								// Ширина разрешения экрана
	static int scr_H;								// Высота разрешения экрана
	static float scr_1;								// Один процент высоты экрана
	static float scr_1w;							// Один процент ширины экрана
	static v2f cam_p;								// Позиция камеры
	static v2f cur_p;								// Позиция курсора
	static Texture* texture;						// Набор ваших текстур
	static Audio* audio;							// Набор ваших звуков и музыки
	static enum GSTATE {main_menu, game} gState;	// Состояние игры
	static bool isPauseGame;						// Если игра на паузе

	static bool isSound_Music_On;					// Вкл-выкл музыки
	static bool isSound_Effects_On;					// Вкл-выкл звуков
	static bool isVideo_Smoth_On;					// Включить сглаживание
	static bool isVideo_VertSync_On;				// Включить вертикальную синхронизацию (для слабых пк - ограничение в 60 фпс)
	static uint sound_Vol_Music;					// Громкость музыки
	static uint sound_Vol_Effects;					// Громкость звуковых эффектов

public:

	static float GetDistance(v2f p1, v2f p2);							// Возвращает расстояние от точки p1 до точки p2
	static sf::FloatRect GetVisible();									// Возвращает позицию и размер камеры вида
	static v2f GetNormalizePosition(v2f pos, float dist, float angle);	// Возвращает точку от pos на расстояние dist в сторону angle
	static float GetAngle(v2f p1, v2f p2);								// Возвращает угол от p1 к p2

	static void MoveToAngle(Shape &shape, float speed, float angle);	// Двигать объект в сторону угла
};