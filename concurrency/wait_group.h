#pragma once

#include <condition_variable>
#include <mutex>
#include <thread>

class WaitGroup
{
private:
    std::mutex mutex_;
    std::condition_variable cv_;
    int count_{0};

public:
    WaitGroup() = default;
    explicit WaitGroup(int count) : count_(count) {};
    WaitGroup(const WaitGroup &) = delete;
    WaitGroup(WaitGroup &&) = delete;
    ~WaitGroup() = default;

public:
    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]
                 { return count_ == 0; });
    }

    void add(int count = 1)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if ((count_ += count) == 0)
        {
            cv_.notify_all();
        }
    }

    void done()
    {
        this->add(-1);
    }
};