#include<string>

class Message
{
    public:

    virtual void process() = 0;

    private:

    std::string data;
};