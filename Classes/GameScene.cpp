#include "GameScene.h"
#include "OverScene.h"
//#include "hgsdk.h"
#include "HgsdkBridge.h"
#include <string>
using namespace std;
USING_NS_CC;

Scene* GameScene::createScene(){
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init(){
	if (!Layer::init()){
		return false;
	}
	auto size = Director::getInstance()->getWinSize();
	auto gameLabel = LabelTTF::create("GameScene", "Arial", 40);
	gameLabel->setColor(Color3B(54, 255, 159));
	gameLabel->setPosition(size.width - 100, size.height - 50);
	this->addChild(gameLabel);

	auto sprite = Sprite::create("game/twomb.png");
	sprite->setPosition(size.width / 2, size.height / 2);
	this->addChild(sprite);

	std::string imgs[] = {
		"game/game.png",
		"game/game1.png",
		"game/game2.png",
		"game/game13.png",
		"game/game14.png"
	};
	for (int i = 0; i < 5; i++){
		auto sprite = Sprite::create(imgs[i]);
		sprite->setPosition(100 + 100 * i, 100 + 30 * i);
		this->addChild(sprite);
	}
	auto toOverItem = MenuItemFont::create("to Over", CC_CALLBACK_1(GameScene::toOverCallBack, this));
	toOverItem->setColor(Color3B(54, 255, 159));
	auto menu = Menu::create(toOverItem, NULL);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(size.width / 2, size.height / 2);
	this->addChild(menu);

	return true;
}
static void toNewScene(){
	auto scene = OverScene::createScene();
	Director::getInstance()->pushScene(scene);
}
void GameScene::toOverCallBack(Ref* sender){
	///////////////////////////////////////////////////////////
	//std::vector<std::string> groups = { "over" };//////hgsdk//////
	//hgsdk::preloadGroups(groups, toNewScene);//////hgsdk///////
	///////////////////////////////////////////////////////////
	std::string group = "pover";
	HgsdkBridge::preloadOrNot(&group);
}