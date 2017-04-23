#include "ofApp.h"




void syphonView::setupUI(int idx, ofPoint windowSize){
    
    rect = ofRectangle(idx%4==0?0:windowSize.x/(4/(float)(idx%4)),
                       idx>=4 ?windowSize.y/4 : 0,
                       windowSize.x/4,
                       windowSize.y/4);
    
    if(fbo.isAllocated())fbo.clear();
    fbo.allocate(rect.width,rect.height,GL_RGBA);

    
    bar = ofRectangle(1,rect.height*0.8+1,rect.width*0.8-2,rect.height*0.2);
    barBg = ofRectangle(0,rect.height*0.8,rect.width*0.8,rect.height*0.2);
    
    ofPoint bs = ofPoint(rect.width*.1,rect.height*.1);
    over = ofRectangle(rect.width*0.8,rect.height*0.8,bs.x,bs.y);
    plus = ofRectangle(rect.width*0.8+bs.x,rect.height*0.8,bs.x,bs.y);
    minus = ofRectangle(rect.width*0.8,rect.height*0.8+bs.y,bs.x,bs.y);
    multi = ofRectangle(rect.width*0.8+bs.x,rect.height*0.8+bs.y,bs.x,bs.y);
    bg = ofRectangle(0,rect.height*0.8,rect.width,rect.height*0.2);
    
    
    
    //rect = ofRectangle(100*(idx%4),floor(idx/4)*100,100,100);
    
    alphaRect = ofRectangle(rect.x+1,rect.y+rect.height*0.8,rect.width*0.8-2,rect.height*0.2-2);
}



void syphonView::drawUI(){
    fbo.begin();
    ofClear(0);
    ofPushStyle();
    ofSetColor(0,0,0,155);
    ofDrawRectangle(bg);
    //ofDrawRectangle(0,0,100,20);
    ofNoFill();
    ofSetColor(255);
    ofDrawRectangle(barBg);
    ofDrawRectangle(over);
    ofDrawRectangle(plus);
    ofDrawRectangle(minus);
    ofDrawRectangle(multi);
    ofFill();
    
    ofDrawBitmapString(appName, 1, 10/*(int)(rect.height*0.1)*/);
    ofDrawBitmapString(serverName,1,20/*(int)(rect.height*0.2)*/);
    ofSetColor(200,0,0);
    ofDrawRectangle(bar.x,bar.y,bar.width*alpha,bar.height);
    switch(blendMode){
        case 1:ofDrawRectangle(over);break;
        case 2:ofDrawRectangle(plus);break;
        case 3:ofDrawRectangle(minus);break;
        case 4:ofDrawRectangle(multi);break;
        default:break;
    }
    ofPopStyle();
    fbo.end();
}

void syphonView::mousePressed(int x, int y, int button){
    if(alphaRect.inside(x,y)){
        bPressing = true;
        pressedCoord = ofPoint(x,y);
        curAlpha = alpha;
        bRedraw = true;
    }
    else if(over.inside(x-rect.x,y-rect.y)){
        blendMode = 1;
        bRedraw = true;
    }
    else if(plus.inside(x-rect.x,y-rect.y)){
        blendMode = 2;
        bRedraw = true;
    }
    else if(minus.inside(x-rect.x,y-rect.y)){
        blendMode = 3;
        bRedraw = true;
    }
    else if(multi.inside(x-rect.x,y-rect.y)){
        blendMode = 4;
        bRedraw = true;
    }else if(rect.inside(x,y)){
        select = true;
    }
}
void syphonView::mouseDragged(int x, int y, int button){
    if(bPressing){
        float a = (x - pressedCoord.x) / alphaRect.width;
        alpha = MIN(1.0,MAX(0.0,curAlpha + a));
        bRedraw = true;
    }
}
///////////////////

void ofApp::setupGui(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
}

void ofApp::drawMonitor(ofEventArgs & args){
    ofTexture tex = fbo.getTexture();
    tex.draw(0,0,ofGetWindowSize().x,ofGetWindowSize().y);
    
    
}

