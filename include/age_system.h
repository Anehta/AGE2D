#ifndef AGE_APPLICATION_H
#define AGE_APPLICATION_H
#include <QApplication>
#include <../include/age_widget.h>
namespace AGE2D
{
class AGE_System
{
public:
	static void Init(int argc, char *argv[]);
	static int Go();
	static void SetSize(int width, int height);

	static int GetWidth();
	static int GetHeight();   
    static int GetWidthOffset();
    static int GetHeightOffset();

	static int IsEngineInitialized();
    static int timeStep();
    static double frameRate();
    friend class AGE_Widget;

private:
	AGE_System();
	static int m_width;
	static int m_height;
    static int m_widthOffset;
    static int m_heightOffset;
	static bool is_init;
	static QApplication * m_application;
	static AGE_Widget * m_widget;

};
}
#endif // AGE_APPLICATION_H





