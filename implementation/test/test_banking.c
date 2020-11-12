	#include "unity.h"
	#include "banking.h"

	void setUp()
	{	}
	void tearDown()
	{	}
	
	void test_interest(void)
	{
  		TEST_ASSERT_EQUAL(160, interest(2.0,1000.0,8.0));
  		TEST_ASSERT_EQUAL(100, interest(5.0,500.0,5.0));
	}
	
	void test_fordelay(int j)
	{
		TEST_ASSERT_EQUAL(5,fordelay(5));
		TEST_ASSERT_EQUAL(6,fordelay(5));
	}
	
	void test_

	int test_main(void)
	{
	  	UNITY_BEGIN();
  	
	  	RUN_TEST(test_interest);
		RUN_TEST(test_fordelay);
  		return UNITY_END();
	}
