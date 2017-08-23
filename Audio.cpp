#include "Audio.h"

void Audio::setVolEffects(uint vol)
{
	testSound.setVolume(vol);
}

void Audio::setVolMusic(uint vol)
{
	testMusic.setVolume(vol);
}

Audio::Audio(void)
{
	LoadSound("testSound.wav", testSound, testBuff);
	LoadMusic("testMusic.ogg", testMusic);
}

void Audio::stopMusic()
{
	testMusic.stop();
}

inline void Audio::LoadSound(std::string file, sf::Sound& sound, sf::SoundBuffer& buffer)
{
	buffer.loadFromFile("Resources/Sounds/"+file);
	sound.setBuffer(buffer);
}

inline void Audio::LoadMusic(std::string file, sf::Music& music)
{
	music.openFromFile("Resources/Music/"+file);
	music.setLoop(true);
}

Audio::~Audio(void)
{
}