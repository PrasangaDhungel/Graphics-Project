//
// Created by prasanga on 3/3/19.
//

#ifndef GRAPHICSPROJECT_LOADFROMTXT_H
#define GRAPHICSPROJECT_LOADFROMTXT_H

#include "headers.h"
#include "usage.h"
#include "algos.h"

void loadVertices(){
    ifstream file;
    char ch;
    float one, two, three,nx,ny,nz, r=0.4, g=0.4, bl=0.4;
    float kar, kag, kab, kdr, kdg, kdb, ksr, ksg, ksb;
    string first, second, third;
    int a, b, c;
    file.open(filename);
    string str;
    setonVertices(0,-6,10);
    setonnormals(0,0,0);
    setoncolors(1,1,1);
    setonnewcolors(0,0,0);
    setonKa(0,0,0);
    setonKd(0,0,0);
    setonKs(0,0,0);
    while(!file.eof()){
        getline(file,str);
        if(str[0] == 'v'){
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

void Render() {
    int ff, fs, ft;
    float p,q,r,multfactor,attenuation,spec,d=1,rx,ry,rz,specmult,Ns=51,lx,ly;
    for(int i=0; i<originalVertices[0].size(); i++){
        p = originalVertices[0][0] - originalVertices[0][i];
        q = originalVertices[1][0] - originalVertices[1][i];
        r = originalVertices[2][0] - originalVertices[2][i];
        attenuation = p*p + q*q +r*r;
        multfactor = (p * normals[0][i] + q * normals[1][i] + r * normals[2][i])/sqrt(attenuation);
        specmult = 2 * (p * normals[0][i] + q * normals[1][i] + r * normals[2][i]);
        rx = specmult * normals[0][i] - p;
        ry = specmult * normals[1][i] - q;
//        rz = specmult * normals[2][i] - r;
        spec = -(rx + ry)/sqrt(2 * (rx*rx +ry*ry));
        spec = pow(spec, Ns);
        if(multfactor>0){
            newcolors[0][i] = (Ka[0][i]*Ia + Kd[0][i] * multfactor *Id/(1+d*d)) * colors[0][i];
            newcolors[1][i] = (Ka[1][i]*Ia + Kd[1][i] * multfactor *Id/(1+d*d)) * colors[1][i];
            newcolors[2][i] = (Ka[2][i]*Ia + Kd[2][i] * multfactor *Id/(1+d*d)) * colors[2][i];
        }
        else{
            newcolors[0][i] = Ka[0][i]*Ia*colors[0][i];
            newcolors[1][i] = Ka[1][i]*Ia*colors[1][i];
            newcolors[2][i] = Ka[2][i]*Ia*colors[2][i];
        }
        if(spec != 0){
            newcolors[0][i] += Ks[0][i]*Id*spec*0.1;
            newcolors[1][i] += Ks[1][i]*Id*spec*0.1;
            newcolors[2][i] += Ks[2][i]*Id*spec*0.1;

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
    matrix sc1 = {{scal,0,0,0}, {0,scal,0,0},{0,0,scal,0},{0,0,0,1}};
    matrix cm =  matmultiply(sc1, rm1);
    result = matmultiply(cm, originalVertices);
    for(int i=0; i<face[0].size(); i++){
        ff = face[0][i];
        fs = face[1][i];
        ft = face[2][i];
        fillTriangle(result[0][ff], result[1][ff], result[2][ff],  newcolors[0][ff],newcolors[1][ff],newcolors[2][ff], result[0][fs], result[1][fs],result[2][fs], newcolors[0][fs],newcolors[1][fs],newcolors[2][fs],result[0][ft], result[1][ft],result[2][ft], newcolors[0][ft],newcolors[1][ft],newcolors[2][ft]);
    }
    depthbuf.clear();
    glEnd();
    glutSwapBuffers();
}

#endif //GRAPHICSPROJECT_LOADFROMTXT_H
