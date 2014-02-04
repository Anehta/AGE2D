#include "age_mouseinfo.h"

AGE_MouseInfo::AGE_MouseInfo()
{
    m_mouseX = 0;
    m_mouseY = 0;
}

int AGE_MouseInfo::getMouseX()
{
    return m_mouseX;
}

int AGE_MouseInfo::getMouseY()
{
    return m_mouseY;
}

void AGE_MouseInfo::setMouseX(int mouseX)
{
    m_mouseX = mouseX;
}

void AGE_MouseInfo::setMouseY(int mouseY)
{
    m_mouseY = mouseY;
}

