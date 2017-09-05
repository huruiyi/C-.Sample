#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//http://www.boost.org/doc/libs/1_59_0/doc/html/boost_asio/tutorial/tuttimer2.html

void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Hello, world!" << std::endl;
}

//Using a timer asynchronously
int main()
{
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.async_wait(&print);

	io.run();

	std::cout << "async_wait...." << std::endl;
	getchar();
	return 0;
}