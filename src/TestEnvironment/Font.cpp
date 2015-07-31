#include "Font.h"

std::string Font::TEXT_PATH = "Images/OpenSans-Regular.ttf";
std::string Font::MESSAGE_PATH = "Allo tous le monde ca va.";

Font::Font()
	:Text(TEXT_PATH,2,MESSAGE_PATH)
	, x(0)
	, y(0)
{
}

Font::~Font()
{
}

Font::Font(int x,int y)
	:Text(TEXT_PATH, 2, MESSAGE_PATH)
	, x(x)
	, y(y)	
{
	
}
