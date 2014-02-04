#ifndef AGE_CRAMERA_H
#define AGE_CRAMERA_H

class AGE_Cramera
{
public:
    AGE_Cramera();
    void lookAt();
    void translate();
    void rotate();
    //这个是用来全局控制用户视角的，主要是做愤怒的小鸟那种拉伸之类的东西
};

#endif // AGE_CRAMERA_H
