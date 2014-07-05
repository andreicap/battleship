
#include "mouse.h"
#include "stdafx.h"


Mouse::Mouse()
	: x(0), y(0), dx(0), dy(0),
	  leftPressed(false), rightPressed(false),
	  leftDown(false), rightDown(false)
{ }


void Mouse::Update(int x_, int y_)
{
    dx = x_ - x;
    dy = y_ - y;
    x = x_;
    y = y_;
}


void Mouse::RegisterListener(IMouseListener* listener)
{
    listeners.push_back(listener);
}


void Mouse::LeftButtonDown()
{
    std::vector<IMouseListener*>::iterator itr;
    for (itr = listeners.begin(); itr != listeners.end(); ++itr)
    {
        (*itr)->OnLeftMouseButtonDown(x, y);
    }
}


void Mouse::LeftButtonUp()
{
    std::vector<IMouseListener*>::iterator itr;
    for (itr = listeners.begin(); itr != listeners.end(); ++itr)
    {
        (*itr)->OnLeftMouseButtonUp(x, y);
    }
}


void Mouse::RightButtonDown()
{
    std::vector<IMouseListener*>::iterator itr;
    for (itr = listeners.begin(); itr != listeners.end(); ++itr)
    {
        (*itr)->OnRightMouseButtonDown(x, y);
    }
}


void Mouse::RightButtonUp()
{
    std::vector<IMouseListener*>::iterator itr;
    for (itr = listeners.begin(); itr != listeners.end(); ++itr)
    {
        (*itr)->OnRightMouseButtonUp(x, y);
    }
}


void Mouse::Move()
{
    std::vector<IMouseListener*>::iterator itr;
    for (itr = listeners.begin(); itr != listeners.end(); ++itr)
    {
        (*itr)->OnMouseMove(x, y);
    }
}



void Mouse::ReceiveLBtnDown()
{

}


void Mouse::ReceiveLBtnUp()
{

}


void Mouse::ReceiveRBtnDown()
{

}


void Mouse::ReceiveRBtnUp()
{

}


bool Mouse::WasLeftPressed()
{
	return leftPressed;
}


bool Mouse::WasRightPressed()
{
	return rightPressed;
}


bool Mouse::IsLeftDown()
{
	return leftDown;
}


bool Mouse::IsRightDown()
{
	return rightDown;
}

