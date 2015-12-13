#pragma once

#include "ofMain.h"
#include "ofxAndroid.h"

#include "ofxAccelerometer.h"
#include "ofxImgui.h"

class ofApp : public ofxAndroidApp{
	
	public:
		
		void setup();
		void update();
		void draw();

		void windowResized(int w, int h);

		void touchDown(int x, int y, int id);
		void touchMoved(int x, int y, int id);
		void touchUp(int x, int y, int id);
		void touchDoubleTap(int x, int y, int id);
		void touchCancelled(int x, int y, int id);
		void swipe(ofxAndroidSwipeDir swipeDir, int id);

		void pause();
		void stop();
		void resume();
		void reloadTextures();

		bool backPressed();
		void okPressed();
		void cancelPressed();

		ofTrueTypeFont font;
		ofVec3f accel, normAccel;
		string messages[3];
        // imgui
		ofxImgui gui;
        ImVec4 clear_color;
        bool show_test_window;
        bool show_another_window;

        float floatValue;

};
