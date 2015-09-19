#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  // arduino
  port.setup("/dev/tty.usbserial-AI02KIGU", 9600);
  
  // max
  receiver.setup(PORT);
  receive = 0;
  
  // init
  start1 = false;
  start2 = false;
}

//--------------------------------------------------------------
void ofApp::update(){
  // arduino
  port.flush();
  while (receiver.hasWaitingMessages()) {
    ofxOscMessage m;
    receiver.getNextMessage(&m);
    if (m.getAddress() == "/value") {
      float value = m.getArgAsFloat(0);
      if ((value == 1025 || value == 1024) && !start2) {
        start2 = true;
        cout << "2\n";
        port.writeByte('S');
      }
      else if (((int)value) && !start1) {
        start1 = true;
        cout << "1\n";
        port.writeByte('T');
      }
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
