#include <age_keyboardevent.h>

AGE_KeyBoardEvent::AGE_KeyBoardEvent()
{
    m_KeyBoardEvent = 0;
}

void AGE_KeyBoardEvent::setKeyBoardType(int valueType)
{
    m_KeyBoardEvent = valueType;
}

int AGE_KeyBoardEvent::getKeyBoardEvent()
{
    return m_KeyBoardEvent;
}
