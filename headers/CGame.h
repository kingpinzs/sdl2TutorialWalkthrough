#ifndef CGAME_H
#define CGAME_H

#include <string>

class CGame
{
public:
	CGame();
	~CGame();
private:
	void eventLoop();
	void update();
	void draw();
	void printErrors(std::string message);
};

#endif // CGAME_H