void ofApp::displayKeyPressed(ofKeyEventArgs & args){
    if(args.key=='f')ofToggleFullscreen();
    
}

//--------------------------------------------------------------
//--------------------------------------------------------------
//ofApp
//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::setup(){
    
    shader.load("multi");
    
    ofSetWindowTitle("SyphonManager");
    ofSetWindowShape(400, 400);
    
    windowSize = ofPoint(ofGetWindowSize().x,ofGetWindowSize().y);
    soloCh = -1;
    solo= false;
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    selectedCh = 0;

    ofEnableAlphaBlending();
    UI.allocate(windowSize.x,windowSize.y,GL_RGBA);
    //server.setName("SyphonManager");
    
    //receiver.setup(PORT);
    ofEnableAlphaBlending();
    
    //setup our directory
    dir.setup();
    
    //register for our directory's callbacks
    ofAddListener(dir.events.serverAnnounced, this, &ofApp::serverAnnounced);
    // not yet implemented
    //ofAddListener(dir.events.serverUpdated, this, &ofApp::serverUpdated);
    ofAddListener(dir.events.serverRetired, this, &ofApp::serverRetired);
    
    dirIdx = -1;
    
        
    //dir.refresh(false);
    dir.refresh(true);
    
    fbo.allocate(1280,720,GL_RGBA);
    
    for(int i = 0; i < 8; i++){
        pressedTimeCh[i] = -1;
    }
    
    
    for(int i = 0 ; i < clients.size(); i++){
        clients[i].setupUI(i,windowSize);
        clients[i].bRedraw = true;
    }
    
    barBg = ofRectangle(windowSize.x-40,windowSize.y/2,40,windowSize.y/2);
    bar = ofRectangle(windowSize.x-39,windowSize.y/2+1,38,windowSize.y/2-2);

    //UIRedraw = true;
    
    
}

//these are our directory's callbacks
void ofApp::serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg)
{
    //int i = 0;
    for( auto& dir : arg.servers ){
        
        ofLogNotice("ofxSyphonServerDirectory Server Announced")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
        /*
        bool doubled = false;
        
        //check double sever
        for(auto client : clients){
            if(dir.serverName==client.getServerName()&&dir.appName==client.getApplicationName()){
                doubled = true;
            }
        }*/
        
        syphonView tmpClient;
        tmpClient.setup();
        tmpClient.set(dir);
        
        clients.push_back(tmpClient);
        clients[clients.size()-1].setupUI(clients.size()-1,windowSize);
        
        clients[clients.size()-1].AppName = dir.appName;
        clients[clients.size()-1].ServerName = dir.serverName;
        clients[clients.size()-1].drawUI();
        
    }
    dirIdx = 0;
}

void ofApp::serverUpdated(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        
        ofLogNotice("ofxSyphonServerDirectory Server Updated")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}

void ofApp::serverRetired(ofxSyphonServerDirectoryEventArgs &arg)
{
    string appName;
    string serverName;
    
    
    for( auto& dir : arg.servers ){
        
        ofLogNotice("ofxSyphonServerDirectory Server Retired")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
        
        serverName = dir.serverName;
        appName = dir.appName;
        
        for(int i = 0; i < clients.size(); i++){
            if(clients[i].getApplicationName() == appName && clients[i].getServerName() == serverName){
                //clients[i].exit();
                //if(clients[i].mTex.get)
                clients.erase(clients.begin()+i);
                //break;
            }
        }
    }
    
    
    
    
    
    for(int i = 0 ; i < clients.size(); i++){
        clients[i].setupUI(i,windowSize);
        clients[i].bRedraw = true;
    }
    
    if(selectedCh>clients.size())selectedCh=clients.size()-1;
        dirIdx = 0;
}


