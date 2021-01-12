#include "../include/CGAMEOVER.h"

CGAMEOVER::CGAMEOVER () {
	if (!soundBuffer.loadFromFile ("assets/sound/gameover.wav")) {
		cout << "Sound file not found" << endl;
	}
	sound.setBuffer (soundBuffer);
	sound.setLoop (false);
}
void CGAMEOVER::playSound () {
	if (sound.getStatus() == sf::Music::Status::Stopped) sound.play ();
}