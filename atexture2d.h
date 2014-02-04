#ifndef ATEXTURE2D_H
#define ATEXTURE2D_H

#include <QGLFunctions>
#include <QImage>

class ATexture2D : public QGLFunctions,public QImage
{
public:
    ATexture2D();
    ATexture2D(QString filename);
    void loadFile(QString filename);
    int width();
    int height();
    GLuint getTextureId();
private:
    GLuint m_texID;
    int m_width;
    int m_height;
    void bindTexture();
    QString m_fileName;
};

#endif // ATEXTURE2D_H
