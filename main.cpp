#include "headers.h"
#include "glutfunctions.h"
#include "renderer.h"
using namespace std;


int main(int argc, char** argv) {
    globalVariablesInitializer();
    loadVertices();
    initWindow(&argc, argv, startx,starty,screenwidth,screenheight, "Graphics Project");
    glutReshapeFunc(changeSize);
    glutIdleFunc(Render);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(specialKeyFunction);
    glutMainLoop();
    exitWindow();
    return 0;
}