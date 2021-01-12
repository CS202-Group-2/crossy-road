#include "../include/CJUMP.h"

CJUMP::CJUMP () {
	if (!soundBuffer.loadFromFile ("assets/sound/jump.wav")) {
		cout << "Sound file not found" << endl;
	}
	sound.setBuffer (soundBuffer);
	sound.setLoop(false);
	sound.setVolume(20);
}
void CJUMP::playSound () {
	sound.play ();
}