#pragma once

#include "ofMain.h"
#include <vector>


class CalculateThread;


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
    static const int THREADS;

    int k_;
    int stripes_;
    int center_;
    double phase_;
    ofImage img_;
    float frameStart_;
    std::vector<CalculateThread*> threads_;
};
