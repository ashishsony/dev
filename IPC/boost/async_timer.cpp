#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void work_for_io_service(const boost::system::error_code& /*e*/)
{
    std::cout << "Non-blocking wait() \n";
}

int main()
{
    boost::asio::io_service io;

    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));

    // work_for_io_service() will be called 
    // when async operation (async_wait()) finishes  
    // note: Though the async_wait() immediately returns
    //       but the callback function will be called when time expires
    timer.async_wait(&work_for_io_service);
    timer.wait();

    std::cout << " If we see this before the callback function, we know async_wait() returns immediately.\n This confirms async_wait() is non-blocking call!\n";

    // the callback function, work_for_io_service(), will be called 
    // from the thread where io.run() is running. 
    io.run();

    return 0;
}
