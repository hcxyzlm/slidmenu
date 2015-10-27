#include "ExchageFareLayer.h"
#include "ZUiBase.h"
ExchageFareLayer::ExchageFareLayer()
:m_pBtn_Back(NULL)
,m_pFareNum(0)
,m_pLayoutCoin(NULL)
,m_pLayoutFare(NULL)
{

}

ExchageFareLayer::~ExchageFareLayer()
{
}

void ExchageFareLayer::onEnter()
{
	UILayout::onEnter();
	setTouchEnabled(true);
	setBackGroundColorOpacity(130);
	initLayer();
	//scheduleOnce(schedule_selector(ExchageFareLayer::updateCanTouch),2.0f);
}


void ExchageFareLayer::onExit()
{
	unschedule(schedule_selector(ExchageFareLayer::updateCanTouch));
	UILayout::onExit();
	setTouchEnabled(false);
}


void ExchageFareLayer::onCloseClick(CCObject *pObj , TouchEventType type)
{
	IF_TRUE_RETURN (TOUCH_EVENT_ENDED != type);

	removeFromParentAndCleanup(true);
}

void ExchageFareLayer::setFareNum( int JiFen )
{
	if (m_pFareNum)
	{
		/*m_pFareNum->setText(int2string(JiFen));*/
	}
}

bool ExchageFareLayer::init()
{
	if (!UILayout::init()) 
	{
		return false;
	}
	ignoreContentAdaptWithSize(false);
	m_pLayOut =dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("GameUI/shezhi.ExportJson"));
	this->addChild(m_pLayOut);
	//m_pLayOut->setTouchEnabled(false);
	/*UIButton* btnclose = NULL;
	CCS_BUTTON_BIND(btnclose,m_pLayOut,"onCloseClick",this,ExchageFareLayer::onCloseClick);
	CCS_BUTTON_BIND(m_pBtn_Back,m_pLayOut,"onOkClick",this,ExchageFareLayer::onCloseClick);
	CCS_LABEL_BIND(m_pFareNum, m_pLayOut, "m_pRewardCoin");
	CCS_LAYOUT_BIND(m_pLayoutFare, m_pLayOut, "panle_fare");
	CCS_LAYOUT_BIND(m_pLayoutCoin, m_pLayOut, "panle_coin");*/

	setSize(CCSizeMake(m_pLayOut->getContentSize().width/2,m_pLayOut->getContentSize().height));
	return true;
}

void ExchageFareLayer::updateCanTouch( float dt )
{
	if (m_pLayOut)
	{
		m_pLayOut->setTouchEnabled(true);

	}
}

void ExchageFareLayer::initLayer()
{
}
