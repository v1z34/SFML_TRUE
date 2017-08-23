#include "Texture.h"

Texture::Texture(void)
{
	Load ( Cursor, "Cursor.png" );
	Load ( Quad, "Quad.png" );
}

void Texture::setSmoth(bool isSmooth)
{
	Cursor.setSmooth(isSmooth);
	Quad.setSmooth(isSmooth);
}

inline void Texture::Load( IMG& texture, const string& file )
{
	texture.loadFromFile("Resources/Texture/" + file );

}

Texture::~Texture(void)
{
}
