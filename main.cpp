#include "headers.h"
#include "glutfunctions.h"
#include "loader.h"
using namespace std;


int main(int argc, char** argv) {
    loadvertices();
    initWindow(&argc, argv, 0,0,1200,700, "Prasanga");
    glutReshapeFunc(changeSize);
    glutIdleFunc(loadandrotate);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(specialKeyFunction);
    glutMainLoop();
    return 0;
}