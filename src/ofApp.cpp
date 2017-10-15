// Author: Amay Kataria
// Date: 10/16/2017
// Description: Utility to take a decimal formatted hexdump and convert
// it into R, G, B and RGB textures.

#include "ofApp.h"
#include "string.h"

using namespace std;

ofPoint center;
int texture_Size = 1024;
int currentTexture = -1;

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(ofColor::black);
  
  // Read the decimal file and store it in memory.
  inputFile.open("howtostillmindConverted.txt");
  
  string stringDec;
  
  // Set the max and min to arbitrarily large numbers.
  maxDecimal = -9999;
  minDecimal = 9999;
  
  if (inputFile.is_open())
  {
    while (getline(inputFile, stringDec))
    {
      // Convert string to decimal and push into the vector.
      int decimal = stoi(stringDec);
      
      // Calculate maxima.
      if (decimal > maxDecimal) {
        maxDecimal = decimal;
      }
      
      // Calculate minima.
      if (decimal < minDecimal) {
        minDecimal = decimal;
      }
      
      decimals.push_back(decimal);
    }
    
    // Close the file
    inputFile.close();
    cout << "Success: File read successfully.";
  } else {
    cout << "Unable to open this file." << endl;
  }
  
  // Allocate new pixels.
  rPixels.allocate(1024, 1024, OF_PIXELS_RGB);
  gPixels.allocate(1024, 1024, OF_PIXELS_RGB);
  bPixels.allocate(1024, 1024, OF_PIXELS_RGB);
  rgbPixels.allocate(1024, 1024, OF_PIXELS_RGB);

  int s = 0;
  // Iterate through the pixels.
  for (int x = 0; x < rPixels.getWidth(); x++)
  {
    for (int y = 0; y < rPixels.getHeight(); y++)
    {
      int val = decimals[s];
      
      ofColor redColor(val, 0, 0);
      ofColor greenColor(0, val, 0);
      ofColor blueColor(0, 0, val);

      // Set the color at the current position.
      rPixels.setColor(x, y, redColor);
      gPixels.setColor(x, y, greenColor);
      bPixels.setColor(x, y, blueColor);
      
      s = s + 1;
    }
  }
  
  // Load our pixels into a texture.
  redTexture.loadData(rPixels);
  greenTexture.loadData(gPixels);
  blueTexture.loadData(bPixels);
}

//--------------------------------------------------------------
void ofApp::update() {
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  switch (currentTexture) {
    case 1:
      redTexture.draw(0, 0);
      break;
      
    case 2:
      greenTexture.draw(0, 0);
      break;
      
    case 3:
      blueTexture.draw(0, 0);
      break;
      
    case 4:
      calcRGBTexture();
      rgbTexture.draw(0, 0);
      break;
    
    default:
      break;
  }
}

void ofApp::calcRGBTexture() {
  int s = 0;
  for (int x = 0; x < rgbPixels.getWidth(); x++)
  {
    for (int y = 0; y < rgbPixels.getHeight(); y++)
    {
      ofColor rgbColor (decimals[s], decimals[s+1], decimals[s+2]);
      rgbPixels.setColor(x, y, rgbColor);
      s = s + 3;
    }
  }
  
  rgbTexture.loadData(rgbPixels);
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case 49:
      currentTexture = 1;
      break;
      
    case 50:
      currentTexture = 2;
      break;
      
    case 51:
      currentTexture = 3;
      break;
      
    case 52:
      currentTexture = 4;
      break;
      
    default:
      break;
  }
}
