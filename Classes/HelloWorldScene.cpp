#include "HelloWorldScene.h"
#include "MainScene.h"
#include "HgsdkBridge.h"
#include <string>
using namespace std;
//#include "hgsdk.h"
//#include "platform\android\jni\JniHelper.h"
USING_NS_CC;

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
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto size = Director::getInstance()->getWinSize();
	// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("bg.jpg");

	// position the sprite on the center of the screen
	//sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(sprite);
	auto startLabel = LabelTTF::create("V1.1StartScene", "Arial", 40);
	startLabel->setPosition(size.width - 100, size.height - 50);
	startLabel->setColor(Color3B(54, 255, 159));
	this->addChild(startLabel);
	
	auto toMainItem = MenuItemFont::create("to Main", CC_CALLBACK_1(HelloWorld::toMainCallback, this));
	toMainItem->setPosition(size.width / 2, size.height / 2);
	toMainItem->setColor(Color3B(54, 255, 159));
	auto menu = Menu::create(toMainItem,  NULL);
	menu->setPosition(0, 0); 
	this->addChild(menu, 1);
	std::string imgs[]= {
		"start/start.png",
		"start/start1.png",
		"start/start2.png",
		"start/start3.png",
		"start/start4.png"
	};
	for (int i = 0; i < 5; i++){
		auto sprite = Sprite::create(imgs[i]);
		sprite->setPosition(50 + 50 * i, 150);
		this->addChild(sprite);
	}

	return true;
}
void HelloWorld::onEnter() {
	Layer::onEnter();
}

static void toNewScene(){
	auto scene = MainScene::createScene();
	// run
	Director::getInstance()->pushScene(scene);
}

void HelloWorld::toMainCallback(Ref* pSender)
{
	///////////////////////////////////////////////////////////
	//std::vector<std::string> groups = { "main" };//////hgsdk//////
	//hgsdk::preloadGroups(groups, toNewScene);//////hgsdk///////
	///////////////////////////////////////////////////////////
	std::string group = "rmain";
	HgsdkBridge::preloadOrNot(&group);
}
/*
void HelloWorld::jniCallback(Ref* pSender)
{
	CCLOG("%s", "JNI TOUCH****\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**");
	//JniMethodInfo info;
	//bool ret = JniHelper::getStaticMethodInfo(info, "com/jhonsmith/jartest/JNITest", "jniSucc", "()V");
	//if (ret){
	//	CCLOG("%s", "JNI SUCC****\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**");
	//	info.env->CallStaticVoidMethod(info.classID, info.methodID);
	//}
	//else {
	//	CCLOG("%s", "JNI FAIL****\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**");
	//}

	int _day = 0;
	JniMethodInfo x;
	if (JniHelper::getStaticMethodInfo(x, "com/mozgame/tapbuilding/NetWork", "getCurDayForYear", "()I"))
	{
		CCLOG("%s", "CP  CPC CP CP CP CPCPJNI SUCC****\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**\n**");
		x.env->CallStaticIntMethod(x.classID, x.methodID);
	}
}
*/