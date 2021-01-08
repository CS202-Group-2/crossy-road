#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace std;

class CASSET {
private:
	CASSET();
	CASSET(const CASSET& other) {};
	CASSET& operator=(const CASSET&) {};

	void initSoundBuffer(string soundFilename);
	void initTexture(string textureFilename, bool isPlayer = false);
public:
	static CASSET& GetInstance() {
		static CASSET instance;
		return instance;
	}
	sf::Texture carT;
	sf::SoundBuffer carS;

	unordered_map<string, sf::SoundBuffer> soundBufferMap;
	unordered_map<string, sf::Texture> textureMap;
};
