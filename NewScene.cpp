#include "NewScene.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

Scene* NewScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = NewScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool NewScene::init()
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
		CC_CALLBACK_1(NewScene::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width,
		origin.y + closeItem->getContentSize().height));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("Anh Nho Em", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + label->getContentSize().width,
		origin.y + visibleSize.height - label->getContentSize().height));
	label->setColor(Color3B::BLUE);
	label->setOpacity(180);
	// add the label as a child to this layer
	this->addChild(label, 1);

	auto sprite = Sprite::create("cv1.jpg");
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	sprite->setScale(0.4f,0.32f);
	sprite->setColor(Color3B::BLUE);
	this->addChild(sprite, 0);

	auto sp1 = Sprite::create("cv2.jpg");
	sp1->setPosition(Vec2(origin.x , visibleSize.height + origin.y));
	sp1->setScale(0.3f);
	sp1->setColor(Color3B::YELLOW);
	sp1->setOpacity(200);
	sp1->setAnchorPoint(Point(0,1.0f));
	this->addChild(sp1, 0);

	auto sp2 = Sprite::create("cv3.jpg");
	sp2->setPosition(Vec2(visibleSize.width - visibleSize.width/1.4 + origin.x, visibleSize.height - visibleSize.height / 3 + origin.y));
	sp2->setZOrder(2);
	sp2->setAnchorPoint(Point(0.2f, 0));
	sp2->setRotation(20);
	sp2->setSkewX(10.0f);
	sp2->setSkewY(-10.0f);
	sp2->setScale(0.125f);
	sp2->setOpacity(200);
	this->addChild(sp2, 0);

	auto sp3 = Sprite::create("cv4.png");
	sp3->setPosition(Vec2(visibleSize.width - visibleSize.width / 3 + origin.x, visibleSize.height - visibleSize.height / 1.5 + origin.y));
	sp3->setRotation(30);
	sp3->setZOrder(3);
	sp3->setSkewX(-10.0f);
	sp3->setSkewY(10.0f);
	sp3->setScale(0.15f, 0.15f);
	sp3->setOpacity(200);
	this->addChild(sp3, 0);

	auto sp4 = Sprite::create("cv6.jpg");
	sp4->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	sp4->setScale(0.55);
	sp4 -> setZOrder(5);
	sp4->setRotation(-45);
	sp4->setOpacity(70);
	this->addChild(sp4, 0);

	auto sp5 = Sprite::create("cc1.jpg");
	sp5->setPosition(Vec2(visibleSize.width + origin.x, visibleSize.height + origin.y));
	sp5->setAnchorPoint(Point(1.0f, 1.0f));
	sp5->setScale(0.2);
	sp5->setZOrder(1);
	sp5->setOpacity(150);
	this->addChild(sp5, 0);

	auto label1 = Label::createWithTTF("Code De Quen Em", "fonts/Marker Felt.ttf", 35);

	label1->setPosition(Vec2(origin.x + visibleSize.width - label1->getContentSize().width,
	origin.y +  label->getContentSize().height));
	label1->setColor(Color3B::MAGENTA);
	label1->setOpacity(120);
	label1->setAnchorPoint(Point(0.1f, 0.85f));
	label1->setZOrder(0);
	this->addChild(label1);

	auto label2 = Label::createWithTTF("Vay Nen Anh", "fonts/Marker Felt.ttf", 35);

	label2->setPosition(Vec2(origin.x + visibleSize.width / 2,
	origin.y + visibleSize.height / 2));
	label2->setColor(Color3B::RED);
	label2->setOpacity(120);
	label2->setZOrder(0);
	this->addChild(label2);

	auto sp6 = Sprite::create("cc12.jpg",Rect(0,0,441,240));
	sp6->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height/1.32  + origin.y));
	sp6->setScale(0.54f,0.68f);
	sp6->setZOrder(100);
	this->addChild(sp6);


	auto sp7 = Sprite::create("cc12.jpg", Rect(441, 240, 441, 240));
	sp7->setPosition(Vec2(visibleSize.width / 1.34 + origin.x, visibleSize.height / 4 + origin.y));
	sp7->setScale(0.54f, 0.68f);
	sp7->setZOrder(100);
	this->addChild(sp7);

	auto sp8 = Sprite::create("cc12.jpg", Rect(441, 0, 441, 240));
	sp8->setPosition(Vec2(visibleSize.width / 1.34 + origin.x, visibleSize.height / 1.32 + origin.y));
	sp8->setScale(0.54f, 0.68f);
	sp8->setZOrder(100);
	this->addChild(sp8);

	auto sp9 = Sprite::create("cc12.jpg", Rect(0, 240, 441, 240));
	sp9->setPosition(Vec2(visibleSize.width / 4 + origin.x, visibleSize.height / 4 + origin.y));
	sp9->setScale(0.54f, 0.68f);
	sp9->setZOrder(100);
	this->addChild(sp9);

	auto mv1 = MoveBy::create(6.0f, Vec2(origin.x - sp6->getContentSize().width, origin.y + sp6->getContentSize().height));
	auto rot1 = RotateTo::create(6.0f, 90.0);
	auto fade1 = FadeTo::create(6.0f, 100);
	auto spa1 = Spawn::createWithTwoActions(mv1, rot1);
	auto dl1 = DelayTime::create(3.0);
	auto sq1 = Sequence::create(dl1, fade1, spa1, nullptr);
	sp6->runAction(RepeatForever::create(sq1));

	auto mv2 = MoveBy::create(6.0f, Vec2(origin.x - sp6->getContentSize().width, origin.y - sp6->getContentSize().height));
	auto rot2 = RotateTo::create(6.0f, -90.0);
	auto fade2 = FadeTo::create(6.0f, 100);
	auto spa2 = Spawn::createWithTwoActions(mv2, rot2);
	auto dl2 = DelayTime::create(3.0);
	auto sq2 = Sequence::create(dl2, fade2, spa2, nullptr);
	sp9->runAction(sq2);
	auto mv3 = MoveBy::create(10.0f, Vec2(origin.x + sp6->getContentSize().width +
	visibleSize.width, origin.y - sp6->getContentSize().height));
	auto rot3 = RotateTo::create(6.0f, -90.0);
	auto fade3 = FadeTo::create(6.0f, 100);
	auto spa3 = Spawn::createWithTwoActions(mv3, rot3);
	auto dl3 = DelayTime::create(3.0);
	auto sq3 = Sequence::create(dl3, fade3, spa3,nullptr);
	sp7->runAction(sq3);
	auto mv4 = MoveBy::create(10.0f, Vec2(origin.x + sp6->getContentSize().width +
	visibleSize.width, origin.y + sp6->getContentSize().height));
	auto rot4 = RotateTo::create(6.0f, 90.0);
	auto fade4 = FadeTo::create(6.0f, 100);
	auto spa4 = Spawn::createWithTwoActions(mv4, rot4);
	auto dl4 = DelayTime::create(3.0);
	auto sq4 = Sequence::create(dl4, fade4, spa4, nullptr);
	sp8->runAction(sq4);

	auto spr1 = Sprite::create("cc4.jpg",Rect(0,0,330,271));
	spr1->setPosition(Vec2(visibleSize.width / 3.98 + origin.x, visibleSize.height / 1.33 + origin.y));
	spr1->setScale(0.73f,0.59f);
	spr1->setZOrder(50);
	this->addChild(spr1);

	auto spr2 = Sprite::create("cc4.jpg", Rect(330, 0, 330, 271));
	spr2->setPosition(Vec2(visibleSize.width / 1.33 + origin.x, visibleSize.height / 1.33 + origin.y));
	spr2->setScale(0.73f, 0.59f);
	spr2->setZOrder(50);
	this->addChild(spr2);

	auto spr3 = Sprite::create("cc4.jpg", Rect(0, 271, 330, 271));
	spr3->setPosition(Vec2(visibleSize.width / 3.98 + origin.x, visibleSize.height / 3.97 + origin.y));
	spr3->setScale(0.73f, 0.59f);
	spr3->setZOrder(50);
	this->addChild(spr3);

	auto spr4 = Sprite::create("cc4.jpg", Rect(330, 271, 330, 271));
	spr4->setPosition(Vec2(visibleSize.width / 1.33 + origin.x, visibleSize.height / 3.97 + origin.y));
	spr4->setScale(0.73f, 0.59f);
	spr4->setZOrder(50);
	this->addChild(spr4);

	auto mv5 = MoveBy::create(10.0f, Vec2(origin.x - spr1->getContentSize().width, origin.y + spr1->getContentSize().height + visibleSize.height));
	auto rot5 = RotateTo::create(6.0f, 90.0);
	auto fade5 = FadeTo::create(6.0f, 100);
	auto spa5 = Spawn::createWithTwoActions(mv5, rot5);
	auto dl5 = DelayTime::create(12.0);
	auto tin5 = TintTo::create(3.0f, Color3B::RED);
	auto sca5 = ScaleTo::create(3.0, 0.5, 0.5);
	auto spa6 = Spawn::createWithTwoActions(sca5 , fade5);
	auto sq5 = Sequence::create(dl5, tin5, spa6, spa5, nullptr);
	spr1->runAction(sq5);

	auto mv6 = MoveBy::create(10.0f, Vec2(origin.x + spr2->getContentSize().width +
	visibleSize.width, origin.y + spr2->getContentSize().height));
	auto rot6 = RotateTo::create(6.0f, 90.0);
	auto fade6 = FadeTo::create(6.0f, 100);
	auto spa7 = Spawn::createWithTwoActions(mv6, rot6);
	auto dl6 = DelayTime::create(12.0);
	auto tin6 = TintTo::create(3.0f, Color3B::RED);
	auto sca6 = ScaleTo::create(3.0, 0.5, 0.5);
	auto spa8 = Spawn::createWithTwoActions(sca6, fade6);
	auto sq6 = Sequence::create(dl6, tin6, spa8, spa7, nullptr);
	spr2->runAction(sq6);

	auto mv7 = MoveBy::create(10.0f, Vec2(origin.x - spr3->getContentSize().width, origin.y - spr3->getContentSize().height));
	auto rot7 = RotateTo::create(6.0f, -90.0);
	auto fade7 = FadeTo::create(6.0f, 100);
	auto spa9 = Spawn::createWithTwoActions(mv7, rot7);
	auto dl7 = DelayTime::create(12.0);
	auto tin7 = TintTo::create(3.0f, Color3B::RED);
	auto sca7 = ScaleTo::create(3.0, 0.5, 0.5);
	auto spa10 = Spawn::createWithTwoActions(sca7, fade7);
	auto sq7 = Sequence::create(dl7,tin7, spa10, spa9, nullptr);
	spr3->runAction(sq7);

	auto mv8 = MoveBy::create(10.0f, Vec2(origin.x + spr4->getContentSize().width +
	visibleSize.width, origin.y + spr4->getContentSize().height));
	auto rot8 = RotateTo::create(6.0f, -90.0);
	auto fade8 = FadeTo::create(6.0f, 100);
	auto spa11 = Spawn::createWithTwoActions(mv8, rot8);
	auto dl8 = DelayTime::create(12.0);
	auto tin8 = TintTo::create(3.0f, Color3B::RED);
	auto sca8 = ScaleTo::create(3.0, 0.5, 0.5);
	auto spa12 = Spawn::createWithTwoActions(sca8, fade8);
	auto sq8 = Sequence::create(dl8,tin8, spa12, spa11, nullptr);
	spr4->runAction(sq8);

	const int numberSprite = 10;
	// khoi tao so luong toi da de tao animation
	auto spr5 = Sprite::create("cc5.jpg", Rect(120, 120, 500, 500));
	spr5->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
	spr5->setZOrder(20);
	spr5->setScale(0.6);
	spr5->setOpacity(150);
	this->addChild(spr5);
	Vector<SpriteFrame*> aniFrames;    //khoi tao vector co kieu SpriteFrame
	aniFrames.reserve(numberSprite);  //khoi tao kich thuong cua mang
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(120, 180, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(120, 250, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(120, 320, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(120,400 ,500 , 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(120, 450, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(180, 120, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(250, 120, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(320, 120, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(400, 120, 500, 500)));
	aniFrames.pushBack(SpriteFrame::create("cc5.jpg", Rect(450, 120, 500, 500)));
	Animation* animation = Animation::createWithSpriteFrames(aniFrames, 1.5f);  // khoi tao 1 khung hinh tu vector
	Animate* animate = Animate::create(animation);    //tao animate
	spr5->runAction(RepeatForever::create(animate));   //chay voi vong lap vo han

	auto spr6 = Sprite::create("cc5.jpg");
	spr6->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	spr6->setZOrder(10);
	spr6->setScale(0.2);
	this->addChild(spr6);
	auto move1 = MoveBy::create(5.0f, Vec2(200, 200));
	auto move_back = move1->reverse();
	auto move_ease = EaseBounceIn::create(move1->clone());
	auto seq1 = Sequence::create(move_ease, dl1, move_back,  nullptr);
	auto move2 = MoveTo::create(5.0f, Vec2(visibleSize.width, 0));
	auto fad = FadeTo::create(5.0f, 100);
	auto seq = Sequence::create(move1, fad, move2, nullptr);
	spr6->runAction(RepeatForever::create(seq1)); 


	auto button = ui::Button::create("bt1.png");
	button->setTitleText("Chuyen Scene");
	button->setPosition(Vec2(930, 610));
	button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:

			break;
		case ui::Widget::TouchEventType::ENDED:
			auto scene = HelloWorld::createScene();
			Director::getInstance()->replaceScene(scene);
			break;

		}
	});
	button->setScale(0.15);
	this->addChild(button);
		
    return true;

}

void NewScene::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_TARGET_PLATFORM_IOS)
	exit(0)
#endif
}