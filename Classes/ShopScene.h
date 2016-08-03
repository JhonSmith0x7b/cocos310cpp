#ifndef __SHOPSCENE_SCENE_H__
#define __SHOPSCENE_SCENE_H__

#include "cocos2d.h"

class ShopScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void returnMainCallBack(cocos2d::Ref* sender);
	// implement the "static create()" method manually
	CREATE_FUNC(ShopScene);
};

#endif // __SHOPSCENE_SCENE_H__