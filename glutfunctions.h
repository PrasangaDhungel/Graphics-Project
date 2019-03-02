//
// Created by prasanga on 3/2/19.
//

#ifndef GRAPHICSPROJECT_GLUTFUNCTIONS_H
#define GRAPHICSPROJECT_GLUTFUNCTIONS_H

#include "headers.h"

void initWindow(int *argc, char **argv, int x, int y, int xsize, int ysize, const std::string &s){
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(x,y);
    glutInitWindowSize(xsize,ysize);
    glutCreateWindow(s.c_str());
}


void setPixel(int x, int y){
    glVertex2i(x, y);
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
    float ratio =  w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    if(key == 'a' || key == 'A'){
        transx -= 1;
    }
    if(key == 'd' || key == 'D'){
        transx += 1;
    }
    if(key == 'w' || key == 'W'){
        transy += 1;
    }
    if(key == 's' || key == 'S'){
        transy -= 1;
    }
    if(key == 'x'){
        anglx += 0.05;
    }
    if(key == 'X'){
        anglx -= 0.05;
    }
    if(key == 'y'){
        angly += 0.05;
    }
    if(key == 'Y'){
        angly -= 0.05;
    }
}

void specialKeyFunction(int key, int x, int y) {
    if ( key == GLUT_KEY_LEFT )
        anglz -= 0.05;
    else if ( key == GLUT_KEY_RIGHT )
        anglz += 0.05;
    else if ( key == GLUT_KEY_DOWN)
        scal -= 0.2;
    else if ( key == GLUT_KEY_UP )
        scal += 0.2;
    glutPostRedisplay();
}


#endif //GRAPHICSPROJECT_GLUTFUNCTIONS_H
