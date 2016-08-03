#ifndef __IMPLEMENTS_SCENE_H__
#define __IMPLEMENTS_SCENE_H__

#include "cocos2d.h"

class ImplementsScene : public cocos2d::Layer
{

public:

	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void onEnter() override;
	// a selector callback
	void returnCallback(cocos2d::Ref* pSender);
	void initCallback(cocos2d::Ref* pSender);
	void loginCallback(cocos2d::Ref* pSender);
	void shareCallback(cocos2d::Ref* pSender);
	void challengeCallback(cocos2d::Ref* pSender);
	void exitCallback(cocos2d::Ref* pSender);
	void startCallback(cocos2d::Ref* pSender);
	void pauseCallback(cocos2d::Ref* pSender);
	void resumeCallback(cocos2d::Ref* pSender);
	void passCallback(cocos2d::Ref* pSender);
	void payCallback(cocos2d::Ref* pSender);
	void overCallback(cocos2d::Ref* pSender);
	void showInAdCallback(cocos2d::Ref* pSender);
	void showRewardAdCallback(cocos2d::Ref* pSender);
	void friendsCallback(cocos2d::Ref* pSender);
	void inviteCallback(cocos2d::Ref* pSender);
	void shareToFacebookSilentCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(ImplementsScene);
};

#endif // __IMPLEMENTS_SCENE_H__