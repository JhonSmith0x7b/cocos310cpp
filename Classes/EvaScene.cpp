#include "EvaScene.h"

USING_NS_CC;

Scene* EvaScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = EvaScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool EvaScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sprite = Sprite::create("eva/eva.jpg",CCRect(400, 600, 395, 395));
	sprite -> setPosition(200, 200);
	this->addChild(sprite);
	auto sprite1 = Sprite::create("eva/evaasuka.jpg", CCRect(0, 0, 1020, 368));
	sprite1 -> setPosition(512, 400 + 185);
	this->addChild(sprite1);
	auto sprite2 = Sprite::create("eva/evamari.jpg", CCRect(900, 100, 620, 395));
	sprite2->setPosition(400 + 310, 200);
	this->addChild(sprite2);
	auto returnItem = MenuItemFont::create("return", CC_CALLBACK_1(EvaScene::returnCallback, this));
	returnItem->setPosition(500, 500);
	returnItem->setColor(Color3B(0, 0, 0));
	returnItem->setFontSize(50);
	auto menu = Menu::create(returnItem, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu, 0);
	return true;
}


void EvaScene::returnCallback(Ref* pSender)
{
	Director::getInstance()->popScene();
}
