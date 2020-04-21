#include "Arduino.h"

#ifndef ExponentialFilter_h
#define ExponentialFilter_h
#define AVG_level 16

class ExponentialFilter
{
  public:
    ExponentialFilter();
    double SampleRec[AVG_level];
    double start(double Xt);
  private:
    int SampleInd;
    double SampleAVG;
};

extern ExponentialFilter ExpFilter;

#endif
