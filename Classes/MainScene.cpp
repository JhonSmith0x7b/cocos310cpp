#include "MainScene.h"
USING_NS_CC;
#include "GameScene.h"
#include "ShopScene.h"
#include "ImplementsScene.h"
#include <string>
using namespace std;
#include "HgsdkBridge.h"
//#include "hgsdk.h"
Scene* MainScene::createScene(){
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init(){
	if (!Layer::init()){
		return false;
	}
	auto size = Director::getInstance()->getWinSize();
	auto mainLabel = LabelTTF::create("MainScene", "Arial", 40);
	mainLabel->setColor(Color3B(111, 59, 156));
	mainLabel->setPosition(size.width - 100, size.height - 50);
	this->addChild(mainLabel);
	std::string imgs[] = {
		"main/main.png",
		"main/main1.png",
		"main/main2.png",
		"main/main3.png",
		"main/main4.png"
	};
	for (int i = 0; i < 5; i++){
		auto sprite = Sprite::create(imgs[i]);
		sprite->setPosition(100 + 100 * i, 100 + 30 * i);
		this->addChild(sprite);
	}
	auto toGameItem = MenuItemFont::create("to Game", CC_CALLBACK_1(MainScene::toGameCallBack, this));
	toGameItem->setColor(Color3B(111, 59, 156));
	auto toShopItem = MenuItemFont::create("to Shop", CC_CALLBACK_1(MainScene::toShopCallBack, this));
	toShopItem->setColor(Color3B(111, 59, 156));
	auto toImplementsItem = MenuItemFont::create("to Implements", CC_CALLBACK_1(MainScene::toImplementsCallBack, this));
	toImplementsItem->setColor(Color3B(111, 59, 156));
	auto menu = Menu::create(toGameItem, NULL);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(size.width / 2, size.height / 2);
	this->addChild(menu);

	return true;
}
static void toNewScene(){
	auto gameScene = GameScene::createScene();
	Director::getInstance()->replaceScene(gameScene);
}
void MainScene::toGameCallBack(Ref* sender){
	///////////////////////////////////////////////////////////
	//std::vector<std::string> groups = { "game" };//////hgsdk//////
	//hgsdk::preloadGroups(groups, toNewScene);//////hgsdk///////
	///////////////////////////////////////////////////////////
	std::string group = "rgame";
	HgsdkBridge::preloadOrNot(&group);
}
static void toNewScene1(){
	auto shopScene = ShopScene::createScene();
	Director::getInstance()->pushScene(shopScene);
}
void MainScene::toShopCallBack(Ref* sender){
	///////////////////////////////////////////////////////////
	//std::vector<std::string> groups = { "shop" };//////hgsdk//////
	//hgsdk::preloadGroups(groups, toNewScene1);//////hgsdk///////
	///////////////////////////////////////////////////////////
	std::string group = "pshop";
	HgsdkBridge::preloadOrNot(&group);
}

void MainScene::toImplementsCallBack(Ref* sender){
	auto implementsScene = ImplementsScene::createScene();
	Director::getInstance()->pushScene(implementsScene);
}