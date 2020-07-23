//
// Created by alexander on 2020-07-21.
//

#include "object.hpp"
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <GL/gl.h>

using namespace std;

const int MAXCHAR = 256;

void Object::LoadObject(const char * object_file_path) {
    ifstream inFile(object_file_path, ios::in);
    char line[MAXCHAR];
    int MAXLENGTH = 0;

    while (inFile) {
        inFile.getline(line, MAXCHAR);
        if (line[0] == 'v' && line[1] == ' ')
            MAXLENGTH++;
    }
    inFile.clear();
    inFile.seekg(0, ios::beg);

    GLfloat* vertices;
    vertices = new float[MAXLENGTH];
    string verticeSep = "v";
    string textureVerticeSep = "vt";
    string vertexNormalsSep = "vn";
    string faceSep = "f";
    string section;
    int index = 0;

    while ( inFile >> section ) {
        if (section == verticeSep) {
            inFile >> vertices[index++];
            inFile >> vertices[index++];
            inFile >> vertices[index++];
        }
    }
    Object::vertices = vertices;


    MAXLENGTH = 0;
    inFile.clear();
    inFile.seekg(0, ios::beg);
    while (inFile) {
        inFile.getline(line, MAXCHAR);
        if (line[0] == 'f' && line[1] == ' ')
            MAXLENGTH++;
    }
    inFile.clear();
    inFile.seekg(0, ios::beg);
    GLfloat* faces;
    faces = new float[100000];
    index = 0;
    string faceString;
    while ( inFile >> section ) {
        if (section == faceSep) {
            for (int x = 0; x < 3; x++) {
                inFile >> faceString;
                cout << faceString << endl;
                faces[index++] = Object::vertices[getGeoVertex(faceString) - 1];
                faces[index++] = Object::vertices[getTexVertex(faceString) - 1];
                faces[index++] = Object::vertices[getNormVertex(faceString) - 1];
            }
        }
    }

    Object::geoVertices = faces;


}

int Object::getGeoVertex(const string& faceString) {
    return stoi(faceString.substr(0, faceString.find('/')));
}
int Object::getTexVertex(const string& faceString) {
    return stoi(faceString.substr(faceString.find('/') + 1, faceString.find('/' , 1)));
}
int Object::getNormVertex(const string& faceString) {
    return stoi(faceString.substr(faceString.find('/', faceString.find('/' , 1) + 1) + 1, faceString.find('/', 1) + 1));
}


GLfloat* Object::getGeoVerts() {
    return vertices;
}


Object::Object(const char *object_file_path) {
    LoadObject("/home/alexander/Desktop/GameEngine/Blender/OddBircks.obj");
}



