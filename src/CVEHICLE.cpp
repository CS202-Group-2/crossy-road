#include "../include/CVEHICLE.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

void CVEHICLE::move(int x, int y) {
	//srand(time(NULL));
	mX = x + (rand()%10+1);
	mY = y;
}

void CVEHICLE::crash () {
	cout << "Crash sound" << endl;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile ("assets/sound/Car+Crash.wav")) {
		cout << "Cannot load vehicle sound" << endl;
	}
	sf::Sound sound;
	sound.setBuffer (buffer);
	sound.play ();
}