#ifndef APPLICATIONEVENT_H
#define APPLICATIONEVENT_H

#include "event.h"

namespace engine {

class WindowCloseEvent : public Event
{
public:
    WindowCloseEvent() = default;

    static EventType getStaticEventType()
    {
        return EventType::WindowClose;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }
    virtual EventCategory getCategoryFlags() const override
    {
        return EventCategory::EventCategoryApplication;
    }
    virtual std::string getName() const override
    {
        return "WindowCloseEvent";
    }
};


class WindowResizeEvent : public Event
{
public:
    WindowResizeEvent(int _width, int _height)
        : width_(_width), height_(_height) { }

    static EventType getStaticEventType()
    {
        return EventType::WindowResize;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }

    virtual EventCategory getCategoryFlags() const override
    {
        return EventCategory::EventCategoryApplication;
    }

    virtual std::string getName() const override
    {
        return "WindowResizeEvent";
    }

    std::pair<int, int> getSize() const
    {
        return { width_, height_ };
    }

    int getWidth() const { return width_; }
    int getHeight() const { return height_; }

private:
    int width_, height_;

};

}

#endif // APPLICATIONEVENT_H
