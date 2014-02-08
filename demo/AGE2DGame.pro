#-------------------------------------------------
#
# Project created by QtCreator 2014-01-19T23:22:01
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += xml multimedia

TARGET = AGE2DGame
TEMPLATE = app

SOURCES += \
    background.cpp \
    bullet.cpp \
    game.cpp \
    hero.cpp \
    main.cpp \
    ../src/shader/age_shader.cpp \
    ../src/shader/age_shaderprogram.cpp \
    ../src/render/age_accumulator.cpp \
    ../src/render/age_animation.cpp \
    ../src/render/age_animationset.cpp \
    ../src/render/age_cramera.cpp \
    ../src/render/age_frame.cpp \
    ../src/render/age_framelistener.cpp \
    ../src/render/age_geometric.cpp \
    ../src/render/age_node.cpp \
    ../src/render/age_sprite.cpp \
    ../src/render/age_spriteactor.cpp \
    ../src/render/age_texture.cpp \
    ../src/math/age_matrix4x4.cpp \
    ../src/math/age_point.cpp \
    ../src/math/age_pointf.cpp \
    ../src/math/age_polygon.cpp \
    ../src/math/age_vector2d.cpp \
    ../src/math/age_vector3d.cpp \
    ../src/math/age_vector4d.cpp \
    ../src/listener/age_baselistener.cpp \
    ../src/listener/age_eventlistener.cpp \
    ../src/listener/age_eventmgr.cpp \
    ../src/listener/age_keyboardevent.cpp \
    ../src/listener/age_keylistener.cpp \
    ../src/listener/age_mouselistener.cpp \
    ../src/listener/agewidgetevent.cpp \
    ../src/info/age_mouseinfo.cpp \
    ../src/framework/age_application.cpp \
    ../src/framework/age_layer.cpp \
    ../src/framework/age_scene.cpp \
    ../src/framework/age_utility.cpp \
    ../src/framework/age_widget.cpp \
    ../src/framework/age_widgetevent.cpp \
    ../src/framework/amainattribute.cpp \
    ../src/framework/age_system.cpp \
    diamond.cpp \
    gamescene.cpp \
    ../src/audio/age_audio.cpp

HEADERS  += \
    ../include/age_accumulator.h \
    ../include/age_animation.h \
    ../include/age_animationset.h \
    ../include/age_application.h \
    ../include/age_baselistener.h \
    ../include/age_cramera.h \
    ../include/age_eventlistener.h \
    ../include/age_eventmgr.h \
    ../include/age_eventsource.h \
    ../include/age_frame.h \
    ../include/age_framelistener.h \
    ../include/age_geometric.h \
    ../include/age_keyboardevent.h \
    ../include/age_keylistener.h \
    ../include/age_layer.h \
    ../include/age_matrix4x4.h \
    ../include/age_mouseinfo.h \
    ../include/age_mouselistener.h \
    ../include/age_node.h \
    ../include/age_point.h \
    ../include/age_pointf.h \
    ../include/age_polygon.h \
    ../include/age_scene.h \
    ../include/age_shader.h \
    ../include/age_shaderprogram.h \
    ../include/age_sprite.h \
    ../include/age_spriteactor.h \
    ../include/age_system.h \
    ../include/age_texture.h \
    ../include/age_utility.h \
    ../include/age_vector2d.h \
    ../include/age_vector3d.h \
    ../include/age_vector4d.h \
    ../include/age_widget.h \
    ../include/amainattribute.h \
    ../include/background.h \
    ../include/bullet.h \
    ../include/game.h \
    ../include/hero.h \
    ../include/herolistener.h \
    ../include/mylayer.h \
    ../include/mylayerlistener.h \
    background.h \
    bullet.h \
    game.h \
    hero.h \
    ../include/AGE2D.h \
    diamond.h \
    gamescene.h \
    ../include/age_audio.h

CONFIG += mobility c++11
MOBILITY =

OTHER_FILES += \
    fshader.glsl \
    vshader.glsl \
    fshader2.fsh

RESOURCES += \
shader.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../src/freetype/ -lfreetype
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../src/freetype/ -lfreetyped
else:unix: LIBS += -L$$PWD/../src/freetype/ -lfreetype

INCLUDEPATH += $$PWD/../src/freetype
DEPENDPATH += $$PWD/../src/freetype

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/libfreetype.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/libfreetyped.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/freetype.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../src/freetype/freetyped.lib
else:unix: PRE_TARGETDEPS += $$PWD/../src/freetype/libfreetype.a
