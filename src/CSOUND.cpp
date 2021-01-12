#include "../include/CSOUND.h"

CSOUND::CSOUND() {
	if (!soundBuffer.loadFromFile("assets/sound/powerup.wav")) {
		cout << "Sound file not found" << endl;
	}
	sound.setBuffer(soundBuffer);
	sound.setVolume(40);
	sound.setLoop(true);
}
void CSOUND::playSound() {
	sound.play();
}