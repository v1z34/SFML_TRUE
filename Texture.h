#pragma once
#include<SFML\Graphics.hpp>
#include<sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <memory>
#include <cmath>

typedef sf::Texture IMG;

using std::cout;
using std::endl;
using std::to_string;
using std::cos; 
using std::cosf;
using std::sin;
using std::sinf;
using std::atanf;
using std::make_shared;

typedef sf::Texture IMG;
using std::vector;
using std::string;
using std::shared_ptr;

class Texture
{
private: 
	
	inline void Load(IMG& texture, const string& file);

public: 

	IMG Cursor;
	IMG Quad;

	Texture();
	void setSmoth(bool isSmooth);
	~Texture(void);
};