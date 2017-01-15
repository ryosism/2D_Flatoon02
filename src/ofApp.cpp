#include "ofApp.h"
#include "panel.h"
#include "ofxTrueTypeFontUC.h"
#include "StateA.h"
#include "mainstate.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100, 100, 100);
    ofSetBackgroundAuto(false);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetFrameRate(10);
    ofSetLineWidth(3);
    
    px=105; py=75;
    qx=885; qy=615;

    panel = new Panel;
    direc1 = 2; direc2 = 4;
    startflag = false;
    opening = true;
    
    playtime=0;
    game=0;//稼働状態
    
    ikamodoki.loadFont("ikamodoki1_0.ttf", 30);
    ikamodoki_eng.loadFont("Paintball_Beta_4a.otf", 40);
    kanji.loadFont("ヒラギノ角ゴシック W3.ttc", 30);
    
    stateMachine.addState<stateA>();
    stateMachine.addState<mainstate>();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(startflag)
        playtime++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//---------------------------------------------
//ゲームレイアウト
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofSetColor(50, 50, 50);
    ofRect(0, 705, 1000, 100);
    ofSetColor(255, 255, 255);
    ofLine(0, 705, ofGetWidth(), 705);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
//---------------------------------------------
    
    if(playtime<501)//ゲーム実行中
    {
        if(playtime>400)
            ofSetColor(255, 150, 0);
        ikamodoki_eng.drawString(ofToString(50-playtime/10), 600, 753);
        ikamodoki.drawString("のこりタイム", 300, 755);
//---------------------------------------------
//スポーン地点
        ofSetColor(255, 120, 120);
        ofCircle(105, 75, 25);
        
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("A", 40, 50);
        
        ofSetColor(120, 120, 255);
        ofCircle(885, 615, 25);
        
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("B", 610, 620);
        
        
//----------------------------------------------
//プレーヤーアイコン
        ofSetColor(255, 150, 150);
        ofCircle(px, py, 13); //プレーヤーアイコン
        
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("A", px-5, py+5);
        
        ofSetColor(150, 150, 255);
        ofCircle(qx, qy, 13); //プレーヤーアイコン
        
        ofSetColor(0, 0, 0);
        ofDrawBitmapString("B", qx-5, qy+5);

//------------------------------------------------
    }
    
    
    else if (501<playtime && playtime<540)
    {
        game=1;//停止状態
        ikamodoki_eng.loadFont("Paintball_Beta_4a.otf", 40);
        if(playtime%4==0 || playtime%4==1)
        kanji.drawString("試合終了！！", 300, 755);
    }
    else if(playtime==541)
    {
        image.grabScreen(0, 0, 1000, 700);
        image.saveImage("result.png");
        
        ofSetBackgroundAuto(true);
        stateMachine.changeState("stateA");
        
    }
    ofLog(OF_LOG_NOTICE,ofToString(playtime));
    if(opening)
    {
        if(startflag==false)
        {
            ofSetColor(255, 255, 255);
            ikamodoki_eng.loadFont("Paintball_Beta_4a.otf", 60);
            ikamodoki_eng.drawString("2D_Flatoon", ofGetWidth()/2-200, 300);
            ikamodoki_eng.loadFont("Paintball_Beta_4a.otf", 40);
            ikamodoki.drawString("スペースをおしてスタート！", ofGetWidth()/2-200, 450);
        }
        if(startflag==true)
        {
            ofSetRectMode(OF_RECTMODE_CORNER);
            ofSetColor(0, 0, 0);
            ofRect(0, 0, 1000, 700);
            opening=false;
            ofSetRectMode(OF_RECTMODE_CENTER);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(game==0){
        
        switch (key) {
            case 'a':
            {
                px-=30;
                ofSetColor(255, 0, 0);
                ofRect(px+30, py, 30, 30);//足跡
                ofRect(px-30, py, 30, 30);
                direc1=4;
                break;
            }
                
            case 'w':
            {
                py-=30;
                ofSetColor(255, 0, 0);
                ofRect(px, py+30, 30, 30);//足跡
                ofRect(px, py-30, 30, 30);
                direc1=1;
                break;
            }
                
            case 's':
            {
                py+=30;
                ofSetColor(255, 0, 0);
                ofRect(px, py-30, 30, 30);//足跡
                ofRect(px, py+30, 30, 30);
                direc1=3;
                break;
            }
                
            case 'd':
            {
                px+=30;
                ofSetColor(255, 0, 0);
                ofRect(px-30, py, 30, 30);//足跡
                ofRect(px+30, py, 30, 30);
                direc1=2;
                break;
            }
                
            case 'q':
            {
                if(panel->shot(1, px, py, direc1,qx,qy)==1)
                {
                    qx=885; qy=615;
                }
                break;
            }
                
        //-------------------------------------------------------------
                
            case OF_KEY_LEFT:
            {
                qx-=30;
                ofSetColor(0, 0, 255);
                ofRect(qx+30, qy, 30, 30);//足跡
                ofRect(qx-30, qy, 30, 30);
                direc2=4;
                break;
            }
                
            case OF_KEY_UP:
            {
                qy-=30;
                ofSetColor(0, 0, 255);
                ofRect(qx, qy+30, 30, 30);//足跡
                ofRect(qx, qy-30, 30, 30);
                direc2=1;
                break;
            }
                
            case OF_KEY_DOWN:
            {
                qy+=30;
                ofSetColor(0, 0, 255);
                ofRect(qx, qy-30, 30, 30);//足跡
                ofRect(qx, qy+30, 30, 30);
                direc2=3;
                break;
            }
                
            case OF_KEY_RIGHT:
            {
                qx+=30;
                ofSetColor(0, 0, 255);
                ofRect(qx-30, qy, 30, 30);//足跡
                ofRect(qx+30, qy, 30, 30);
                direc2=2;
                break;
            }
                
            case OF_KEY_RIGHT_SHIFT:
            {
                if(panel->shot(2, qx, qy, direc2,px,py)==1)
                {
                    px=105; py=75;
                }
                break;
            }
            case '^':
            {
                playtime=500;
                break;
            }
            
            case ' ':
            {
                ofLog(OF_LOG_NOTICE, "startted");
                startflag=true;
            }
                
            default:
                break;
        }
        ofSetColor(255, 255, 255);
        ofLog(OF_LOG_NOTICE, "px = "+ofToString(px)+", py = "+ofToString(py)+"  direction1 = "+ofToString(direc1));
        ofLog(OF_LOG_NOTICE,"time "+ofToString(playtime));

        //    for(int i=0;i<10;++i)
        //    {
        //        panel->draw(gamecolor[i],i);
        //    }
        
    }
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

//--------------------------------------------------------------
