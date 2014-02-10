#ifndef AAPPLICATION_H
#define AAPPLICATION_H
#include <QApplication>
#include <../include/age_widget.h>
namespace AGE2D
{
class ASystem
{
public:
	static void Init(int argc, char *argv[]);
	static int Go();
	static void SetSize(int width, int height);

	static int GetWidth();
	static int GetHeight();
	static int GetWidthOffset();
	static int GetHeightOffset();
	static AWidget * GetWidget();
	static int IsEngineInitialized();
	static int timeStep();
	static double frameRate();
	friend class AWidget;

private:
	ASystem();
	static int m_width;
	static int m_height;
	static int m_widthOffset;
	static int m_heightOffset;
	static bool is_init;
	static QApplication * m_application;
	static AWidget * m_widget;

};
}
#endif // AAPPLICATION_H