//--------------------------------------------------------------
void ofApp::update(){
    /*
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        for(int i = 1; i <= 8; i++){
            if(m.getAddress() == "/1/multifader1/" + ofToString(i)){
                if(i <= clients.size()){
                    clients[i-1].alpha = m.getArgAsFloat(0);
                    clients[i-1].bRedraw = true;
                }
            }
        }
    }
*/
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    ofTexture tex;
    for(int i = 0; i < clients.size();i++){
        
        if(clients[i].bRedraw){
            clients[i].drawUI();
            clients[i].bRedraw = false;
        }
        
        if(dir.isValidIndex(dirIdx))clients[i].draw(clients[i].rect.x,clients[i].rect.y,clients[i].rect.width,clients[i].rect.height);
        //tex = clients[i].fbo.getTexture();
        //tex.draw(clients[i].rect.x,clients[i].rect.y);

        clients[i].fbo.getTexture().draw(clients[i].rect.x,clients[i].rect.y);
        
    }
    
    /////////
    //mixer//************************************************
    /////////
    
    fbo.begin();
    
    
    
    ofPushStyle();
    //ofClear(0);
    ofBackground(0, 0, 0);
    for(int i = 0; i < clients.size();i++){
        ofEnableBlendMode(ofBlendMode(clients[i].blendMode));
        
        if(!solo){
            ofSetColor(255,255,255,clients[i].alpha*255);
        }
        else{
            ofSetColor(255,255,255,soloCh == i ? 255:0);
        }
        
        clients[i].mTex.draw(0,0,fbo.getWidth(),fbo.getHeight());
        
    }
    //ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(0,0,0,255*darkness);
    ofDrawRectangle(0,0,fbo.getWidth(),fbo.getHeight());
    ofPopStyle();
    
    
    fbo.end();
    
    tex = fbo.getTexture();
    
    //shader.begin();
    tex.draw(0,windowSize.y/2,windowSize.y/2*1.777,windowSize.y/2);
    //shader.end();

    //SyphonFeedback
    server.publishTexture(&tex/*fbo.getTexture()*/);
    
    
    
    /////////////////////
    //UI*************************************
    /////////////////////
    
    if(UIRedraw){
        UI.begin();
        ofClear(0);
        ofNoFill();
    
        bar.height = ( barBg.height - 2 ) * ( 1 - darkness);
        bar.y = ( barBg.y + barBg.height - 1 ) - bar.height;
    
        ofDrawRectangle(barBg);
        ofDrawRectangle(four);
        ofDrawRectangle(svga);
        ofDrawRectangle(seventwo);
        ofDrawRectangle(teneighty);
        ofSetColor(255,0,0,255);
        if(clients.size()>0)ofDrawRectangle(clients[selectedCh].rect);
        ofFill();
        ofDrawRectangle(bar);
        switch(screenSize){
            case 0:ofDrawRectangle(four);break;
            case 1:ofDrawRectangle(svga);break;
            case 2:ofDrawRectangle(seventwo);break;
            case 3:ofDrawRectangle(teneighty);break;
            default:break;
        }
        ofSetColor(255);
        UI.end();
        UIRedraw = false;
    }
    tex = UI.getTexture();
    tex.draw(0,0);
    /*
    stringstream ss;
    ss << "framerate: " << ofToString(ofGetFrameRate(), 0);
    ofDrawBitmapString(ss.str(), 0, ofGetHeight()/2+10);
    */
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    float tmpTime = 0;
    
    switch(key){
        //solo
        case '1':
            solo = true;
            pressedTimeCh[0] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
        case '2':
            solo = true;
            pressedTimeCh[1] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
        case '3':
            solo = true;
            pressedTimeCh[2] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
        case '4':
            solo = true;
            pressedTimeCh[3] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
        case '5':
            solo = true;
            pressedTimeCh[4] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
        case '6':
            solo = true;
            pressedTimeCh[5] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
        case '7':
            solo = true;
            pressedTimeCh[6] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
        case '8':
            solo = true;
            pressedTimeCh[7] = ofGetElapsedTimef();
            
            for(int i = 0 ; i < 8; i++){
                if(tmpTime < pressedTimeCh[i]){
                    tmpTime = pressedTimeCh[i];
                    soloCh = i;
                }
            }
            break;
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        case OF_KEY_RIGHT:
            if( selectedCh < clients.size()-1 && selectedCh<8){
                
                syphonView tmpClient = clients[selectedCh];
                clients.erase(clients.begin()+selectedCh);
                selectedCh++;
                clients.insert(clients.begin()+selectedCh, tmpClient);
                clients[selectedCh].setupUI(selectedCh, windowSize);
                clients[selectedCh-1].setupUI(selectedCh-1, windowSize);
                clients[selectedCh].bRedraw = true;
                clients[selectedCh-1].bRedraw = true;
                UIRedraw = true;
            }
            break;
        case OF_KEY_LEFT:
            if(clients.size()>0 && selectedCh>0){
                syphonView tmpClient = clients[selectedCh];
                clients[selectedCh] = clients[selectedCh-1];
                clients[selectedCh-1] = tmpClient;
                
                clients[selectedCh].setupUI(selectedCh, windowSize);
                clients[selectedCh-1].setupUI(selectedCh-1, windowSize);
                clients[selectedCh].bRedraw = true;
                clients[selectedCh-1].bRedraw = true;
                selectedCh--;
                UIRedraw = true;
            }
            break;
            
        default:break;
    }//
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //ChSwitcher
    float tmpTime = 0;
    switch(key){
        case '1':pressedTimeCh[0] = -1;break;
            
        case '2':pressedTimeCh[1] = -1;break;

        case '3':pressedTimeCh[2] = -1;break;

        case '4':pressedTimeCh[3] = -1;break;

        case '5':pressedTimeCh[4] = -1;break;

        case '6':pressedTimeCh[5] = -1;break;

        case '7':pressedTimeCh[6] = -1;break;

        case '8':pressedTimeCh[7] = -1;break;
            
            default:break;
    }
    soloCh = -1;
    solo = false;
    for(int i = 0 ; i < 8; i++){
        if(tmpTime < pressedTimeCh[i]){
            tmpTime = pressedTimeCh[i];
            soloCh = i;
            solo = true;
        }
    }
    if(tmpTime == 0)solo = false;
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for(int i = 0; i < clients.size();i++){
        clients[i].mouseDragged(x,y,button);
    }
    if(bPressing){
        float posy = (y - pressedPos.y) / barBg.y;
        darkness = MIN(MAX(curDarkness + posy ,0.0),1.0);
        UIRedraw = true;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i = 0; i < clients.size();i++){
        clients[i].mousePressed(x,y,button);
        if(clients[i].select){
            selectedCh = i;
            UIRedraw = true;
            clients[i].select = false;
        }
    }
    if(four.inside(x,y)){
        screenSize = 0;
        fbo.clear();
        fbo.allocate(720,480,GL_RGBA);
        UIRedraw = true;
    }
    if(svga.inside(x,y)){
        screenSize = 1;
        fbo.clear();
        fbo.allocate(800,600,GL_RGBA);
        UIRedraw = true;
    }
    if(seventwo.inside(x,y)){
        screenSize = 2;
        fbo.clear();
        fbo.allocate(1280,720,GL_RGBA);
        UIRedraw = true;
    }
    if(teneighty.inside(x,y)){
        screenSize = 3;
        fbo.clear();
        fbo.allocate(1920,1080,GL_RGBA);
        UIRedraw = true;
    }
    
    if(barBg.inside(x,y)){
        bPressing = true;
        pressedPos = ofPoint(x,y);
        curDarkness = darkness;
        UIRedraw = true;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for(int i = 0; i < clients.size();i++){
        clients[i].bPressing = false;
    }
    bPressing = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    windowSize = ofGetWindowSize();// ofPoint(ofGetWindowSize().x,ofGetWindowSize().y);´
    for(int i = 0 ; i < clients.size(); i++){
        clients[i].setupUI(i,windowSize);
        clients[i].bRedraw = true;
        
    }
    UI.allocate(windowSize.x,windowSize.y,GL_RGBA);
    float ww = windowSize.y/2*1.777;
    barBg = ofRectangle(windowSize.x-40,windowSize.y/2,40,windowSize.y/2);
    bar = ofRectangle(windowSize.x-39,windowSize.y/2+1,38,windowSize.y/2-2);
    four.y = svga.y = seventwo.y = teneighty.y = windowSize.y/2+20;
    UIRedraw = true;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
