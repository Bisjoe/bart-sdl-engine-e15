#pragma once
#include "Common.h"
class Audio
{

public:
	Audio();
	~Audio();
	void PlayMusic(const std::string& song);
	void PlayMusic(const std::string& song, const int& volume);
	void PlayMusic(const std::string& song, const int& volume, const int& fadeInMs);
	void PlayMusicLooped(const std::string& song);
	void ChangeMusicVolume(const int& volume);
private:

	//SoundFX* GetSound(const std::string& path);
	//Music* GetMusic(const std::string& path);
	
};

