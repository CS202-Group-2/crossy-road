#include "../include/CSOUND.h"

CSOUND::CSOUND() {
	if (!backgroundSoundBuffer.loadFromFile("assets/sound/powerup.wav")) {
		cout << "Sound file not found" << endl;
	}
	backgroundSound.setBuffer(backgroundSoundBuffer);
	backgroundSound.setVolume(40);
	backgroundSound.setLoop(true);
}
void CSOUND::playBackgroundSound() {
	backgroundSound.play();
}