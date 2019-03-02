//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_LOADER_H
#define GRAPHICSPROJECT_LOADER_H

#include "headers.h"
#include "usage.h"
#include "algos.h"

void loadvertices(){
    ifstream file;
    char ch;
    long double one, two, three, r, g, b;
    string first, second, third;
    int a, b, c;
    char filename[] = "main.obj";
    file.open(filename);
    string str;
    seton3d(0,0,0);
    setonnormals(0,0,0);
    while(!file.eof()){
        getline(file,str);
        if(str[0] == 'v' && str[1] != 't' && str[1] != 'n'){
            stringstream ss(str);
            ss>>ch>>one>>two>>three;
            seton3d(one, two,three);
        }
        if(str[0] == 'v' && str[1] == 'n'){
            stringstream ss(str);
            ss>>ch>>one>>two>>three;
            setonnormals(one, two,three);
        }
        if(str[0] == 'f'){
            stringstream ss(str);
            ss>>ch>>first>>second>>third;
            a = stoi(first.substr(0,first.find("/")));
            b = stoi(second.substr(0,second.find("/")));
            c = stoi(third.substr(0,third.find("/")));
            setonface(a,b,c);
            a = stoi(first.substr(first.rfind("/")+1, first.size()- first.rfind("/")- 1));
            b = stoi(second.substr(second.rfind("/")+1, second.size()- second.rfind("/")- 1));
            c = stoi(third.substr(third.rfind("/")+1, third.size()- third.rfind("/")- 1));
            setonFacenormals(a,b,c);
        }
    }
    file.close();
}

void loadandrotate(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-600.0,600.0, -350.0,350.0);
    glBegin(GL_POINTS);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // glBegin(GL_TRIANGLES);
    matrix rmz = {{cos(anglz),-sin(anglz),0,0},{sin(anglz),cos(anglz),0,0},{0,0,1,0},{0,0,0,1}};
    matrix rmx = {{1,0,0,0},{0,cos(anglx),-sin(anglx),0},{0,sin(anglx),cos(anglx),0},{0,0,0,1}};
    matrix rmy = {{cos(angly),0,sin(angly),0},{0,1,0,0},{-sin(angly),0,cos(angly),0},{0,0,0,1}};
    matrix rm1 = matmultiply(rmy, matmultiply(rmx, rmz));
    matrix tm1 = {{cos(M_PI/5.25), -cos(M_PI/5.25), 0,0}, {sin(M_PI/5.25),sin(M_PI/5.25),1,0},{0,0,1,0},{0,0,0,1}};
    matrix sc1 = {{scal,0,0,0}, {0,scal,0,0},{0,0,scal,0},{0,0,0,1}};
    matrix cm = matmultiply(tm1, matmultiply(sc1, rm1));
    result = matmultiply(cm, original);
    for(int i=0; i<face[0].size(); i++){
        fillTriangle(result[0][face[0][i]]+transx + transx, result[1][face[0][i]]+transy,1.0,1.0,0.0, result[0][face[1][i]]+transx, result[1][face[1][i]]+transy,0.0,1.0,0.0,result[0][face[2][i]]+transx, result[1][face[2][i]]+transy,1.0,0.0,0.0);
    }
    glEnd();
    glutSwapBuffers();
}


#endif //GRAPHICSPROJECT_LOADER_H
