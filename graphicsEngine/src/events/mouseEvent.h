#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "event.h"

namespace engine {

class MouseButtonEvent : public Event
{
public:

    int getMouseButton() const { return mouseButton_; }

    virtual EventCategory getCategoryFlags() const override
    {
        return EventCategory::EventCategoryMouse;
    }

protected:
    MouseButtonEvent(int _mouseButton)
        : mouseButton_(_mouseButton){}

    int mouseButton_;

};


class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
    MouseButtonPressedEvent(int _button) : MouseButtonEvent(_button) { }

    static EventType getStaticEventType()
    {
        return EventType::MouseButtonPressed;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }

    virtual std::string getName() const override
    {
        return "MouseButtonPressedEvent";
    }
};


class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
    MouseButtonReleasedEvent(int _button) : MouseButtonEvent(_button) { }

    static EventType getStaticEventType()
    {
        return EventType::MouseButtonReleased;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }

    virtual std::string getName() const override
    {
        return "MouseButtonReleasedEvent";
    }

};


class MouseScrollEvent : public Event
{
public:
    MouseScrollEvent(double _xoffset, double _yoffset)
        : xoffset_(_xoffset), yoffset_(_yoffset) { }

    static EventType getStaticEventType()
    {
        return EventType::MouseScrolled;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }
    virtual EventCategory getCategoryFlags() const override
    {
        return EventCategory::EventCategoryMouse;
    }
    virtual std::string getName() const override
    {
        return "MouseScrollEvent";
    }

    double getXOffset() const { return xoffset_; }
    double getYOffset() const { return yoffset_; }

private:
    double xoffset_, yoffset_;

};


}


#endif // MOUSEEVENT_H
