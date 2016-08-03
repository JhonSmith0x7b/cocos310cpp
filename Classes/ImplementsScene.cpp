#include "ImplementsScene.h"
//#include "hgsdk.h"

USING_NS_CC;
static ImplementsScene *self = nullptr;
static cocos2d::MenuItemFont* _init;
static cocos2d::MenuItemFont* _login;
static cocos2d::MenuItemFont* _share;
static cocos2d::MenuItemFont* _exit1;
static cocos2d::MenuItemFont* _start;
static cocos2d::MenuItemFont* _pause;
static cocos2d::MenuItemFont* _resume;
static cocos2d::MenuItemFont* _pass;
static cocos2d::MenuItemFont* _pay;
static cocos2d::MenuItemFont* _over;
static cocos2d::MenuItemFont* _challenge;
static cocos2d::MenuItemFont* _return;
static cocos2d::MenuItemFont* _showInAd;
static cocos2d::MenuItemFont* _showRewardAd;
static cocos2d::MenuItemFont* _friends;
static cocos2d::MenuItemFont* _invite;
static cocos2d::MenuItemFont* _shareToFacebookSilent;
static cocos2d::LabelTTF* _resultTitle;
static cocos2d::LabelTTF* _resultResult;
static cocos2d::LabelTTF* _resultDetail;
static cocos2d::LabelTTF* _resultDetail1;
Scene* ImplementsScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ImplementsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

