//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_HEADERS_H
#define GRAPHICSPROJECT_HEADERS_H

#include<GL/glut.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <cstring>

using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)

typedef std::vector<std::vector<float>  > matrix;
typedef std::vector<std::vector<int>  > matrixint;

matrix originalVertices(4);
matrix result(4);
matrixint face(3);
matrix normals(3);
matrix colors(3);
matrix newcolors(3);
matrixint facenormals(3);
matrix Ka(3);
matrix Kd(3);
matrix Ks(3);
//matrix projectionMatrix = {};
char filename[] = "object.txt";
float anglz, anglx, angly, transx, transy, scal,lightangle;
int screenwidth = 1200;
int screenheight = 600;
int startx = 90;
int starty = 90;
int lightmode = 0;
float Ia = 0.35, Id = 1.0;
float isoangle = M_PI / 5.25;
float lightinitx, lightinity, lightinitz;

void globalVariablesInitializer() {
    if(strcmp(filename, "object.txt")==0) {
        anglz = -0.85f;
        anglx = -0.3;
        angly = 0.35;
        transx = 0;
        transy = 0;
        scal = 7;
        lightangle = 2;
        lightinitx = 120;
        lightinity = 0;
        lightinitz = 20;
    }
    else if(strcmp(filename, "try.txt")==0){
        anglz = 0.9f;
        anglx = 0;
        angly = 0;
        transx = 0;
        transy = 0;
        scal = 40;
        lightangle = 2;
        lightangle = 2;
        lightinitx = -15;
        lightinity = -42;
        lightinitz = 18.5;
    }
}
void logstates(){
    cout<<"Anglz: "<<anglz<<" "<<"Angley: "<<angly<<" "<<"Anglex: "<<anglx<<endl;
    cout<<"Scal: "<<scal<<endl;
    cout<<"LightSource: "<<originalVertices[0][0]<<" "<<originalVertices[1][0]<<" "<<originalVertices[2][0]<<endl;
    cout<<"Lightangle: "<<lightangle<<endl;
    cout<<"Light Intensities: "<<Ia<<" "<<Id<<endl;
}

map<pair<int, int>,  float> depthbuf;
matrix matmultiply(const matrix & a, const matrix & b){
    std::vector<std::vector<float>  > c(a.size());
    float sum;
    rep(i,0,a.size()){
        rep(j,0,b[0].size()){
            sum=0;
            rep(k,0,b.size()){
                sum+= a[i][k]*b[k][j];
            }
            c[i].push_back(sum);
        }
    }
    return c;
}


#endif //GRAPHICSPROJECT_HEADERS_H
