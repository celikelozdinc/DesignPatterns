#include "observer.h"

#include <iostream>
#include <functional>
#include <utility>

void Publisher::registerSubscriber(std::string&& key, std::function<void(void)> func) {
    subscriberCollection.insert({std::move(key), std::bind(func)});
}

void Publisher::unregisterSubscriber(std::string&& key) {
    auto matchedKey = [&](const auto& elem){
      return (key == elem.first);
    };

    auto it = std::find_if(subscriberCollection.begin(), subscriberCollection.end(), matchedKey);
    if (subscriberCollection.end() != it) {
      std::cout << "Found a callback for the key : " << it->first << "\n";
      subscriberCollection.erase(it);
    } else {
      std::cout << "Could not find a callback for the key : " << key << "\n";
    }
}

void Publisher::notifySubscribers() const {
    for (const auto& [key, callback] : subscriberCollection) {
      callback();
      subscriberCollection.at(key)();
    }
}

Subscriber::Subscriber(std::string&& i) : indicator(std::move(i)) {
    std::cout << "Subscriber::Subscriber\n";
}

ConcreteSubscriber::ConcreteSubscriber(std::string&& key, std::shared_ptr<Publisher> pub, std::string&& i) :
        Subscriber(std::move(i)), publisher(pub) {
    std::cout << "ConcreteSubscriber::ConcreteSubscriber()\n";
    pub->registerSubscriber(std::move(key), std::bind(&ConcreteSubscriber::notify, this));
}

Subscriber::~Subscriber() {
    std::cout << "Subscriber::~Subscriber()\n";
}

void ConcreteSubscriber::notify() const {
    std::cout << "Hello from {"<< this->indicator << "}\n";
}

int main() {
    auto pub = std::make_shared<Publisher>();
    std::cout << "# subscribers that use same publisher : " << pub.use_count() << "\n";
    ConcreteSubscriber sub1{"KEY1", pub, "ConcreteSubscriber1"};
    std::cout << "# subscribers that use same publisher : " << pub.use_count() << "\n";
    ConcreteSubscriber sub2{"KEY2", pub, "ConcreteSubscriber2"};
    std::cout << "# subscribers that use same publisher : " << pub.use_count() << "\n";
    pub->notifySubscribers();
    pub->unregisterSubscriber("KEY4");
    pub->unregisterSubscriber("KEY2");
    pub->notifySubscribers();
    return EXIT_SUCCESS;
}