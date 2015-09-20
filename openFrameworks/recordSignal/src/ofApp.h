#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include <fstream>

#define PORT 9999

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxOscReceiver receiver;
    float receive;
  
    ofSerial port;
    float box;
    float start;
    float time;
  
    bool on;
};
