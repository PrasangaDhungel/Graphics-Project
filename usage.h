//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_USAGE_H
#define GRAPHICSPROJECT_USAGE_H

#include "headers.h"


void seton3d(float x, float y, float z){
    original[0].push_back(x);
    original[1].push_back(y);
    original[2].push_back(z);
    original[3].push_back(1.0);
}

void setonnormals(float x, float y, float z){
    normals[0].push_back(x);
    normals[1].push_back(y);
    normals[2].push_back(z);
}

void setonFacenormals(float x, float y, float z){
    normals[0].push_back(x);
    normals[1].push_back(y);
    normals[2].push_back(z);
}


void setoncolors(float x, float y, float z){
    colors[0].push_back(x);
    colors[1].push_back(y);
    colors[2].push_back(z);
}

void setonface(int x, int y, int z){
    face[0].push_back(x);
    face[1].push_back(y);
    face[2].push_back(z);
}


#endif //GRAPHICSPROJECT_USAGE_H
