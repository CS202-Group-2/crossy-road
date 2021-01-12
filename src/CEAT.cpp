#include "../include/CEAT.h"

CEAT::CEAT () {
	if (!soundBuffer.loadFromFile ("assets/sound/coin.wav")) {
		cout << "Sound file not found" << endl;
	}
	sound.setBuffer (soundBuffer);
	sound.setLoop (false);
}
void CEAT::playSound () {
	sound.play ();
}