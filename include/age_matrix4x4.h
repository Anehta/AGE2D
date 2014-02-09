#ifndef AGE_MATRIX4X4_H
#define AGE_MATRIX4X4_H

#include <QMatrix4x4>

namespace AGE2D {
class AGE_Matrix4x4 : public QMatrix4x4
{
public:
    AGE_Matrix4x4();
    AGE_Matrix4x4(QMatrix4x4 matrix);
    AGE_Matrix4x4(float m11,float m12,float m13,float m14,
		  float m21,float m22,float m23,float m24,
		  float m31,float m32,float m33,float m34,
		  float m41,float m42,float m43,float m44);
};
}


#endif // AGE_MATRIX4X4_H
