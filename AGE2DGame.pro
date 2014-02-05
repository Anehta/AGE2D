#-------------------------------------------------
#
# Project created by QtCreator 2014-01-19T23:22:01
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += xml

TARGET = AGE2DGame
TEMPLATE = app

SOURCES += main.cpp\
    amainattribute.cpp \
    herosprite.cpp \
    bullet.cpp \
    mylayer.cpp \
    mylayerlistener.cpp \
    age_system.cpp \
    age_baselistener.cpp \
    age_eventlistener.cpp \
    age_geometric.cpp \
    age_widget.cpp \
    age_widgetevent.cpp \
    age_keyboardevent.cpp \
    age_layer.cpp \
    age_eventmgr.cpp \
    age_node.cpp \
    age_polygon.cpp \
    age_scene.cpp \
    age_sprite.cpp \
    age_texture.cpp \
    age_framelistener.cpp \
    age_mouselistener.cpp \
    age_mouseinfo.cpp \
    age_vector2d.cpp \
    age_point.cpp \
    age_vector3d.cpp \
    age_pointf.cpp \
    age_vector4d.cpp \
    age_spriteactor.cpp \
    age_cramera.cpp \
    age_utility.cpp \
    age_animation.cpp \
    age_frame.cpp \
    age_matrix4x4.cpp \
    age_animationset.cpp \
    age_accumulator.cpp

HEADERS  += \
    amainattribute.h \
    herosprite.h \
    bullet.h \
    mylayer.h \
    mylayerlistener.h \
    age_system.h \
    age_baselistener.h \
    age_eventlistener.h \
    age_eventsource.h \
    age_geometric.h \
    age_widget.h \
    age_keyboardevent.h \
    age_layer.h \
    age_eventmgr.h \
    age_node.h \
    age_polygon.h \
    age_scene.h \
    age_sprite.h \
    age_texture.h \
    age_framelistener.h \
    age_mouselistener.h \
    age_mouseinfo.h \
    age_vector2d.h \
    age_point.h \
    age_vector3d.h \
    age_pointf.h \
    age_vector4d.h \
    age_spriteactor.h \
    age_cramera.h \
    age_utility.h \
    age_animation.h \
    age_frame.h \
    age_matrix4x4.h \
    age_animationset.h \
    age_accumulator.h

CONFIG += mobility c++11
MOBILITY =

OTHER_FILES += \
    fshader.glsl \
    vshader.glsl \
    fshader2.fsh

RESOURCES += \
shader.qrc
