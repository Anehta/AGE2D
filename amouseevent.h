#ifndef AMOUSEEVENT_H
#define AMOUSEEVENT_H

class AMouseEvent
{
public:
    AMouseEvent();
    void setMouseEventType(int mouseEvent);
    void setMouseX(int mouseX);
    void setMouseY(int mouseY);

    int getMouseEventType();
    int getMouseX();
    int getMouseY();
private:
    int m_mouseEvent;
    int m_mouseX;
    int m_mouseY;
};

#endif // AMOUSEEVENT_H
