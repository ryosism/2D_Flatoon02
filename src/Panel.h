//
//  Panel.h
//  
//
//  Created by 祖父江亮 on 2015/10/07.
//
//

#ifndef ____Panel__
#define ____Panel__

#include <stdio.h>
#include <ofMain.h>

class Panel{
public:
    Panel();//コンストラクタ
    int shot(int,int,int,int,int,int);
    void draw(int,int);
    void death(int,int,int);
    
private:
    int px,py,panelnum=0;
    ofVec2f panel[];
};

#endif /* defined(____Panel__) */
