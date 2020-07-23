//
// Created by alexander on 2020-07-21.
//

#ifndef GAMEENGINE_OBJECT_HPP
#define GAMEENGINE_OBJECT_HPP

#include <GL/gl.h>
#include <string>


class Object{
private:
    GLfloat* vertices{};
    GLfloat* geoVertices{};
    GLfloat* texVertices{};
    GLfloat* normVertices{};
public:
    void LoadObject(const char * object_file_path);
    explicit Object(const char *object_file_path);
    GLfloat* getGeoVerts();

    static int getGeoVertex(const std::string &faceString);
    static int getTexVertex(const std::string &faceString);
    static int getNormVertex(const std::string &faceString);
};




#endif //GAMEENGINE_OBJECT_HPP
