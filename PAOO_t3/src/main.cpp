#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <semaphore.h>

class Semaphore {
public:
    Semaphore(int initialCount) {
        sem_init(&sem, 0, initialCount);
    }

    ~Semaphore() {
        sem_destroy(&sem);
    }

    void wait() {
        sem_wait(&sem);
    }

    void signal() {
        sem_post(&sem);
    }

private:
    sem_t sem;
};

class Counter {
public:
    Counter() : count(0) {}

    int getValue() const {
        return count;
    }

    void increment() {
        std::lock_guard<std::mutex> lock(mutex);
        ++count;
    }

    void decrement() {
        std::lock_guard<std::mutex> lock(mutex);
        --count;
    }

private:
    int count;
    mutable std::mutex mutex;
};

void incrementCounter(std::shared_ptr<Semaphore> incrementSemaphore, std::shared_ptr<Semaphore> decrementSemaphore, std::shared_ptr<Counter> counter) {
    for (int i = 0; i < 5; ++i) {
        incrementSemaphore->wait();
        counter->increment();
        std::cout << "Incremented: " << counter->getValue() << std::endl;
        decrementSemaphore->signal();
    }
}

void decrementCounter(std::shared_ptr<Semaphore> incrementSemaphore, std::shared_ptr<Semaphore> decrementSemaphore, std::shared_ptr<Counter> counter) {
    for (int i = 0; i < 5; ++i) {
        decrementSemaphore->wait(); 
        counter->decrement();
        std::cout << "Decremented: " << counter->getValue() << std::endl;
        incrementSemaphore->signal();
    }
}

int main() {
    auto incrementSemaphore = std::make_shared<Semaphore>(1);
    auto decrementSemaphore = std::make_shared<Semaphore>(0);

    auto counter = std::make_shared<Counter>();

    std::thread t1(incrementCounter, incrementSemaphore, decrementSemaphore, counter);
    std::thread t2(decrementCounter, incrementSemaphore, decrementSemaphore, counter);

    t1.join();
    t2.join();

    return 0;
}
