#pragma once
#include "Text.h"
 
class Font :
	public Text
{
public:
	Font();
	Font(int x,int y);
	~Font();
	
	
private:
	int x, y;
	
	static std::string MESSAGE_PATH;
	static std::string TEXT_PATH;
};

