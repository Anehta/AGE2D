#include <../include/age_frame.h>
namespace AGE2D
{
AGE_Frame::AGE_Frame(AGE_Vector2D bl,AGE_Vector2D tr)
{
	this->bl=bl;
	this->tr=tr;
}

AGE_Vector2D AGE_Frame::bottomLeft()
{
	return bl;
}

AGE_Vector2D AGE_Frame::topRight()
{
	return tr;
}

}
