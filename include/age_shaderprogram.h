#ifndef AGE_SHADERPROGRAM_H
#define AGE_SHADERPROGRAM_H

#include <QGLShaderProgram>
#include <QString>
#include <../include/age_shader.h>
namespace AGE2D{
class AGE_ShaderProgram : public QGLShaderProgram
{
public:
    AGE_ShaderProgram();
    AGE_ShaderProgram(QString vshaderFilename,QString fshaderFilename);
    bool addVertexShader(QString vshaderFilename);
    bool addFragmentShader(QString fshaderFilename);
    void initShaderEffect(int value);
};
}


#endif // AGE_SHADERPROGRAM_H
