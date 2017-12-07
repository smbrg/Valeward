#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class VisualEntity
{
protected:
	virtual void Draw() = 0;
	virtual void SetSprite(std::string path) = 0;
	virtual void SetPosition(float xpos, float ypos) = 0;
};