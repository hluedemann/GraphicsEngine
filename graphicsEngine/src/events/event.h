#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <functional>

namespace engine {

enum class EventType
{
    None = 0,
    WindowClose, WindowResize,
    KeyPressd, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved
};

enum EventCategory
{
    None = 0,
    EventCategoryApplication = 1 << 0,
    EventCategoryKeyboard = 1 << 1,
    EventCategoryMouse = 1 << 2
};

class Event
{
public:
    Event() = default;
    virtual ~Event() {}

    virtual EventType getEventType() const = 0;
    virtual EventCategory getCategoryFlags() const = 0;

    virtual std::string getName() const = 0;

    bool isInCategory(EventCategory _category)
    {
        return getCategoryFlags() & _category;
    }

};


class EventDispatcher
{
    template<typename T>
    using EventFn = std::function<void(T&)>;

public:
    EventDispatcher(Event& event) : event_(event)
    {
    }

    template<typename T>
    bool dispatch(EventFn<T> func)
    {
        if(event_.getEventType() == T::getStaticEventType())
        {
            func(*(T*)&event_);
            return true;
        }
        return false;
    }
private:
    Event& event_;
};


}


#endif // EVENT_H
