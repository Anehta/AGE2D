#ifndef AGE_APPLICATION_H
#define AGE_APPLICATION_H
#include <QApplication>
#include <agewidget.h>
class AGE_Application
{
public:
	static void Init(int argc, char *argv[]);
	static int Go();
	static void SetSize(int width, int height);
	static int IsEngineInitialized();
private:
	AGE_Application();
	static int m_width;
	static int m_height;
	static bool is_init;
	static QApplication * m_application;
	static AGE2DWidget * m_widiget;
};

#endif // AGE_APPLICATION_H





