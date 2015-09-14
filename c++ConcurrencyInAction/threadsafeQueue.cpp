#include <mutex>
#include<queue>
#include<memory>
#include<conditional_variable>

template <typename T>
class threadsafe_queue
{
    private:
        mutable std::mutex mut;
        std::queue<T> data_queue;
        std::condition_variable data_cond;
    public:
        threadsafe_queue();
        threadsafe_queue(threadsafe_queue const& other)
        {
            std::lock_guard<std::mutex> lg(other.mut);
            data_queue=other.data_queue;
        }
        void push(T new_val)
        {
            std::lock_guard<std::mutex> lg(mut);
            data_queue.push(new_val);
            data_cond.notify_one();
        }
        void wait_and_pop(T &value)
        {
            std::unique_lock<std::mutex> ulk(mut);
            data_cond.wait(ulk,[this]{return !data_queue.empty();});
            value=data_queue.front();
            data_queue.pop();
        }
        std::shared_ptr<T> wait_and_pop()
        {
            std::unique_lock<std::mutex> ulk(mut);
            data_cond.wait(ulk,[this]{return !data_queue.empty();});
            std::shared_ptr<T> res = std::make_shared<T>(data_queue.front());
            data_queue.pop();
            return res;
        }
        bool try_pop(T &value)
        {
            std::lock_guard<std::mutex> lg(mut);
            if(data_queue.empty())
                return false;
            value=data_queue.front();
            data_queue.pop();
            return true;
        }
        std::shared_ptr() try_pop()
        {
            std::lock_guard<std::mutex> lg(mut);
            if(data_queue.empty())
                return std::shared_ptr<T>();
            std shared_ptr<T> res(std::make_shared(data_queue.front()));
            data_queue.pop();
            return res;
        }

        bool empty()
        {
            std::lock_guard<std::mutex> lg(mut);
            return data_queue.empty();
        }
};
int main()
{}
