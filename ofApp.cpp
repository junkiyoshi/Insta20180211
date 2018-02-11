#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofSetLineWidth(0.3);

	this->cap.open(1);
	this->cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
	this->cap.set(cv::CAP_PROP_FRAME_HEIGHT, 640);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->cap >> this->frame;
	if (this->frame.empty()) {

		return;
	}
	cv::flip(this->frame, this->frame, 1);

	if (ofGetFrameNum() % 90 == 0) {

		this->r_rect = RecuRect(8, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), 640, true);
	}

	this->r_rect.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	r_rect.draw(this->frame);
}

//========================================================================
int main() {

	ofSetupOpenGL(640, 640, OF_WINDOW);
	ofRunApp(new ofApp());
}