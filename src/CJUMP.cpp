#include "../include/CJUMP.h"

CJUMP::CJUMP () {
	if (!jumpSoundBuffer.loadFromFile ("assets/sound/jump.wav")) {
		cout << "Sound file not found" << endl;
	}
	jumpSound.setBuffer (jumpSoundBuffer);
	jumpSound.setLoop(false);
}
void CJUMP::playJumpSound () {
	jumpSound.play ();
}