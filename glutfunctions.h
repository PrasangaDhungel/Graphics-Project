//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_GLUTFUNCTIONS_H
#define GRAPHICSPROJECT_GLUTFUNCTIONS_H

#include "headers.h"

void initWindow(int *argc, char **argv, int x, int y, int xsize, int ysize, const std::string &s){
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(x,y);
    glutInitWindowSize(xsize,ysize);
    glutCreateWindow(s.c_str());
}

void putpixel(int x, int y, float r, float g, float b){
    glColor3f(r, g, b);
    glVertex2i(x, y);
}

void exitWindow(){
    glEnd();
    glFlush();
    glutMainLoop();
}

void changeSize(int w, int h) {
    if (h == 0)
        h = 1;
    float ratio =  w * 1.0f / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    else if(key == 'a' || key == 'A'){
        transx -= 5;
    }
    else if(key == 'd' || key == 'D'){
        transx += 5;
    }
    else if(key == 'w' || key == 'W'){
        transy += 5;
    }
    else if(key == 's' || key == 'S'){
        transy -= 5;
    }
    else if(key == 'x' && lightmode == 0){
        anglx += 0.05;
    }
    else if(key == 'x' && lightmode == 1){
        originalVertices[0][0] += 0.5;
    }
    else if(key == 'X' && lightmode == 0){
        anglx -= 0.05;
    }
    else if(key == 'X' && lightmode == 1){
        originalVertices[0][0] -= 0.5;
    }
    else if(key == 'y' && lightmode == 0){
        angly += 0.05;
    }
    else if(key == 'Y' && lightmode == 0){
        angly -= 0.05;
    }
    else if(key == 'y' && lightmode == 1){
        originalVertices[1][0] += 0.5;
    }
    else if(key == 'Y' && lightmode == 1){
        originalVertices[1][0] -= 0.5;
    }
    else if(key == 'z' && lightmode == 1){
        originalVertices[2][0] += 0.5;
    }
    else if(key == 'Z' && lightmode == 1){
        originalVertices[2][0] -= 0.5;
    }
    else if(key == 'L' || key == 'l'){
        lightmode = 1 - lightmode;
    }
    else if(key == 'i'){
        Ia += 0.02;
    }
    else if(key == 'I'){
        Ia -= 0.02;
    }
    logstates();
}

void specialKeyFunction(int key, int x, int y) {
    if ( key == GLUT_KEY_LEFT ) {
        anglz -= 0.05;
    }
    else if ( key == GLUT_KEY_RIGHT ) {
        anglz += 0.05;
    }
    else if ( key == GLUT_KEY_DOWN)
        scal -= 0.2;
    else if ( key == GLUT_KEY_UP )
        scal += 0.2;
    logstates();
    glutPostRedisplay();
}


#endif //GRAPHICSPROJECT_GLUTFUNCTIONS_H
