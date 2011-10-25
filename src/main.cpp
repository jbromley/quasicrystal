#include "ofMain.h"
#include "QuasicrystalApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main(int argc, char* argv[])
{

    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 512, 512, OF_WINDOW);

    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new QuasicrystalApp());
    return EXIT_SUCCESS;
}
