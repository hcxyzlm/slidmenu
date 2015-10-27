#include "HelloWorldScene.h"
#include "ExchageFareLayer.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !UILayer::init() )
    {
        return false;
    }

	CCSize windowSize = CCDirector::sharedDirector()->getOpenGLView()->getDesignResolutionSize();

	sliderMenu = SlidMenuLayer::create();
	sliderMenu->setZOrder(100);
	//sliderMenu->setAnchorPoint(ccp(0.5, 0.5));
	sliderMenu->setThresholdPageLimit(960/4);
	sliderMenu->setrightSize(320);
	addWidget(sliderMenu);

	ExchageFareLayer* playout = ExchageFareLayer::create();
	playout->setAnchorPoint(ccp(0.5,0.5));
	playout->setPosition(ccp(480,320));
	playout->setZOrder(-100);
	addWidget(playout);
	sliderMenu->setLeftLayout(playout);
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	 CCLOG ("Item CLICKED: %d",  ((CCMenuItemSprite*)pSender)->getTag());
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
//	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//#else
//    CCDirector::sharedDirector()->end();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//#endif
}
