#include "QuasicrystalApp.h"
#include <cmath>
#include <iostream>
#include "CalculateThread.h"


const int QuasicrystalApp::THREADS = 8;


QuasicrystalApp::QuasicrystalApp() :
    k_(3), stripes_(37), center_(ofGetWidth() / 2), phase_(0.0),
    frameStart_(0.0)
{
}

QuasicrystalApp::~QuasicrystalApp()
{
    img_.clear();

    for (unsigned int i = 0; i < threads_.size(); ++i) {
        delete threads_[i];
    }
    threads_.clear();
}

//--------------------------------------------------------------
void QuasicrystalApp::setup()
{
    ofBackground(255, 255, 255);
    img_.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);

    int height = ofGetHeight();
    for (int i = 0; i < THREADS; ++i) {
        int y0 = i * (height / THREADS);
        int y1 = (i + 1) * (height / THREADS);
        threads_.push_back(new CalculateThread(img_, k_, stripes_, y0, y1));
    }
}

//--------------------------------------------------------------
void QuasicrystalApp::update()
{
    for (int i = 0; i < THREADS; ++i) {
        threads_[i]->setPhase(phase_);
        threads_[i]->startThread(false, false);
    }

    for (int i = 0; i < THREADS; ++i) {
        threads_[i]->waitForThread(false);
    }

    img_.update();
    phase_ += TWO_PI / 60;
}

//--------------------------------------------------------------
void QuasicrystalApp::draw()
{
    img_.draw(0, 0);
    float now = ofGetElapsedTimef();
    float frameTime = now - frameStart_;
    std::cout << "Frame " << ofGetFrameNum() << ": " << frameTime
              << " seconds" << std::endl;
    frameStart_ = now;
    ofSaveFrame();
}

//--------------------------------------------------------------
void QuasicrystalApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::mouseMoved(int x, int y )
{
}

//--------------------------------------------------------------
void QuasicrystalApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void QuasicrystalApp::dragEvent(ofDragInfo dragInfo)
{
}
