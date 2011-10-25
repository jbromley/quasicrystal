#pragma once

#include "ofMain.h"

class QuasicrystalApp : public ofBaseApp
{
public:
    QuasicrystalApp();
    ~QuasicrystalApp();
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

private:
    int k_;
    int stripes_;
    int center_;
    double phase_;
    ofImage img_;
    float frameStart_;
};
