#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    ofGLFWWindowSettings settings;
    settings.width = 600;
    settings.height = 600;
    settings.setPosition(ofVec2f(1067,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    
    
    settings.shareContextWith = mainWindow;
    settings.width = 1066;
    settings.height = 600;
    settings.setPosition(ofVec2f(0,0));
    //settings.resizable = false;
    // uncomment next line to share main's OpenGL resources with gui
    //settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> DisplayWindow = ofCreateWindow(settings);
    
    DisplayWindow->setVerticalSync(true);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupGui();
    /*ofAddListener(DisplayWindow->events().update,
                  mainApp.get(),&ofApp::displayUpdate);*/
    ofAddListener(DisplayWindow->events().draw,
                  mainApp.get(),&ofApp::drawMonitor);
    ofAddListener(DisplayWindow->events().keyPressed,
                  mainApp.get(),&ofApp::displayKeyPressed);
    /*ofAddListener(DisplayWindow->events().windowResized,
                  mainApp.get(),&ofApp::displayWindowResized);*/
    
    
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();


}
