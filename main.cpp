#include "headers.h"
#include "glutfunctions.h"
#include "loadfromtxt.h"
using namespace std;


int main(int argc, char** argv) {
    txtloadvertices();
    initWindow(&argc, argv, startx,starty,screenwidth,screenheight, "Graphics Project");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(txtloadandrotate);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(specialKeyFunction);
    glutMainLoop();
    exitWindow();
    return 0;
}