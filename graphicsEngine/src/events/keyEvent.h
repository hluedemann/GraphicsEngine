#ifndef KEYEVENT_H
#define KEYEVENT_H

#include "event.h"

namespace engine {

class KeyEvent : public Event
{
public:
    virtual EventCategory getCategoryFlags() const override
    {
        return EventCategory::EventCategoryKeyboard;
    }

    int getKey() const { return key_; }

protected:
    KeyEvent(int _key)
        : key_(_key) {}

private:
    int key_;

};

class KeyPressedEvent : public KeyEvent
{
public:
    KeyPressedEvent(int _key) : KeyEvent(_key) { }

    static EventType getStaticEventType()
    {
        return EventType::KeyPressd;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }
    virtual std::string getName() const override
    {
        return "KeyPressedEvent";
    }
};

class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(int _key) : KeyEvent(_key) { }

    static EventType getStaticEventType()
    {
        return EventType::KeyReleased;
    }

    virtual EventType getEventType() const override
    {
        return getStaticEventType();
    }
    virtual std::string getName() const override
    {
        return "KeyReleasedEvent";
    }
};

}

#endif // KEYEVENT_H
