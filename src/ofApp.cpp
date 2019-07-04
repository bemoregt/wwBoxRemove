#include "ofApp.h"
#include <iostream>

using namespace ofxCv;
using namespace cv;
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

    filePath= "/Users/kerbal/Desktop/box.jpg";
    before.load(filePath);
    ofmask.allocate(before.getWidth(), before.getHeight(), OF_IMAGE_COLOR);
    after.allocate(before.getWidth(), before.getHeight(), OF_IMAGE_COLOR);
    
    Mat src = toCv(before);
    
    if (src.empty()) {
        ofLog() << "Image load failed!" << endl;
        return -1;
    }
    // RGB to HSV
    Mat src_hsv;
    cvtColor(src, src_hsv, COLOR_RGB2HSV);
    // make mask
    Mat mask, mask2;
    inRange(src_hsv, Scalar(0, 50, 0), Scalar(15, 255, 255), mask);
    toOf(mask, ofmask);
    
    // dilate mask
    dilate(mask, mask2, Mat());
    toOf(mask2, ofmask2);
    // inpainting
    Mat dst;
    inpaint(src, mask2, dst, 3, INPAINT_NS);
    
    toOf(dst, after);
    ofmask.update();
    ofmask2.update();
    after.update();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    before.draw(0, 0, 587, 346);
    ofmask.draw(0, 346, 587, 346);
    ofmask2.draw(587, 346, 587, 346);
    after.draw(587, 0, 587, 346);
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
