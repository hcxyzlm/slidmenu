#ifndef __SLIDENAVIGATIONCONTROLLER_H__
#define __SLIDENAVIGATIONCONTROLLER_H__

#include "cocos2d.h"
#include "cocos-ext.h"


USING_NS_CC;
USING_NS_CC_EXT;

#include <iostream>
using namespace std;
using namespace cocos2d::gui;

// 分成三个界面，左，中，右
typedef  enum{
    MenuLeft,
    MenuMain,
    MenuRight,
}Menu;


class SlideNavigationController : public CCScene
{
    
public:
    SlideNavigationController(void);
    virtual ~SlideNavigationController(void);
protected:
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
   // virtual bool init();
    virtual void onExit();
    virtual void onEnter();
	CCPoint GetPositionOfCurrentPage();
	void initLayer();
	void ListenMainLayout(CCObject *pObj, TouchEventType type);
public:
    static SlideNavigationController* sharedDirector(void);
    UILayout* leftLayout;
	UILayout* m_pMainLayout;
    UILayout* rightLayout;
private:
    // 屏幕的宽和高
     int mScreenWidth;
     int mMenuWidth;
    int mRightPinding; 
    
     bool once; 
     bool isOpen; // 是否打开侧边栏
	 CCPoint touchOrigin; // Where the touch action began.
	 bool bMoving; // Scene is move
	 float fMoveDelta; // Distance from origin of touch and current frame.
	 float threshold; //Threshold value to limit full movement of page on first and last page.
	 CCPoint touchStop; // Where the touch action stopped.
};

#endif // __HELLOWORLD_SCENE_H__
