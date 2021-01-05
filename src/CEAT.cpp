#include "../include/CEAT.h"

CEAT::CEAT () {
	if (!jumpSoundBuffer.loadFromFile ("assets/sound/coin.wav")) {
		cout << "Sound file not found" << endl;
	}
	jumpSound.setBuffer (jumpSoundBuffer);
	jumpSound.setLoop (false);
}
void CEAT::playJumpSound () {
	jumpSound.play ();
}