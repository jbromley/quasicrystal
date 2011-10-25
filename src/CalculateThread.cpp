#include "CalculateThread.h"
#include <cmath>


CalculateThread::CalculateThread(ofImage& img, int k, int stripes,
                                 int startY, int endY) :
    img_(img), k_(k), stripes_(stripes), y0_(startY), y1_(endY), phase_(0.0),
    width_(ofGetWidth()), height_(ofGetHeight()), center_(width_ / 2)
{
}

void
CalculateThread::threadedFunction()
{
    unsigned char* pixels = img_.getPixels();

    for (double phase = phase_; phase < phase_ + TWO_PI; phase += TWO_PI / 30) {
        for (int j = y0_; j < y1_; ++j) {
            for (int i = 0; i < width_; ++i) {
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
                pixels[j * width_ + i] = intensity;
            }
        }
    }
}

void
CalculateThread::setPhase(double phase)
{
    phase_ = phase;
}
