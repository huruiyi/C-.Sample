#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
//http://www.boost.org/doc/libs/1_59_0/doc/html/boost_asio/tutorial/tuttimer1.html

//Using a timer synchronously
int main()
{
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.wait();

	std::cout << "Hello, world!" << std::endl;

	getchar();
	return 0;
}