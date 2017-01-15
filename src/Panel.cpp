//
//  Panel.cpp
//  
//
//  Created by 祖父江亮 on 2015/10/07.
//
//

#include "Panel.h"

Panel::Panel(){
    
}

int Panel::shot(int color,int x,int y,int direction,int qx,int qy){
    if(color==1)
        ofSetColor(255, 0, 0);
    else if(color==2)
        ofSetColor(0, 0, 255);
    
    int j=0;
    if(direction == 1)
        for(j=0;j<12;++j)
        {
            ofRect(x, y-30*j, 30, 30);
            if(qx==x and y-30*j==qy)
            {
                death(color ,qx ,qy);
                ofLog(OF_LOG_NOTICE,"hit");
                return 1;
            }
        }
    if(direction == 2)
        for(j=0;j<=12;++j)
        {
            ofRect(x+30*j, y, 30, 30);
            if(qx==x+30*j and y==qy)
            {
                death(color ,qx ,qy);
                ofLog(OF_LOG_NOTICE,"hit");
                return 1;
            }
        }
    if(direction == 3)
        for(j=0;j<=12;++j)
        {
            ofRect(x, y+30*j, 30, 30);
            if(qx==x and y+30*j==qy)
            {
                death(color ,qx ,qy);
                ofLog(OF_LOG_NOTICE,"hit");
                return 1;
            }
        }
    if(direction == 4)
        for(j=0;j<=12;++j)
        {
            ofRect(x-30*j, y, 30, 30);
            if(qx==x-30*j and y==qy)
            {
                death(color ,qx ,qy);
                ofLog(OF_LOG_NOTICE,"hit");
                return 1;
            }
        }
    return 0;
}

void Panel::draw(int color,int num){
//        if(color==0)
//            ofSetColor(0, 0, 0);
//        if(color==1)
//            ofSetColor(255, 0, 0);
//        if(color==2)
//            ofSetColor(0,0,255);
//        ofRect(panel[num], 28, 28);
}
void Panel::death(int color,int qx,int qy){
    if(color==1)
    {
        ofSetColor(255, 0, 0);
        
    }
    if(color==2)
    {
        ofSetColor(0, 0, 255);

    }
    ofRect(qx-30, qy-30, 30, 30);
    ofRect(qx-30, qy   , 30, 30);
    ofRect(qx-30, qy+30, 30, 30);
    ofRect(qx,    qy-30, 30, 30);
    ofRect(qx,    qy   , 30, 30);
    ofRect(qx,    qy+30, 30, 30);
    ofRect(qx+30, qy-30, 30, 30);
    ofRect(qx+30, qy   , 30, 30);
    ofRect(qx+30, qy+30, 30, 30);
    
    ofRect(qx-60, qy-60, 30, 30);
    ofRect(qx   , qy-60, 30, 30);
    ofRect(qx+60, qy-60, 30, 30);
    ofRect(qx-60, qy   , 30, 30);
    ofRect(qx+60, qy, 30, 30);
    ofRect(qx-60, qy+60, 30, 30);
    ofRect(qx   , qy+60, 30, 30);
    ofRect(qx+60, qy+60, 30, 30);
    
}