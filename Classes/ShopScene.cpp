#include "ShopScene.h"
USING_NS_CC;

Scene* ShopScene::createScene(){
	auto scene = Scene::create();
	auto layer = ShopScene::create();
	scene->addChild(layer);
	return scene;
}

bool ShopScene::init(){
	if (!Layer::init()){
		return false;
	}
	auto size = Director::getInstance()->getWinSize();
	auto shopLabel = LabelTTF::create("ShopScene", "Arial", 40);
	shopLabel->setColor(Color3B(54, 255, 159));
	shopLabel->setPosition(size.width - 100, size.height - 50);
	this->addChild(shopLabel);
	
	std::string imgs[] = {
	"shop/shop.jpg",
	"shop/shop1.jpg",
	"shop/shop2.jpg",
	"shop/shop3.jpg",
	"shop/shop4.jpg"
	};
	for (int i = 0; i < 5; i++){
	auto sprite = Sprite::create(imgs[i]);
	sprite->setPosition(100 + 100 * i, 100 + 30 * i);
	this->addChild(sprite);
	}
	
	auto returnMainItem = MenuItemFont::create("return Main", CC_CALLBACK_1(ShopScene::returnMainCallBack, this));
	returnMainItem->setColor(Color3B(54, 255, 159));
	auto menu = Menu::create(returnMainItem, NULL);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(size.width / 2, size.height / 2);
	this->addChild(menu);
	return true;
}

void ShopScene::returnMainCallBack(Ref* sender){
	Director::getInstance()->popScene();
}
