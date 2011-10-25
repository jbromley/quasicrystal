#pragma once
#include "ofMain.h"


class CalculateThread : public ofThread
{
public:
    CalculateThread(ofImage& img, int k, int stripes, int startY, int endY);
    void setPhase(double startPhase);

protected:
    virtual void threadedFunction();

private:
    ofImage& img_;
    int k_;
    int stripes_;
    int y0_;
    int y1_;
    double phase_;
    int width_;
    int height_;
    int center_;
};

