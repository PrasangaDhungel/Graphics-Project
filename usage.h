//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_USAGE_H
#define GRAPHICSPROJECT_USAGE_H

#include "headers.h"


void setonVertices(float x, float y, float z){
    originalVertices[0].push_back(x);
    originalVertices[1].push_back(y);
    originalVertices[2].push_back(z);
    originalVertices[3].push_back(1.0);
}

void setonnormals(float x, float y, float z){
    normals[0].push_back(x);
    normals[1].push_back(y);
    normals[2].push_back(z);
}

void setoncolors(float x, float y, float z){
    colors[0].push_back(x);
    colors[1].push_back(y);
    colors[2].push_back(z);
}

void setonnewcolors(float x, float y, float z){
    newcolors[0].push_back(x);
    newcolors[1].push_back(y);
    newcolors[2].push_back(z);
}


void setonface(int x, int y, int z){
    face[0].push_back(x);
    face[1].push_back(y);
    face[2].push_back(z);
}

void setonKa(float x, float y, float z){
    Ka[0].push_back(x);
    Ka[1].push_back(y);
    Ka[2].push_back(z);
}

void setonKd(float x, float y, float z){
    Kd[0].push_back(x);
    Kd[1].push_back(y);
    Kd[2].push_back(z);
}

void setonKs(float x, float y, float z){
    Ks[0].push_back(x);
    Ks[1].push_back(y);
    Ks[2].push_back(z);
}

#endif //GRAPHICSPROJECT_USAGE_H
