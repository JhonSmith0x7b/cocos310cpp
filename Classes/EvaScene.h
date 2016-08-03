#ifndef __EVASCENE_SCENE_H__
#define __EVASCENE_SCENE_H__

#include "cocos2d.h"

class EvaScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void returnCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(EvaScene);
};

#endif // __EVASCENE_SCENE_H__