#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class MediaPlayer
{
public:
	virtual void play(string audioType, string fileName) = 0;
};

class AdvancedMediaPlayer
{
public:
	virtual void playVlc(string fileName) = 0;
	virtual void playMp4(string fileName) = 0;
};

class VlcPlayer: public AdvancedMediaPlayer
{
public:
	void playVlc(string fileName)
	{
		cout << "Playing vlc file. Name: " << fileName << endl;
	}

	void playMp4(string fileName)
	{
		//nothing
	}
};

class Mp4Player: public AdvancedMediaPlayer
{
public:
	void playVlc(string fileName)
	{
		//nothing
	}

	void playMp4(string fileName)
	{
		cout << "Playing mp4 file. Name: " << fileName << endl;
	}
};

class MediaAdapter: public MediaPlayer
{
private:
	AdvancedMediaPlayer *advancedMusicPlayer;

public:
	MediaAdapter(string audioType)
	{
		if (audioType.compare("vlc") == 0)
		{
			advancedMusicPlayer = new VlcPlayer();
		}
		else if (audioType.compare("mp4") == 0)
		{
			advancedMusicPlayer = new Mp4Player();
		}
	}

	void play(string audioType, string fileName)
	{
		if (audioType.compare("vlc") == 0)
		{
			advancedMusicPlayer->playVlc(fileName);
		}
		else if (audioType.compare("mp4") == 0)
		{
			advancedMusicPlayer->playMp4(fileName);
		}
	}
};

class AudioPlayer: public MediaPlayer
{
private:
	MediaAdapter *mediaAdapter;

public:
	void play(string audioType, string fileName)
	{
		if (audioType.compare("mp3") == 0)
		{
			cout << "Playing mp3 file. Name: " << fileName << endl;
		}
		else if ((audioType.compare("vlc") == 0)
			  || (audioType.compare("mp4") == 0))
		{
			mediaAdapter = new MediaAdapter(audioType);
			mediaAdapter->play(audioType, fileName);
		}
		else
		{
			cout << "Invalid media. " << audioType << " format not supported" << endl;
		}
	}
};

int main(int argc, char** argv)
{
	AudioPlayer *audioPlayer = new AudioPlayer();
	
	audioPlayer->play("mp3", "beyond the horizon.mp3");
	audioPlayer->play("mp4", "alone.mp4");
	audioPlayer->play("vlc", "far far away.vlc");
	audioPlayer->play("mp4", "mind me.avi");
	return 0;
}
