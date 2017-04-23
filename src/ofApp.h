#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
//#include "utils.hpp"
//#include "ofxOsc.h"
//#define REZ 100
//#define BUFFER_SIZE 1024
//#define PORT 3333

class syphonView : public ofxSyphonClient{
public:
    
    float alpha = 0;
    
    void setupUI(int idx, ofPoint windowSize);
    
    void drawUI();
    
    void updateUI();
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    int blendMode = 1;
    
    string AppName;
    string ServerName;
    ofRectangle rect;
    
    ofRectangle bar;// = ofRectangle(1,81,78,18);
    ofRectangle barBg;// = ofRectangle(0,80,80,20);
    ofRectangle over;// = ofRectangle(80,80,10,10);
    ofRectangle plus;// = ofRectangle(90,80,10,10);
    ofRectangle minus;// = ofRectangle(80,90,10,10);
    ofRectangle multi;// = ofRectangle(90,90,10,10);
    ofRectangle bg;// = ofRectangle(0,80,100,20);
    ofFbo fbo;
    
    ofRectangle alphaRect;
    bool bRedraw = true;
    bool bPressing = false;
    bool select = false;
    ofPoint pressedCoord;
    float curAlpha;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void drawUI();
    ofFbo UI;
    bool UIRedraw = true;
    void setupGui();
    //void displayUpdate(ofEventArgs & args);
    void drawMonitor(ofEventArgs & args);
    void displayKeyPressed(ofKeyEventArgs & args);
    

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg);
    void serverUpdated(ofxSyphonServerDirectoryEventArgs &args);
    void serverRetired(ofxSyphonServerDirectoryEventArgs &arg);
    void setServer(syphonView view,int idx);
    int dirIdx;
    ofFbo fbo;
    int selectedCh;
    float darkness = 0.0;
    ofRectangle bar = ofRectangle(357,201,42,198);
    ofRectangle barBg = ofRectangle(356,200,44,200);
    bool bPressing = false;
    ofPoint pressedPos;
    float curDarkness;
    float alphas[8];
    int soloCh;
    bool solo;
    float pressedTimeCh[8];
    
    ofPoint windowSize;
    ofShader shader;
    ofxSyphonServerDirectory dir;
    vector<syphonView> clients;
    ofxSyphonServer server;
    
    bool full = false;
    int screenSize = 2;
    
    ofRectangle four = ofRectangle(0,210,10,10);
    ofRectangle svga = ofRectangle(10,210,10,10);
    ofRectangle seventwo = ofRectangle(20,210,10,10);
    ofRectangle teneighty = ofRectangle(30,210,10,10);
    
    //ofxOscReceiver receiver;
    int count = 0;
};
