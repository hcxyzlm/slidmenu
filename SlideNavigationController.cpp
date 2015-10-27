//
//  SlideNavigationController.cpp
//  SlidMenu
//
//  Created by zhuo on 15/10/25.
//
//

#include "SlideNavigationController.h"

static SlideNavigationController *m_sharedInstance = NULL;

SlideNavigationController * SlideNavigationController::
sharedDirector(void)
{
    if (!m_sharedInstance)
    {
        m_sharedInstance = new SlideNavigationController;
        m_sharedInstance->init();
    }
    
    return m_sharedInstance;
}

SlideNavigationController::SlideNavigationController(void)
{
    leftLayout = NULL;
    rightLayout = NULL;
	isOpen = false;
}
void SlideNavigationController::onExit()
{
    /*CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);*/
    //setTouchEnabled(true);
    CCLog("SlideNavigationController onter");
}

void SlideNavigationController::onEnter()
{
    //setTouchEnabled(false);
    CCLOG("SlideNavigationController exit");
}

SlideNavigationController::~SlideNavigationController(void)
{
    
}

bool SlideNavigationController::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLog("%s", __FUNCTION__);
	//touchOrigin = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());

    return true;
}

void SlideNavigationController::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

	CCLog("%s", __FUNCTION__);
	//touchStop = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());// Distance between the origin of the touch and current touch point.
	//fMoveDelta = (touchStop.x - touchOrigin.x);
	/*if(iCurrentPage == 0){
	if (fMoveDelta < threshold) {
	setPosition(GetPositionOfCurrentPageWithOffset(fMoveDelta));
	bMoving = true;
	return;
	}
	}
	else if(iCurrentPage == iPageCount - 1){
	if (fMoveDelta > -threshold) {
	setPosition(GetPositionOfCurrentPageWithOffset(fMoveDelta));
	bMoving = true;
	return;
	}
	}
	else{
	setPosition(GetPositionOfCurrentPageWithOffset(fMoveDelta));
	bMoving = true;
	}*/
}

void SlideNavigationController::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("%s", __FUNCTION__);
}

void SlideNavigationController::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("%s", __FUNCTION__);
}

void SlideNavigationController::initLayer()
{
	CCLog("%s", __FUNCTION__);
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	mScreenWidth = size.width;
	mRightPinding = 80;
	mMenuWidth = size.width - mRightPinding;

	if (leftLayout)
	{
		addChild(leftLayout,0);
	}
	if (rightLayout)
	{
		addChild(rightLayout);
	}

	threshold = size.width / 4;
	m_pMainLayout->addTouchEventListener(m_pMainLayout, toucheventselector(SlideNavigationController::ListenMainLayout));
}

CCPoint SlideNavigationController::GetPositionOfCurrentPage()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint position=getPosition();
	return position;
}

void SlideNavigationController::ListenMainLayout( CCObject *pObj, TouchEventType type )
{
	if (pObj  == NULL)
	{
		return;
	}

	CCLog("touch selector = %d", type);
	switch (type)
	{
	case TOUCH_EVENT_BEGAN:
		//m_beganPt = convertToWorldSpace(pObj->getTouchStartPos());
		break;
	case TOUCH_EVENT_MOVED:

		break;
	case TOUCH_EVENT_ENDED:

		break;
	case TOUCH_EVENT_CANCELED:

		break;
	default:
		break;
	}
}


    
