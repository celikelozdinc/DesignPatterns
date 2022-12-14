#include "observer.h"

#include <iostream>
#include <functional>

void Publisher::registerSubscriber(std::function<void(void)> func) {
    subscriberCollection.emplace_back(std::bind(func));
}

void Publisher::notifySubscribers() const {
    for (const auto& subs : subscriberCollection) {
        subs();
    }
}

Subscriber::Subscriber(std::string&& i) : indicator(std::move(i)) {
    std::cout << "Subscriber::Subscriber\n";
}

ConcreteSubscriber::ConcreteSubscriber(std::shared_ptr<Publisher> pub, std::string&& i) :
        Subscriber(std::move(i)), publisher(pub) {
    std::cout << "ConcreteSubscriber::ConcreteSubscriber()\n";
    pub->registerSubscriber(std::bind(&ConcreteSubscriber::notify, this));
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
    ConcreteSubscriber sub1{pub, "ConcreteSubscriber1"};
    std::cout << "# subscribers that use same publisher : " << pub.use_count() << "\n";
    ConcreteSubscriber sub2{pub, "ConcreteSubscriber2"};
    std::cout << "# subscribers that use same publisher : " << pub.use_count() << "\n";
    pub->notifySubscribers();
    return EXIT_SUCCESS;
}