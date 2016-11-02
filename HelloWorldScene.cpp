#include "HelloWorldScene.h"
#include "NewScene.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
USING_NS_CC;
Sprite *spr1;
Scene *scene1;
using namespace std;
using namespace cocos2d;
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

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
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width,
		origin.y + closeItem->getContentSize().height));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto button1 = ui::Button::create("play.png");
	button1->setPosition(Vec2(origin.x + visibleSize.width / 2, 300));
	button1->setScale(0.07);
	button1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(button1, 0);

	auto button = ui::Button::create("bt1.png");
	button->setTitleText("Chuyen Scene");
	button->setPosition(Vec2(930, 610));
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:

			break;
		case ui::Widget::TouchEventType::ENDED:
			auto scene = NewScene::createScene();
			Director::getInstance()->replaceScene(scene);
			break;

		}
	});
	button->setScale(0.15);
	this->addChild(button);

	auto label = Label::create("Anh Nho Em", "fonft/Marker, Felt.ttf", 30);
	label->setPosition(Vec2(origin.x + label->getContentSize().width, origin.y + visibleSize.height - label->getContentSize().height));
	label->enableShadow();
	this->addChild(label);


	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this); 

	auto checkbox = ui::CheckBox::create("check.png", "check1.png");
	checkbox->setPosition(Vec2(870, 40));
	checkbox->setScale(0.2);
	checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			auto move11 = MoveTo::create(2, Vec2(500,250));
			spr1->runAction(move11);
			break;

		}
	});
	this->addChild(checkbox, 0);

	auto loadingBar = ui::LoadingBar::create("bar.png");
	loadingBar->setPosition(visibleSize / 2);
	loadingBar->setColor(Color3B::RED);
	loadingBar->setScale(0.8, 0.6);
	loadingBar->setPercent(0);
	loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
	this->addChild(loadingBar, 0);

	this->schedule([=](float delta){
		float percent = loadingBar->getPercent();
		percent++;
		loadingBar->setPercent(percent);
		if (percent >= 100.0f)
		{
			this->unschedule("updateLoadingBar");
		}
	}, 0.1f, "updateLoadingBar");

		



	spr1 = Sprite::create("cc5.jpg");
	spr1->setPosition(Vec2(100, 100));
	spr1->setScale(0.3);
	this->addChild(spr1);

    return true;

}

void HelloWorld::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	Vec2 touchLocation = touch->getLocation();

}

bool HelloWorld::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	Vec2 touchLocation = touch->getLocation();
	auto move11 = MoveTo::create(2, touchLocation);
	spr1->stopActionByTag(10);
	move11->setTag(10);
	spr1->runAction(move11);
	return true;
}
void HelloWorld::menuCloseCallback(Ref* pSender){
    scene1 = Scene::create();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto pageView = ui::PageView::create();
	pageView->setPosition(Vec2(0,320));
	pageView->setContentSize(Director::getInstance()->getVisibleSize());
	scene1->addChild(pageView);
	for (int i = 0; i < 4; i++)
	{
		auto page = ui::Layout::create();
		page->setContentSize(pageView->getContentSize());
		auto spr4 = Sprite::create("cc5.jpg");
		page->addChild(spr4);
		pageView->insertPage(page, i);
	}
	pageView->addEventListener([&](Ref *sender, ui::PageView::EventType type){
		if (type == ui::PageView::EventType::TURNING)
		{
			auto pageView = dynamic_cast<ui::PageView*>(sender);
			CCLOG("current page = %d", pageView->getCurPageIndex());
		}
	});


	auto button = ui::Button::create("bt1.png");
	button->setTitleText("Chuyen Scene");
	button->setPosition(Vec2(930, 610));
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:

			break;
		case ui::Widget::TouchEventType::ENDED:
			auto scene = NewScene::createScene();
			Director::getInstance()->replaceScene(scene);
			break;

		}
	});
	button->setScale(0.15);
	scene1->addChild(button);

	Director::getInstance()->replaceScene(TransitionFlipX::create(2, scene1));
}