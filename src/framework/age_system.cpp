#include "../include/AGE2D.h"
#include "../include/age_system.h"
#include <iostream>

using namespace std;
QApplication * AGE_System::m_application;
AGE_Widget * AGE_System::m_widget;
int AGE_System::m_width;
int AGE_System::m_height;
int AGE_System::m_widthOffset;
int AGE_System::m_heightOffset;
bool AGE_System::is_init=false;

AGE_System::AGE_System()
{
}

int AGE_System::Go()
{
	if(!is_init)
	{
		return -1;
	}
	return m_application->exec ();
}

void AGE_System::SetSize(int width, int height )
{

	m_width=width;
	m_height=height;
    m_widthOffset = 0;
    m_widthOffset = 0;
    cout<<"set"<<m_height;
	if(!is_init)
	{
		return ;
	}
    m_widget->resize(width,height);
}

int AGE_System::GetWidth()
{
	return m_width;
}

int AGE_System::GetHeight()
{
	return m_height;
}

int AGE_System::GetWidthOffset()
{
    return m_widthOffset;
}

int AGE_System::GetHeightOffset()
{
    return m_heightOffset;
}

int AGE_System::IsEngineInitialized()
{
	return is_init;
}

void AGE_System::Init(int argc, char *argv[])
{
	m_application=new QApplication(argc,argv);
	m_widget=new AGE_Widget();
	SetSize(640,480);
	m_widget->show();
	is_init=true;
}

int AGE_System::timeStep()
{
	return getTimeStep();
}

double AGE_System::frameRate()
{
	return 1000.0/getTimeStep ();
}

