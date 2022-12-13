#ifndef BEHAVIORAL_OBSERVER_OBSERVER_H
#define BEHAVIORAL_OBSERVER_OBSERVER_H

#include <vector>
#include <functional>
#include <memory>
#include <string>

/**
 * Subject
 */
class Publisher {
public:
    void registerSubscriber(std::function<void(void)>);
    void notifySubscribers() const;
    //TODO: need to deregister some subscribers
private:
    //TODO: need a key/value map
    std::vector<std::function<void(void)>> subscriberCollection;
};

/**
 * Base class for Subscribers/Observers
 */
class Subscriber {
public:
    Subscriber(const std::string i);
    virtual void notify() const = 0;
    virtual ~Subscriber();
protected:
    std::string indicator;
};

/**
 * Concrete subscribers
 * that are inherited from Subscriber
 */
class ConcreteSubscriber : public Subscriber {
public:
    ConcreteSubscriber(std::shared_ptr<Publisher> pub, const std::string& i);
    void notify() const override;
private:
    std::shared_ptr<Publisher> publisher;
};

#endif //BEHAVIORAL_OBSERVER_OBSERVER_H
