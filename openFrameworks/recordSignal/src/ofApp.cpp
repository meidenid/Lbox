#include "ofApp.h"

// text
std::ofstream sout("signal.txt");

int BOX = 1;

//--------------------------------------------------------------
void ofApp::setup(){
  // max
  receiver.setup(PORT);
  receive = 0;
  
  // init
  box = 0;
  start = 0;
  time = ofGetElapsedTimef();
  on = false;
  
  ofBackground(ofColor::black);
}

//--------------------------------------------------------------
void ofApp::update(){
  while (receiver.hasWaitingMessages()) {
    ofxOscMessage m;
    receiver.getNextMessage(&m);
    if (m.getAddress() == "/value") {
      float value = m.getArgAsFloat(0);
      if (value == 1024) { BOX = 1; }
      box = ((int)value & BOX) ? 1 : 0;
      if (box && !on) {
        on = true;
        float m = ofGetElapsedTimef();
        time = m - time;
        sout << "delay(" << time << ");\n";
        sout << "digitalWrite(13, HIGH);\n";
        ofBackground(ofColor::white);
        time = m;
      } else if (!box && on) {
        on = false;
        float m = ofGetElapsedTimef();
        time = m - time;
        sout << "delay(" << time << ");\n";
        sout << "digitalWrite(13, LOW);\n";
        ofBackground(ofColor::black);
        time = m;
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == 't') { sout << "\n"; }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
