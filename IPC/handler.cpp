#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class handler
{
    public:
        handler(boost::asio::io_service& io)
            : m_timer(io, boost::posix_time::seconds(1)),
            m_count(0)
    {
        m_timer.async_wait(boost::bind(&handler::message, this));
    }

        ~handler()
        {
            std::cout << "The last count : " << m_count << "\n";
        }

        void message()
        {
            if (m_count < 5)
            {
                std::cout << m_count << "\n";
                ++m_count;

                m_timer.expires_at(m_timer.expires_at() + boost::posix_time::seconds(1));
                m_timer.async_wait(boost::bind(&handler::message, this));
            }
        }

    private:
        boost::asio::deadline_timer m_timer;
        int m_count;
};

int main()
{
    boost::asio::io_service io;
    handler h(io);
    io.run();

    return 0;
}
