#include "HgsdkBridge.h"
#include "MainScene.h"
#include "GameScene.h"
#include "ShopScene.h"
#include "OverScene.h"
#include <string>
using namespace std;
USING_NS_CC;

#if OPEN_HGSDK
#include "hgsdk.h"
#endif

static void replaceToMain(){
	auto scene = MainScene::createScene();
	// run
	Director::getInstance()->replaceScene(scene);
}

static void pushToShop(){
	auto shopScene = ShopScene::createScene();
	Director::getInstance()->pushScene(shopScene);
}

static void replaceToGame(){
	auto gameScene = GameScene::createScene();
	Director::getInstance()->replaceScene(gameScene);
}

static void pushToOver(){
	auto scene = OverScene::createScene();
	Director::getInstance()->pushScene(scene);
}

bool HgsdkBridge::preloadOrNot(std::string* group){
	if (*group == "rmain"){
#if OPEN_HGSDK
		std::vector<std::string> groups = { "main" };//////hgsdk//////
		hgsdk::preloadGroups(groups, replaceToMain);//////hgsdk///////
#else
		replaceToMain();
#endif
	}
	else if (*group == "pshop"){
#if OPEN_HGSDK
		std::vector<std::string> groups = { "shop" };//////hgsdk//////
		hgsdk::preloadGroups(groups, pushToShop);//////hgsdk///////
#else
		pushToShop();
#endif
	}
	else if (*group == "rgame"){
#if OPEN_HGSDK
		std::vector<std::string> groups = { "game" };//////hgsdk//////
		hgsdk::preloadGroups(groups, replaceToGame);//////hgsdk///////
#else
		replaceToGame();
#endif
	}
	else if (*group == "pover"){
#if OPEN_HGSDK
		std::vector<std::string> groups = { "over" };//////hgsdk//////
		hgsdk::preloadGroups(groups, pushToOver);//////hgsdk///////
#else
		pushToOver();
#endif
	}
	return true;
}