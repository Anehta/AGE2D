#include "age_application.h"
 QApplication * AGE_Application::m_application;
 AGE2DWidget * AGE_Application::m_widiget;
  int AGE_Application::m_width;
  int AGE_Application::m_height;
bool AGE_Application::is_init=false;
AGE_Application::AGE_Application()
{
}

int AGE_Application::Go()
{
	if(!is_init)
	{
		return -1;
	}
	return m_application->exec ();
}

void AGE_Application::SetSize(int width, int height )
{
	if(!is_init)
	{
		return ;
	}
	m_width=width;
	m_height=height;
	m_widiget->setFixedSize (width,height);
}

int AGE_Application::IsEngineInitialized()
{
	return is_init;
}

void AGE_Application::Init(int argc, char *argv[])
{
	m_application=new QApplication(argc,argv);
	m_widiget=new AGE2DWidget();
	m_widiget->setFixedSize(640,480);
	m_widiget->show();
	is_init=true;
}
