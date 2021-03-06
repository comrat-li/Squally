#pragma once

#include "cocos/ui/UITextField.h"

#include "Engine/Localization/LocalizedLabel.h"

class ConstantString;
class ClickableNode;

class InputText : public cocos2d::ui::UICCTextField
{
public:
	static InputText* create(cocos2d::Size minimumInputSize, LocalizedLabel::FontStyle fontStyle, LocalizedLabel::FontSize fontSize, bool unfuck = false);

	void focus();
	void unfocus();
	void setString(const std::string& label) override;
	void setStringChangeCallback(std::function<void(std::string)> stringChangeCallback);
	std::string getFont();
	float getFontSize();
	ClickableNode* getHitbox();

private:
	typedef UICCTextField super;
	InputText(cocos2d::Size minimumInputSize, LocalizedLabel::FontStyle fontStyle, LocalizedLabel::FontSize fontSize, bool unfuck = false);
	virtual ~InputText() = default;

	void onEnter() override;
	void update(float dt) override;
	void initializePositions();
	cocos2d::Size resize();

	// This is a hacky fix to some weird scenario where the position changes when there is input in the textfield
	bool unfuck;
	std::string stringCache;
	ConstantString* labelText;
	LocalizedLabel* inputLabel;
	ClickableNode* hitBox;
	std::function<void(std::string)> stringChangeCallback;

	cocos2d::Vec2 initCoords;
	cocos2d::Size minimumInputSize;
};
