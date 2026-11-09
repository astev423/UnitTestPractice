/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeating_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAAAAAAAAA11111");
	ASSERT_EQ(10, actual);
}

TEST(PasswordTest, no_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, long_repeating_leading_nums)
{
	Password my_password;
	int actual = my_password.count_leading_characters("111111111");
	ASSERT_EQ(9, actual);
}

TEST(PasswordTest, no_repeating_chars)
{
	Password my_password;
	int actual = my_password.count_leading_characters("lol");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_repeating_leading_underscores)
{
	Password my_password;
	int actual = my_password.count_leading_characters("_____________________");
	ASSERT_EQ(21, actual);
}