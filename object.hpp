//
// Created by alexander on 2020-07-21.
//

#ifndef GAMEENGINE_OBJECT_HPP
#define GAMEENGINE_OBJECT_HPP

#include <GL/gl.h>


class Object{
private:
    float * verts;
public:
    void LoadObject(const char * object_file_path);
    explicit Object(const char *object_file_path);
};




#endif //GAMEENGINE_OBJECT_HPP