/*
static void loginOnSuccess(const hgsdk::UserInfo &info){
	_login->setString("logSucc");
	CCLOG("hgsdk login success time : %d ", time);
}

static void loginOnFail(int code, const char *msg){
	CCLOG("hgsdk login fail");
	_login->setString("logFail");
}
static void payOnSuccess(const char *order_id, const char *item_name, int hgb_amount, const char *extra){
	CCLOG("hgsdk pay success");
	_pay->setString("paySucc");
}
static void payOnFail(int code, const char *message){
	CCLOG("hgsdk pay fail %d", code);
	_pay->setString("payFail");
}
static void showInAdOnSuccess(){
	CCLOG("hgsdk showInAd success");
	_showInAd->setString("showSucc");
}

static void showInAdOnFail(int code, const char *message){
	CCLOG("hgsdk showInAd fail %d", code);
	_showInAd->setString("showFail");
}

static void showRewardAdOnSuccess(const char *type, int amount){
	CCLOG("hgsdk showRewardAd success");
	_showRewardAd->setString("showSucc");
}

static void showRewardAdOnFail(int code, const char *message){
	CCLOG("hgsdk showRewardAd fail %d", code);
	_showRewardAd->setString("showFail");
}

static void friendsOnSuccess(const hgsdk::Friend array[], int count){
	CCLOG("hgsdk friends success");
	_friends->setString("friendSucc");
}

static void friendsOnFail(int code, const char *message){
	CCLOG("hgsdk friends fail %d", code);
	_friends->setString("friendsFail");
}

static void inviteOnSuccess(const char *request, const char *to[], int count){
	CCLOG("hgsdk invite success");
	_invite->setString("inivteSucc");
}

static void inviteOnFail(int code, const char *message){
	CCLOG("hgsdk invite fail %d", code);
	_invite->setString("inviteFail");
}

static void fbSilentOnSuccess(){
	CCLOG("hgsdk facebook silent share success");
	_shareToFacebookSilent->setString("shareSucc");
}

static void fbSilentOnFail(int code, const char *message){
	CCLOG("hgsdk facebook silent share fail %d", code);
	_shareToFacebookSilent->setString("shareFail");
}

static void hgsdkImplementsAdapter(){
	hgsdk::init("fbb006f298bd436086a9ab4f079d9caa", true);
	hgsdk::login(loginOnSuccess, loginOnFail);
	hgsdk::share("Hola Play", "very Good", "http://developers.holaverse.com/", "http://developers.holaverse.com/developer/img/logo.png");
	hgsdk::Challenge::send(0, 1, 0);
	hgsdk::Game::exit();
	hgsdk::Game::Status::start(1);
	hgsdk::Game::Status::pause();
	hgsdk::Game::Status::resume();
	hgsdk::Game::Status::pass(0, 1, 0);
	hgsdk::pay("order_idcpp", "item_namecpp", 100, "extra", payOnSuccess, payOnFail);
	hgsdk::Game::Status::over(0, 1, 0);
	hgsdk::showInAd("adc", showInAdOnSuccess, showInAdOnFail);
	hgsdk::showRewardAd(showRewardAdOnSuccess, showRewardAdOnFail);
	hgsdk::friends(40, 40, friendsOnSuccess, friendsOnFail);
	hgsdk::invite("Emancipation Proclamation", inviteOnSuccess, inviteOnFail);
	hgsdk::shareToFacebookSilent("Emancipation Proclamation", "I am happy to join u today", "http://developers.holaverse.com/", "http://developers.holaverse.com/developer/img/logo.png", fbSilentOnSuccess, fbSilentOnFail);
}
*/
void ImplementsScene::onEnter() {
	Layer::onEnter();
}
// on "init" you need to initialize your instance
bool ImplementsScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	auto size = Director::getInstance()->getWinSize();
	self = this;
	_init = MenuItemFont::create("init", CC_CALLBACK_1(ImplementsScene::initCallback, this));
	_login = MenuItemFont::create("login", CC_CALLBACK_1(ImplementsScene::loginCallback, this));
	_share = MenuItemFont::create("share", CC_CALLBACK_1(ImplementsScene::shareCallback, this));
	_challenge = MenuItemFont::create("challenge", CC_CALLBACK_1(ImplementsScene::challengeCallback, this));
	_exit1 = MenuItemFont::create("exit", CC_CALLBACK_1(ImplementsScene::exitCallback, this));
	_start = MenuItemFont::create("start", CC_CALLBACK_1(ImplementsScene::startCallback, this));
	_pause = MenuItemFont::create("pause", CC_CALLBACK_1(ImplementsScene::pauseCallback, this));
	_resume = MenuItemFont::create("resume", CC_CALLBACK_1(ImplementsScene::resumeCallback, this));
	_pass = MenuItemFont::create("pass", CC_CALLBACK_1(ImplementsScene::passCallback, this));
	_pay = MenuItemFont::create("pay", CC_CALLBACK_1(ImplementsScene::payCallback, this));
	_over = MenuItemFont::create("over", CC_CALLBACK_1(ImplementsScene::overCallback, this));
	_return = MenuItemFont::create("return", CC_CALLBACK_1(ImplementsScene::returnCallback, this));
	_showInAd = MenuItemFont::create("showInAd", CC_CALLBACK_1(ImplementsScene::showInAdCallback, this));
	_showRewardAd = MenuItemFont::create("showRewardAd", CC_CALLBACK_1(ImplementsScene::showRewardAdCallback, this));
	_friends = MenuItemFont::create("friends", CC_CALLBACK_1(ImplementsScene::friendsCallback, this));
	_invite = MenuItemFont::create("invite", CC_CALLBACK_1(ImplementsScene::inviteCallback, this));
	_shareToFacebookSilent = MenuItemFont::create("shareFBSilent", CC_CALLBACK_1(ImplementsScene::shareToFacebookSilentCallback, this));
	
	_resultTitle = LabelTTF::create("function", "Arial", 20);
	_resultTitle->setColor(Color3B(255, 255, 255));
	_resultTitle->setPosition(size.width / 2 - 200, 300);
	this->addChild(_resultTitle);
	_resultResult = LabelTTF::create("succ or fail", "Arial", 20);
	_resultResult->setColor(Color3B(255, 255, 255));
	_resultResult->setPosition(size.width / 2 - 200, 250);
	this->addChild(_resultResult);
	_resultDetail = LabelTTF::create("sth", "Arial", 20);
	_resultDetail->setColor(Color3B(255, 255, 255));
	_resultDetail->setPosition(size.width / 2 - 200, 200);
	this->addChild(_resultDetail);
	_resultDetail1 = LabelTTF::create("sth1", "Arial", 20);
	_resultDetail1->setColor(Color3B(255, 255, 255));
	_resultDetail1->setPosition(size.width / 2 - 200, 150);
	this->addChild(_resultDetail1);

	auto menu = Menu::create(_init, _login, _pay, _showInAd, _showRewardAd, NULL);
	menu->setPosition(size.width / 2, size.height - 50);
	menu->alignItemsHorizontallyWithPadding(40);
	this->addChild(menu, 0);

	auto menu1 = Menu::create( _friends, _invite, _shareToFacebookSilent, NULL);
	menu1->setPosition(size.width / 2, size.height - 150);
	menu1->alignItemsHorizontallyWithPadding(40);
	this->addChild(menu1, 0);

	auto menu2 = Menu::create(_start, _pause, _resume, _pass, _over, NULL);
	menu2->setPosition(size.width / 2, size.height - 250);
	menu2->alignItemsHorizontallyWithPadding(40);
	this->addChild(menu2, 0);

	auto menu3 = Menu::create(_share, _challenge, _exit1, _return, NULL);
	menu3->setPosition(size.width / 2, size.height - 350);
	menu3->alignItemsHorizontallyWithPadding(40);
	this->addChild(menu3, 0);

	auto spriteRotate = Sprite::create("HelloWorld.png");
	spriteRotate->setPosition(100, 250);
	auto actionBy = RotateBy::create(2, 0.0f, 360);
	spriteRotate->runAction(RepeatForever::create(actionBy));
	this->addChild(spriteRotate);
	
	return true;
}


void ImplementsScene::returnCallback(Ref* pSender)
{
	Director::getInstance()->popScene();
}

void ImplementsScene::initCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : init");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}


void ImplementsScene::loginCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : login");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::shareCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : share");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::challengeCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : chanllenge");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::exitCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : exit");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::startCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : start");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::pauseCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : pause");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::resumeCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : resume");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::passCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : pass");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}
void ImplementsScene::payCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : pay");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::overCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : over");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::showInAdCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : showInAd");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::showRewardAdCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : showRewardAd");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::friendsCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : friends");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::inviteCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : inivte");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}

void ImplementsScene::shareToFacebookSilentCallback(cocos2d::Ref* pSender)
{
	_resultTitle->setString("func : shareToFacebookSilent");
	_resultResult->setString("...");
	_resultDetail->setString("...");
	_resultDetail1->setString("...");
}