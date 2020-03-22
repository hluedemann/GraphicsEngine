#ifndef APPLICATION_H
#define APPLICATION_H



namespace engine {

class Application
{
public:
    Application();
    virtual ~Application() = default;

    void run();

    inline static Application& getApplication() { return *instance_; }

private:

    bool running_;
    static Application *instance_;

};

Application* createApplication();

}

#endif // APPLICATION_H
