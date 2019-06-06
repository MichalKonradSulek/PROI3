#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include "Product.h"
#include <string>



BOOST_AUTO_TEST_SUITE( ProductSuite )
BOOST_AUTO_TEST_CASE( testDefaultConstructor )
{
    Product prod;
	BOOST_CHECK( prod.getName() == "Something" );
    BOOST_CHECK( prod.getPrice() == 100 );
}
BOOST_AUTO_TEST_CASE( testConstructor )
{
    Product prod("name", 567);
	BOOST_CHECK( prod.getName() == "name" );
    BOOST_CHECK( prod.getPrice() == 567 );
}
BOOST_AUTO_TEST_CASE( testChangePrice )
{
    Product prod;
	prod.changePrice(53);
    BOOST_CHECK_EQUAL( prod.getPrice(), 53 );
}
BOOST_AUTO_TEST_CASE( testGetInfo )
{
    Product prod;
    BOOST_CHECK( prod.getInfo() == "--Name:Something --Price:100" );
}
BOOST_AUTO_TEST_SUITE_END()
