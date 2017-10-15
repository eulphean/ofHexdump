#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    void keyPressed(int key);
  
    void calcRGBTexture();
  
    // Input file.
    ofFile inputFile;
    vector<int> decimals;
  
    // Maximum and minimum.
    int maxDecimal;
    int minDecimal;
  
    // ofPath
    ofPath myPath;
  
    // ofPixels
    ofPixels rPixels;
    ofPixels gPixels;
    ofPixels bPixels;
    ofPixels rgbPixels;
  
    // All the textures
    ofTexture redTexture;
    ofTexture greenTexture;
    ofTexture blueTexture;
    ofTexture rgbTexture;
  
    // 3D Camera
    ofEasyCam cam;
};
