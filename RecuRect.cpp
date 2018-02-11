#include "RecuRect.h"

RecuRect::RecuRect() {

}

RecuRect::RecuRect(int level, ofVec2f location, float size, bool origin) {

	if (level > 0) {

		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x - size / 4, location.y - size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x - size / 4, location.y + size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x + size / 4, location.y - size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x + size / 4, location.y + size / 4), size / 2));
	}

	this->level = level;
	this->location = location;
	this->size = size;
	this->type = ofRandom(100);
	this->origin = origin;
}

RecuRect::~RecuRect() {

}

void RecuRect::update() {

}

void RecuRect::draw(cv::Mat frame) {

	if (this->origin || (this->level != 0 && this->type < 80)) {

		for (int i = 0; i < this->rects.size(); i++) {

			this->rects[i].draw(frame);
		}
	}
	else {

		cv::Vec3b frame_color = frame.at<cv::Vec3b>((int)this->location.y, (int)this->location.x);
		ofColor color = ofColor(frame_color[2], frame_color[1], frame_color[0]);
		ofSetColor(color);
		ofDrawRectangle(this->location, this->size, this->size);
	}
}