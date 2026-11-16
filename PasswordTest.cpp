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

TEST(PasswordTest, one_upper_and_one_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, two_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, two_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("BB");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, no_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, long_string_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("jdfssduiAHSDUHIUADHqwnekjnquihaffnbhyIUZHXCIU");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, only_symbols_no_chars)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("$*@&#^@&*!(^$*(^(*^@)!#&*``~~[;'/.,<>?:]))");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, symbols_and_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("iewjur@*#&!&@#()");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, nums_only)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("823947832477658651627941040");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, symbols_and_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("iewjur@*#&!&@#()AAAAAAAAMCKXCMOIWQJEJQWIOEIFUASIUFHUI");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, numbers_and_symbols)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("928347@#&*(@&#182398318293)");
	ASSERT_EQ(false, actual);
}
