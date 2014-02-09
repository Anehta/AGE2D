#include <../include/age_shaderprogram.h>
#include <qdebug.h>

namespace AGE2D
{
AGE_ShaderProgram::AGE_ShaderProgram()
{

}

AGE_ShaderProgram::AGE_ShaderProgram(QString vshaderFilename, QString fshaderFilename)
{
    addVertexShader(vshaderFilename);
    addVertexShader(fshaderFilename);

    if(!link())
    {
	qDebug()<<"error in shader link";
    }

}
bool AGE_ShaderProgram::addVertexShader(QString vshaderFilename)
{
    if(!addShaderFromSourceFile(QGLShader::Vertex,vshaderFilename))
    {
	qDebug()<<"error in addShaderFromSourceFile():QGLShader::Vertex";
	return false;
    }
    return true;
}


bool AGE_ShaderProgram::addFragmentShader(QString fshaderFilename)
{
    if(!addShaderFromSourceFile(QGLShader::Fragment,fshaderFilename))
    {
	qDebug()<<"error in addShaderFromSourceFile()::QGLShader::Fragment";
	return false;
    }
    return true;

}

void AGE_ShaderProgram::initShaderEffect(int value)
{

}
}

