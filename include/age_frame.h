#ifndef AGE_FRAME_H
#define AGE_FRAME_H
#include <../include/age_vector2d.h>

namespace AGE2D {
class AGE_Frame
{
public:
	AGE_Frame(AGE_Vector2D bl,AGE_Vector2D tr);
	AGE_Vector2D bottomLeft();
	AGE_Vector2D topRight();
protected:
	AGE_Vector2D bl;
	AGE_Vector2D tr;
};
}


#endif // AGE_FRAME_H




