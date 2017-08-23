#pragma once
#include <SFML\Audio.hpp>

typedef sf::SoundBuffer Buff;
typedef unsigned int uint;

class Audio
{
public:

	Buff testBuff;
	sf::Sound testSound;
	sf::Music testMusic;

public:

	void setVolEffects(uint vol);
	void setVolMusic(uint vol);
	Audio(void);
	void stopMusic();
	~Audio(void);

private:

	inline void LoadSound(std::string file, sf::Sound& sound, sf::SoundBuffer& buffer);
	inline void LoadMusic(std::string file, sf::Music& music);
};