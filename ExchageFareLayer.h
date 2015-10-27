#pragma once

#include "iostream"
#include "cocos-ext.h"
#include "cocos2d.h"


using namespace std;
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::gui;

class ExchageFareLayer
	: public UILayout
{
public:
	CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ExchageFareLayer, create);
	
	ExchageFareLayer();
	virtual ~ExchageFareLayer();

	virtual bool init();
	void onEnter();
	void onExit();
	void onTouchLayoutListner(CCObject *pObj , TouchEventType type);
	void onCloseClick(CCObject *pObj, TouchEventType type);
	void setFareNum(int JiFen);
protected:
	void initLayer();
	void updateCanTouch( float dt );
private:
	UILabel* m_pFareNum;
	UIButton*  m_pBtn_Back;
	UILayout*  m_pLayOut;
	UILayout*  m_pLayoutFare;
	UILayout*  m_pLayoutCoin;
};