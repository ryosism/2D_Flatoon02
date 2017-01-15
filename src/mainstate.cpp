//
//  mainstate.cpp
//
//
//  Created by 祖父江亮 on 2016/01/23.
//
//

#include "mainstate.h"

//--------------------------------------------------------------
void mainstate::setup(){
    
}

//--------------------------------------------------------------
void mainstate::update(){
    
}

//--------------------------------------------------------------
void mainstate::draw(){
    ofBackground(0,0,0);
    ofSetColor(0, 255, 0);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200);
    
    //ボタン
    ofSetColor(255, 0, 0);
    ofRect(10, 10, 50, 50);
    ofSetColor(0, 255, 0);
    ofRect(70, 10, 50, 50);
    ofSetColor(0, 0, 255);
    ofRect(130, 10, 50, 50);
    
}

//--------------------------------------------------------------
string mainstate::getName(){
    return "mainstate";
}

//--------------------------------------------------------------

void mainstate::mousePressed(int x , int y, int button){
    //クリックした時に呼び出す
    if (10 < x && x < 60 && 10 < y && y < 60) {
        ofLog(OF_LOG_NOTICE, "touch");
        changeState("stateA");
    }
}

//--------------------------------------------------------------