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
    int MAXLENGTH = 14;

    while (inFile) {
        inFile.getline(line, MAXCHAR);
        if (line[0] == 'v' && line[1] == ' ') {
            MAXLENGTH++;
        }
    }
    inFile.clear();
    inFile.seekg(0, ios::beg);

    float* vertices;
    vertices = new float[MAXLENGTH];
    string verticeSep = "v";
    string section;
    int index = -1;

    while ( inFile >> section ) {
        //inFile >> section;
        if (section == verticeSep) {
            //inFile.getline(line, MAXCHAR);
            index++;
            cout <<index<< endl;
            //cout << line<< endl;
            //inFile >> vertices[index++];
            //inFile >> vertices[index++];
            //inFile >> vertices[index++];
        }
    }

    for (int x = 0; x < MAXLENGTH; x++) {
     //   cout << vertices[x] << endl;
    }


    Object::verts = vertices;
    return;
}



Object::Object(const char *object_file_path) {
    LoadObject("/home/alexander/Desktop/GameEngine/Blender/OddBircks.obj");
}



