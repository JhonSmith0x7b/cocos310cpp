#ifndef __OVERSCENE_SCENE_H__
#define __OVERSCENE_SCENE_H__

#include "cocos2d.h"

class OverScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void returnGameCallBack(cocos2d::Ref* sender);
	void toMainCallBack(cocos2d::Ref* sender);
	// implement the "static create()" method manually
	CREATE_FUNC(OverScene);
};

#endif // __OVERSCENE_SCENE_H__