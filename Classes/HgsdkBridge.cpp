#include "HgsdkBridge.h"
#include "MainScene.h"
#include "GameScene.h"
#include "ShopScene.h"
#include "OverScene.h"
//#include "hgsdk.h"
#include <string>
using namespace std;
USING_NS_CC;
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
		//std::vector<std::string> groups = { "main" };//////hgsdk//////
		//hgsdk::preloadGroups(groups, replaceToMain);//////hgsdk///////
		//normal
		replaceToMain();
	}
	else if (*group == "pshop"){
		//std::vector<std::string> groups = { "shop" };//////hgsdk//////
		//hgsdk::preloadGroups(groups, pushToShop);//////hgsdk///////
		//normal
		pushToShop();
	}
	else if (*group == "rgame"){
		//std::vector<std::string> groups = { "game" };//////hgsdk//////
		//hgsdk::preloadGroups(groups, replaceToGame);//////hgsdk///////
		//normal
		replaceToGame();
	}
	else if (*group == "pover"){
		//std::vector<std::string> groups = { "over" };//////hgsdk//////
		//hgsdk::preloadGroups(groups, pushToOver);//////hgsdk///////
		//normal
		pushToOver();
	}
	return true;
}