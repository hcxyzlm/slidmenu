#include "SlidingMenu.h"
#include "ExchageFareLayer.h"

SlidMenuLayer::SlidMenuLayer(){

	m_LayoutState = MainLayout;
	m_pRightLayout = NULL;
	m_pLeftLayout = NULL;
}

SlidMenuLayer::~SlidMenuLayer(){
	CCLog("Grid Destructor");
}

void SlidMenuLayer::onExit(){
	setTouchEnabled(false);
    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCLog("Grid onExit");
}

bool SlidMenuLayer::init(){
	if ( !UILayout::init() ){
		return false;
	}
	ignoreContentAdaptWithSize(false);
	UIImageView* sp = UIImageView::create();
	sp->loadTexture("HelloWorld.png");
	sp->setScale(2.0f);
	sp->setAnchorPoint(ccp(0.5,0.5));
	sp->setPosition(ccp(480,320));
	addChild(sp,1);
	/*ExchageFareLayer* playout = ExchageFareLayer::create();
	playout->setPosition(CCPointZero);
	addChild(playout,-100);*/
	setSize(CCSizeMake(960,640));
	return true;
}


bool SlidMenuLayer::onTouchBegan(CCTouch *touch, CCEvent *unused_event){
	UILayout::onTouchBegan(touch, unused_event);
    touchOrigin = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    
	CCLog("touchOrigin =%f, %f", touchOrigin.x, touchOrigin.y);
	return true;
}

void SlidMenuLayer::onTouchCancelled(CCTouch *touch, CCEvent *unused_event)
{

}

void SlidMenuLayer::onTouchMoved(CCTouch *touch, CCEvent *unused_event)
{

    touchStop = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
	fMoveDelta = (touchStop.x - touchOrigin.x);// Set our position.
	// Distance between the origin of the touch and current touch point.
	GestureDirection direction = getSliderDirection(fMoveDelta);
	// 右滑
	bMoving = true;
	if (direction == RightDirction)
	{
		if (fMoveDelta < leftSize && m_LayoutState != LeftLayout)
		{
			setUIScroll(fMoveDelta);
		}
	}// 左滑
	else if (direction == LeftDirction)
	{
		if (fMoveDelta > -rightSize && m_LayoutState != RightLayout)
		{
			setUIScroll(fMoveDelta);
		}
	}

	//if (fabs(fMoveDelta) < leftSize && fabs(fMoveDelta) < rightSize) {
	//	/*bMoving = true;
	//	if (m_LayoutState == LeftLayout && fMoveDelta >0)
	//	{
	//		return;
	//	}
	//	if (m_LayoutState == RightLayout && fMoveDelta <0)
	//	{
	//		return;
	//	}*/
	//	setUIScroll(fMoveDelta);
	//}
}

void SlidMenuLayer::onTouchEnded(CCTouch *touch, CCEvent *unused_event)
{
	if( bMoving )
	{
		CCLog("status = %d", m_LayoutState);
		// 中间布局
		GestureDirection direction = getSliderDirection(fMoveDelta);
		if (m_LayoutState == MainLayout)
		{
			if (direction == RightDirction && fabs(fMoveDelta) > leftSize/2)
			{
				setUIScroll(leftSize);
				m_LayoutState = LeftLayout;
			}
			else if (direction == LeftDirction && fabs(fMoveDelta) > rightSize/2)
			{
				setUIScroll(0-rightSize);
				m_LayoutState = LeftLayout;
			}
			else
			{
				moveToCurrentPage(false);
			}
		}
		else if (m_LayoutState == LeftLayout)
		{
			if (direction == LeftDirction && fabs(fMoveDelta) > leftSize/2)
			{
				m_LayoutState = MainLayout;
				moveToCurrentPage(false);
			}
			else
			{
				setPosition(GetPositionOfCurrentPageWithOffset(leftSize));
			}
		}
		else
		{
			if (direction ==RightDirction && fabs(fMoveDelta) > rightSize/2)
			{
				m_LayoutState = MainLayout;
				moveToCurrentPage(false);
			}
			else
			{
				setPosition(GetPositionOfCurrentPageWithOffset(0-rightSize));
			}
			/*if (fMoveDelta > 0 && fabs(fMoveDelta) > leftSize/2)
			{
			m_LayoutState = MainLayout;
			moveToCurrentPage(false);
			}
			else
			{
			setPosition(GetPositionOfCurrentPageWithOffset(0-leftSize));
			ScrollX(GetPositionOfCurrentPageWithOffset(0-leftSize).x);
			}*/
		}
	}
	else
	{
		CCLog("test click to cpcpot0");
		setPosition(GetPositionOfCurrentPage());
		m_LayoutState = MainLayout;
	//	CCEaseBounce* action =CCEaseBounce::create(CCMoveTo::create(fAnimSpeed*0.3f, GetPositionOfCurrentPage()));
	}
	bMoving = false;
}

