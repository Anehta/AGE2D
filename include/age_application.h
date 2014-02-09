#ifndef AGE_APPLICATION2_H
#define AGE_APPLICATION2_H

#include <QApplication>
#include "AGE2D.h"
#include "age_widget.h"
namespace AGE2D {
class AGE_Wdiget;

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
    static AGE_Widget * m_widiget;
};

}

#endif // AGE_APPLICATION_H

