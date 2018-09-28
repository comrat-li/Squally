#include "MouseEvents.h"

const std::string MouseEvents::MouseMoveEvent = "EVENT_MOUSE_MOVE";
const std::string MouseEvents::MouseRefreshEvent = "EVENT_MOUSE_REFRESH";
const std::string MouseEvents::MouseDownEvent = "EVENT_MOUSE_DOWN";
const std::string MouseEvents::MouseUpEvent = "EVENT_MOUSE_UP";
const std::string MouseEvents::MouseScrollEvent = "EVENT_MOUSE_SCROLL";
const std::string MouseEvents::ClickableMouseOverEvent = "EVENT_CLICKABLE_MOUSE_OVER";
const std::string MouseEvents::ClickableMouseOutEvent = "EVENT_CLICKABLE_MOUSE_OUT";
const std::string MouseEvents::MouseDragEvent = "EVENT_MOUSE_DRAG";
const std::string MouseEvents::MouseStateUpdateEvent = "EVENT_MOUSE_STATE_UPDATE";

void MouseEvents::TriggerMouseMove(MouseEventArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseMoveEvent,
		&args
	);
}

void MouseEvents::TriggerMouseRefresh(MouseEventArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseRefreshEvent,
		&args
	);
}

void MouseEvents::TriggerMouseDown(MouseEventArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseDownEvent,
		&args
	);
}

void MouseEvents::TriggerMouseUp(MouseEventArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseUpEvent,
		&args
	);
}

void MouseEvents::TriggerStateChange(MouseEventArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseStateUpdateEvent,
		&args
	);
}

void MouseEvents::TriggerClickableMouseOverEvent()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::ClickableMouseOverEvent
	);
}

void MouseEvents::TriggerClickableMouseOutEvent()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::ClickableMouseOutEvent
	);
}

void MouseEvents::TriggerDragEvent()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseDragEvent
	);
}

void MouseEvents::TriggerMouseScroll()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		MouseEvents::MouseScrollEvent
	);
}