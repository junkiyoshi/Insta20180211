#pragma once
#include "ofMain.h"
#include "opencv2/opencv.hpp"

class RecuRect
{
public:
	RecuRect();
	RecuRect(int level, ofVec2f location, float size, bool origin = false);
	~RecuRect();

	void update();
	void draw(cv::Mat frame);
private:
	int level;
	ofVec2f location;
	float size;
	int type;
	bool origin;

	std::vector<RecuRect> rects;
};