void SlidMenuLayer::moveToCurrentPage(bool animated){
    if (animated){
		stopAllActions();
       // CCEaseBackOut* action =CCEaseBackOut::create());
		CCPoint pt=GetPositionOfCurrentPage();
        this->runAction(CCMoveTo::create(0.2, pt));
    }
    else{
        setPosition(GetPositionOfCurrentPage());
    }
}

CCPoint SlidMenuLayer::GetPositionOfCurrentPage(){
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	return CCPointMake(0*winSize.width,0);
}

CCPoint SlidMenuLayer::GetPositionOfCurrentPageWithOffset(float offset){
	CCPoint position= GetPositionOfCurrentPage();
	position.x+=offset;
	return position;
}



//Sets the width limit for First/Last page swipe limit.
void SlidMenuLayer::setThresholdPageLimit(float fValue){
    leftSize = fValue;
}

void SlidMenuLayer::onEnter()
{
	setTouchEnabled(true);
	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);
	/*setTouchPriority(-1);*/
}

CCPoint SlidMenuLayer::getPositionOffset( float f )
{
	CCPoint pt;
	switch (m_LayoutState)
	{
	case LeftLayout:
		pt = ccp(0+leftSize,0);
		break;
	case MainLayout:
		pt = CCPointZero;
		break;
	case RightLayout:
		pt = ccp(0-leftSize,0);
		break;
	default:
		break;
	}
	pt.x += f;
	return pt;
}

void SlidMenuLayer::openLeftLayer()
{
	m_LayoutState = LeftLayout;
	setPosition(GetPositionOfCurrentPageWithOffset(leftSize));
}

void SlidMenuLayer::closeLeftLayer()
{
	m_LayoutState = MainLayout;
	moveToCurrentPage(false);
}

void SlidMenuLayer::closeRightLayer()
{
	m_LayoutState = MainLayout;
	moveToCurrentPage(false);
}

void SlidMenuLayer::openRightLayer()
{
	m_LayoutState = RightLayout;
	setPosition(GetPositionOfCurrentPageWithOffset(0-leftSize));
	
}

void SlidMenuLayer::ScrollX( float offset ) // 向左偏移的x轴距离
{
	// 透明度从 0.6 ~ 1
	// scale 从 0.7 ~ 1
	float offsetScale = fabs(offset * 1.0f /leftSize); // 0 ~ 1

	float scale = 0.85 +offsetScale*0.15;
	float leftAlpht = 0.4f + 0.6f*offsetScale;
	CCLog("scale=%f,leftAlpht = %f", scale, leftAlpht);
	if (m_pLeftLayout)
	{
		m_pLeftLayout->setScale(scale);
		m_pLeftLayout->setOpacity(255*leftAlpht);
	}
	if (m_pRightLayout)
	{
		m_pRightLayout->setScale(scale);
		m_pRightLayout->setOpacity(255*leftAlpht);
	}
}

void SlidMenuLayer::setLeftLayout( UILayout* left )
{
	
	m_pLeftLayout = left;
	//leftSize = m_pLeftLayout->getSize().width;
}

void SlidMenuLayer::setRightLayout(UILayout* right)
{
	/*if (m_pRightLayout)
	{
	m_pRightLayout->removeFromParentAndCleanup(true);

	}*/
	m_pRightLayout = right;
	//this->addChild(m_pRightLayout, -1);
}

void SlidMenuLayer::setUIScroll( float offset )
{
	//ScrollX(getPositionOffset(offset).x);
	setPosition(getPositionOffset(offset));
}

GestureDirection SlidMenuLayer::getSliderDirection( float offset )
{
	if (offset > 0)
	{
		return RightDirction;
	}
	else if (offset  < 0)
	{
		return LeftDirction;
	}
}
