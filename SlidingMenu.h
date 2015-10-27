#ifndef __SLIDING_MENU_GRID_H
#define __SLIDING_MENU_GRID_H

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::gui;
USING_NS_CC;

typedef  enum{
	LeftLayout,
	MainLayout,
	RightLayout,
}LayoutState;

typedef enum 
{
	LeftDirction,
	RightDirction,
}GestureDirection;

class SlidMenuLayer: public UILayout
{
protected:
	void moveToCurrentPage(bool animated = true);
	virtual bool onTouchBegan( CCTouch *touch, CCEvent *unused_event );
	virtual void onTouchMoved(CCTouch *touch, CCEvent *unused_event);
	virtual void onTouchEnded(CCTouch *touch, CCEvent *unused_event);
	virtual void onTouchCancelled(CCTouch *touch, CCEvent *unused_event);
	CCPoint GetPositionOfCurrentPage();
	CCPoint GetPositionOfCurrentPageWithOffset(float offset);
	CCPoint touchOrigin; // Where the touch action began.
	CCPoint touchStop; // Where the touch action stopped.
	bool bMoving; // Is the grid currently moving?
	float fMoveDelta; // Distance from origin of touch and current frame.
	float fAnimSpeed; // 0.0-1.0 value determining how slow/fast to animate the paging.
	// ×óÓÒ±ß¾àµÄÆ«ÒÆÁ¿
	CC_SYNTHESIZE(float, leftSize, leftSize );
	CC_SYNTHESIZE(float, rightSize,  rightSize);
public:
	SlidMenuLayer();
	~SlidMenuLayer();
	virtual bool init();
	virtual void onExit();
	virtual void onEnter();
    void setThresholdPageLimit(float fValue);
	CCPoint getPositionOffset(float f);
	CREATE_FUNC(SlidMenuLayer);
	void openLeftLayer();
	void closeLeftLayer();
	void closeRightLayer();
	void openRightLayer();
	void ScrollX(float offset);
	void setLeftLayout(UILayout* left);
	void setRightLayout(UILayout* right);
private:
	LayoutState m_LayoutState;
protected:
	UILayout*  m_pLeftLayout;
	UILayout*  m_pRightLayout;

	void setUIScroll(float offset);
	GestureDirection getSliderDirection(float offset);
};
#endif
