#include "../include/CGAMEOVER.h"

CGAMEOVER::CGAMEOVER () {
	if (!jumpSoundBuffer.loadFromFile ("assets/sound/gameover.wav")) {
		cout << "Sound file not found" << endl;
	}
	jumpSound.setBuffer (jumpSoundBuffer);
	jumpSound.setLoop (false);
}
void CGAMEOVER::playJumpSound () {
	jumpSound.play ();
}