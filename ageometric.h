#ifndef AGEOMETRIC_H
#define AGEOMETRIC_H

#include <QGLFunctions>

class AGeometric : public QGLFunctions
{
public:
    AGeometric();
    ~AGeometric();
    void initRectGeometric(int width,int height);
    GLuint * getVboId();
    int width();
    int height();
    void setWidth(int w);
    void setHeight(int h);
private:
    GLuint * m_vboId;
    int m_width;
    int m_height;
    void initializeAll();
};

#endif // AGEOMETRIC_H
