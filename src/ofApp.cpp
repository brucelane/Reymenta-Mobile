#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// initialize the accelerometer
	ofxAccelerometer.setup();

	font.load("verdana.ttf",24);
	ofSetLineWidth(10);
	ofBackground(0,0,0);
	ofSetLogLevel(OF_LOG_VERBOSE);

	//required call
	gui.setup();


	ImGui::GetIO().MouseDrawCursor = true;
	clear_color = ImColor(114, 144, 154);
	show_test_window = true;
	show_another_window = false;
	floatValue = 0.0f;
}

//--------------------------------------------------------------
void ofApp::update(){
	accel = ofxAccelerometer.getForce();
	messages[0] = "g(x) = " + ofToString(accel.x,2);
	messages[1] = "g(y) = " + ofToString(accel.y,2);
	messages[2] = "g(z) = " + ofToString(accel.z,2);
	normAccel = accel.getNormalized();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255,255,0);
	font.drawString(messages[0],10,font.stringHeight(messages[0])+20);
	ofSetColor(255,0,255);
	font.drawString(messages[1],10,(font.stringHeight(messages[0])+20)*2);
	ofSetColor(0,255,255);
	font.drawString(messages[2],10,(font.stringHeight(messages[0])+20)*3);
	ofSetColor(128,255,255);
	font.drawString(ofToString(ImGui::GetIO().Framerate,2),10,(font.stringHeight(messages[0])+20)*4);

	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

	ofSetColor(255,255,0);
	ofDrawLine(0,0,normAccel.x*ofGetWidth()/2,0);
	ofSetColor(255,0,255);
	ofDrawLine(0,0,0,-normAccel.y*ofGetHeight()/2);
	// we don't draw z as the perspective might be confusing
	// but it's approximately one when the device is still and parallel
	// to the ground
	ofPopMatrix();
    // imgui
	//required to call this at beginning
	gui.begin();

	// 1. Show a simple window
	// Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets appears in a window automatically called "Debug"
	{
		ImGui::Text("Hello, world!");
		ImGui::SliderFloat("float", &floatValue, 0.0f, 1.0f);
		ImGui::ColorEdit3("clear color", (float*)&clear_color);
		if (ImGui::Button("Test Window")) show_test_window ^= 1;
		if (ImGui::Button("Another Window")) show_another_window ^= 1;
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}
	// 2. Show another simple window, this time using an explicit Begin/End pair
	if (show_another_window)
	{
		//note: ofVec2f and ImVec2f are interchangeable
		ImGui::SetNextWindowSize(ofVec2f(200,100), ImGuiSetCond_FirstUseEver);
		ImGui::Begin("Another Window", &show_another_window);
		ImGui::Text("Hello");
		ImGui::End();
	}

	// 3. Show the ImGui test window. Most of the sample code is in ImGui::ShowTestWindow()
	if (show_test_window)
	{
		ImGui::SetNextWindowPos(ofVec2f(650, 20), ImGuiSetCond_FirstUseEver);
		ImGui::ShowTestWindow(&show_test_window);
	}
	//required to call this at end
	gui.end();

}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

    cout << "sending hello" <<endl;
}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
