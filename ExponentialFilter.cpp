#include "ExponentialFilter.h"

ExponentialFilter::ExponentialFilter()
{
  SampleInd = 0;
}

/*-- Kalman Filter --*/
double ExponentialFilter::start(double Xt){
    if( SampleInd < AVG_level-1 ){
      SampleInd++;
    }else{
      SampleInd = 0;
    }
    SampleRec[SampleInd] = Xt;
    SampleAVG = 0;
    int i = 0;
    for( i=0 ; i<AVG_level ; i++ ){
      SampleAVG += SampleRec[i];
    }  
    
    return SampleAVG / AVG_level;
}

// Set the default object
ExponentialFilter ExpFilter = ExponentialFilter();
