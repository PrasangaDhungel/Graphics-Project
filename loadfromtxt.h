//
// Created by prasanga on 3/3/19.
//

#ifndef GRAPHICSPROJECT_LOADFROMTXT_H
#define GRAPHICSPROJECT_LOADFROMTXT_H

#include "headers.h"
#include "usage.h"
#include "algos.h"

void txtloadvertices(){
    ifstream file;
    char ch;
    float one, two, three,nx,ny,nz, r=0.4, g=0.4, bl=0.4;
    float kar, kag, kab, kdr, kdg, kdb, ksr, ksg, ksb;
    string first, second, third;
    int a, b, c;
    float p,q,multfactor;
    char filename[] = "try.txt";
    file.open(filename);
    string str;
    setonVertices(0,-6.5,1);
    setonnormals(0,0,0);
    setoncolors(1,1,1);
    setonnewcolors(0,0,0);
    setonKa(0,0,0);
    setonKd(0,0,0);
    setonKs(0,0,0);
    while(!file.eof()){
        getline(file,str);
        if(str[0] == 'v' && str[1] != 't' && str[1] != 'n'){
            stringstream ss(str);
            ss>>ch>>one>>two>>three>>nx>>ny>>nz>>r>>g>>bl>>kar>>kag>>kab>>kdr>>kdg>>kdb>>ksr>>ksg>>ksb;
            setonVertices(one, two,three);
            setonnormals(nx, ny, nz);
            setoncolors(r,g,bl);
            setonnewcolors(0,0,0);
            setonKa(kar,kag, kab);
            setonKd(kdr,kdg, kdb);
            setonKs(ksr,ksg, ksb);
        }
        else if(str[0] == 'f'){
            stringstream ss(str);
            ss>>ch>>a>>b>>c;
            setonface(a,b,c);
        }
    }
    file.close();

}

void txtloadandrotate(void) {
    int ff, fs, ft;
    float p,q,r,multfactor;
    for(int i=0; i<originalVertices[0].size(); i++){
        p = originalVertices[0][0] - originalVertices[0][i];
        q = originalVertices[1][0] - originalVertices[1][i];
        r = originalVertices[2][0] - originalVertices[2][i];
        multfactor = (p * normals[0][i] + q * normals[1][i] + r * normals[2][i])/sqrt(p*p + q*q + r*r);
        if(multfactor>0){
            newcolors[0][i] = 0.1 + colors[0][i] * multfactor;
            newcolors[1][i] = 0.1 + colors[1][i] * multfactor;
            newcolors[2][i] = 0.1 + colors[2][i] * multfactor;
        }
        else{
            newcolors[0][i] = colors[0][i]*0.3;
            newcolors[1][i] = colors[1][i]* 0.3;
            newcolors[2][i] = colors[2][i]*0.3;
        }
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-screenwidth/2.0,screenwidth/2.0, -screenheight/2.0,screenheight/2.0);
    glBegin(GL_POINTS);

    matrix rmz = {{cos(anglz),-sin(anglz),0,0},{sin(anglz),cos(anglz),0,0},{0,0,1,0},{0,0,0,1}};
    matrix rmx = {{1,0,0,0},{0,cos(anglx),-sin(anglx),0},{0,sin(anglx),cos(anglx),0},{0,0,0,1}};
    matrix rmy = {{cos(angly),0,sin(angly),0},{0,1,0,0},{-sin(angly),0,cos(angly),0},{0,0,0,1}};
    matrix rm1 = matmultiply(rmy, matmultiply(rmx, rmz));
    matrix tm1 = {{cos(M_PI/5.25), -cos(M_PI/5.25), 0,0}, {sin(M_PI/5.25),sin(M_PI/5.25),1,0},{0,0,1,0},{0,0,0,1}};
    matrix sc1 = {{scal,0,0,0}, {0,scal,0,0},{0,0,scal,0},{0,0,0,1}};
    matrix cm = matmultiply(tm1, matmultiply(sc1, rm1));
    result = matmultiply(cm, originalVertices);
    for(int i=0; i<face[0].size(); i++){
        ff = face[0][i];
        fs = face[1][i];
        ft = face[2][i];
        fillTriangle(result[0][ff]+transx, result[1][ff]+transy,newcolors[0][ff],newcolors[1][ff],newcolors[2][ff], result[0][fs]+transx, result[1][fs]+transy,newcolors[0][fs],newcolors[1][fs],newcolors[2][fs],result[0][ft]+transx, result[1][ft]+transy,newcolors[0][ft],newcolors[1][ft],newcolors[2][ft]);
    }
    glEnd();
    glutSwapBuffers();
}


#endif //GRAPHICSPROJECT_LOADFROMTXT_H
