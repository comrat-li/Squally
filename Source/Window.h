#pragma once
#include "cocos2d.h"
#include "Game.h"
#include "audio/include/SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

/**
@brief The cocos2d Application.

Private inheritance here hides part of interface from Director.
*/
class  Window : private Application
{
public:
	Window();
	virtual ~Window();

	virtual void initGLContextAttrs();

	/**
	@brief Implement Director and Scene init code here.
	@return true Initialize success, app continue.
	@return false Initialize failed, app terminate.
	*/
	virtual bool applicationDidFinishLaunching();

	/**
	@brief Called when the application moves to the background.
	@param The pointer of the application.
	*/
	virtual void applicationDidEnterBackground();

	/**
	@brief Called when the application reenters the foreground.
	@param The pointer of the application.
	*/
	virtual void applicationWillEnterForeground();

private:
	const Size* designResolutionSize = new Size(480, 320);
	const Size* smallResolutionSize = new Size(480, 320);
	const Size* mediumResolutionSize = new Size(1024, 768);
	const Size* largeResolutionSize = new Size(2048, 1536);
};