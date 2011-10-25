#include "QuasicrystalApp.h"
#include <cmath>
#include <iostream>


QuasicrystalApp::QuasicrystalApp() :
    k_(4), stripes_(27), center_(ofGetWidth() / 2), phase_(0.0),
    frameStart_(0.0)
{
}

QuasicrystalApp::~QuasicrystalApp()
{
    img_.clear();
}

//--------------------------------------------------------------
void QuasicrystalApp::setup()
{
    ofBackground(255, 255, 255);
    img_.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
}

//--------------------------------------------------------------
void QuasicrystalApp::update()
{
    unsigned char* pixels = img_.getPixels();
    int w = ofGetWidth();
    int h = ofGetHeight();

    for (double phase = phase_; phase < phase_ + TWO_PI; phase += TWO_PI / 30) {
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                double x = i - center_;
                double y = j - center_;
                double r = log(sqrt(x * x + y * y));
                double theta = atan2(y, x);
                double intensity = 0;
                for (double t = 0; t < PI; t += PI / k_) {
                    intensity += cos((theta * cos(t) - r * sin(t)) * stripes_ +
                                     phase);
                }
                intensity = static_cast<int>((intensity + k_) / (k_ * 2) * 255);
                pixels[j * w + i] = intensity;
            }
        }
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
