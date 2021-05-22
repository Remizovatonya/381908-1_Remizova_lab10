#include "TPolinom.h"
#include "../gtest/gtest.h"

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(TPolinom P1);
}

TEST(Polynom, can_copy_polynom)
{
	TPolinom P1;
	ASSERT_NO_THROW(TPolinom P2(P1));
}

TEST(Polynom, can_operator_plus_equally)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TPolinom P1;
	ASSERT_NO_THROW(P1 += a);
}

TEST(Polynom, can_multiplicate)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);
	TPolinom P1, P2, P3;
	P1 += a;
	P2 += b;

	ASSERT_NO_THROW(P1 * P2);
}

TEST(Polynom, can_add)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);
	TPolinom P1, P2;
	P1 += a;
	P2 += b;

	ASSERT_NO_THROW(P2 + P1);
}

TEST(Polynom, can_subtract)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TMonom b(new double[3]{ 3, 2, 1 }, 3, 1);
	TPolinom P1, P2;
	P1 += a;
	P2 += b;

	ASSERT_NO_THROW(P2 - P1);
}

TEST(TPolinom, can_load_polinom_to_file)
{
	const int size = 4;
	TPolinom P;
	TMonom a(new double[3]{ 3,2,1 }, 3, 1);
	TMonom b(new double[3]{ 2,1,2 }, 3, -2);
	TMonom c(new double[3]{ 1,2,3 }, 3, 1);
	P += a;
	P += b;
	P += c;
	P.LoadToFile("output.txt");
	string expP = "1321-22121123";
	string Polinom = "";
	ifstream fin("output.txt");
	fin >> Polinom;
	fin.close();
	EXPECT_EQ(expP, Polinom);
}