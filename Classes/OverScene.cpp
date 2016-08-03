#include "OverScene.h"
#include "MainScene.h"
//#include "hgsdk.h"
#include "HgsdkBridge.h"
#include <string>
using namespace std;
USING_NS_CC;

Scene* OverScene::createScene(){
	auto scene = Scene::create();
	auto layer = OverScene::create();
	scene->addChild(layer);
	return scene;
}

bool OverScene::init(){
	if (!Layer::init()){
		return false;
	}
	auto size = Director::getInstance()->getWinSize();

	auto sprite = Sprite::create("over/onemb.png");
	sprite->setPosition(size.width / 2, size.height / 2);
	this->addChild(sprite);

	auto overLabel = LabelTTF::create("OverScene", "Arial", 40);
	overLabel->setColor(Color3B(54, 255, 159));
	overLabel->setPosition(size.width - 100, size.height - 50);
	this->addChild(overLabel);

	std::string imgs[] = {
		"over/over.png",
		"over/over1.png",
		"over/over2.png",
		"over/over3.png",
		"over/over4.png"
	};
	for (int i = 0; i < 5; i++){
		auto sprite = Sprite::create(imgs[i]);
		sprite->setPosition(100 + 100 * i, 100 + 30 * i);
		this->addChild(sprite);
	}

	auto returnGameItem = MenuItemFont::create("return Game", CC_CALLBACK_1(OverScene::returnGameCallBack, this));
	returnGameItem->setColor(Color3B(54, 255, 159));
	auto toMainItem = MenuItemFont::create("to Main", CC_CALLBACK_1(OverScene::toMainCallBack, this));
	toMainItem->setColor(Color3B(54, 255, 159));
	auto menu = Menu::create(returnGameItem, toMainItem, NULL);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(size.width / 2, size.height / 2);
	this->addChild(menu);

	return true;
}

void OverScene::returnGameCallBack(Ref* sender){
	Director::getInstance()->popScene();
}
static void toNewScene(){
	auto scene = MainScene::createScene();
	Director::getInstance()->replaceScene(scene);
}
void OverScene::toMainCallBack(Ref* sender){
	///////////////////////////////////////////////////////////
	//std::vector<std::string> groups = { "main" };//////hgsdk//////
	//hgsdk::preloadGroups(groups, toNewScene);//////hgsdk///////
	///////////////////////////////////////////////////////////
	std::string group = "rmain";
	HgsdkBridge::preloadOrNot(&group);
}