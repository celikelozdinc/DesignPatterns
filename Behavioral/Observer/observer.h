#ifndef BEHAVIORAL_OBSERVER_OBSERVER_H
#define BEHAVIORAL_OBSERVER_OBSERVER_H

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

/**
 * Subject
 */
class Publisher {
public:
    void registerSubscriber(std::string&&, std::function<void(void)>);
    void unregisterSubscriber(std::string&&);
    void notifySubscribers() const;
private:
    std::unordered_map<std::string, std::function<void(void)>> subscriberCollection;
};

/**
 * Base class for Subscribers/Observers
 */
class Subscriber {
public:
    explicit Subscriber(std::string&& i);
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
    ConcreteSubscriber(std::string&& key, std::shared_ptr<Publisher> pub, std::string&& i);
    void notify() const override;
private:
    std::shared_ptr<Publisher> publisher;
};

#endif //BEHAVIORAL_OBSERVER_OBSERVER_H
