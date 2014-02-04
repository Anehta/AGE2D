#ifndef AKEYBOARDEVENT_H
#define AKEYBOARDEVENT_H

class AKeyBoardEvent
{
public:
    AKeyBoardEvent();
    int getKeyBoardEvent();
    void setKeyBoardType(int valueType);
private:
    int m_KeyBoardEvent;
};

#endif // AEVENT_H
