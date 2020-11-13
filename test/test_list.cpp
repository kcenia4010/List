#include <../gtest/gtest.h>
#include <../list_lib/List.h>
#include <../list_lib/ListElem.h>

TEST(list, cen_create_default_list)
{
	ASSERT_NO_THROW(TList<int> A);
}

TEST(list, can_ins_firts)
{
	TList<int> A;
	ASSERT_NO_THROW(A.InsFirst(1));
}

TEST(list, can_ins_last)
{
	TList<int> A;
	ASSERT_NO_THROW(A.InsLast(1));
}

TEST(list, can_get)
{
	TList<int> A;
	int x1 = 1;
	A.InsLast(1);
	int result = A.GetFirst()->GetData();
	EXPECT_EQ(x1, result);
}

TEST(list, can_ins)
{
	TList<int> A;
	int x1 = 1, x2 = 2;
	A.InsFirst(x1);
	A.InsLast(x2);

	int result = A.GetFirst()->GetData();
	EXPECT_EQ(x1, result);

	result = A.GetLast()->GetData();
	EXPECT_EQ(x2, result);
}

TEST(list, can_ins_any_element)
{
	TList<int> A;
	TListElem<int>* e1;
	int x1 = 1, x2 = 2, x3 = 3, x4 = 4;
	A.InsFirst(x1);
	A.InsLast(x2);
	e1 = A.GetLast();
	A.InsLast(x4);

	ASSERT_NO_THROW(A.Ins(e1, x3));
}

TEST(list, can_delete_first)
{
	TList<int> A;
	int x1 = 1, x2 = 2, x3 = 3;
	A.InsFirst(x1);
	A.InsFirst(x2);
	A.InsLast(x3);

	ASSERT_NO_THROW(A.DelFirst());
}

TEST(list, can_delete_last)
{
	TList<int> A;
	int x1 = 1, x2 = 2, x3 = 3;
	A.InsFirst(x1);
	A.InsFirst(x2);
	A.InsLast(x3);

	ASSERT_NO_THROW(A.DelLast());
}

TEST(list, can_delete_any_element)
{
	TList<int> A;
	TListElem<int>* e1;
	int x1 = 1, x2 = 2, x3 = 3, x4 = 4;
	
	A.InsFirst(x3);
	A.InsLast(x4);
	e1 = A.GetLast();
	A.InsLast(x2);
	A.InsLast(x1);

	ASSERT_NO_THROW(A.Del(e1));
}

TEST(list, can_not_delete_in_empty_list)
{
	TList<int> A;

	ASSERT_ANY_THROW(A.DelFirst());
	ASSERT_ANY_THROW(A.DelLast());
}

TEST(list, can_found_elem)
{
	TList<int> A;
	int x1 = 1, x2 = 2, x3 = 3;
	A.InsFirst(x1);
	A.InsLast(x2);
	A.InsLast(x3);

	EXPECT_TRUE(A.elem(3));
	EXPECT_FALSE(A.elem(0));
}

TEST(list, can_swap_elements)
{
	TList<int> A;
	int x1 = 1, x2 = 2, x3 = 3;
	A.InsFirst(x1);
	A.InsLast(x2);
	A.InsLast(x3);
	A.InsFirst(x2);
	A.InsLast(x2);
	A.InsFirst(x2);

	A.swap(2, -2);

	int result = A.GetFirst()->GetData();
	EXPECT_EQ(-2, result);
	result = A.GetLast()->GetData();
	EXPECT_EQ(-2, result);

	A.DelFirst();
	A.DelLast();
	A.DelLast();

	result = A.GetFirst()->GetData();
	EXPECT_EQ(-2, result);
	result = A.GetLast()->GetData();
	EXPECT_EQ(-2, result);
}

TEST(list, can_combine_elements)
{
	TList<int> A;
	int x1 = 1, x2 = 2;
	A.InsFirst(x1);
	A.InsLast(x2);

	TList<int> B;
	int x5 = -2, x6 = -3;
	B.InsLast(x5);
	B.InsLast(x6);
	
	ASSERT_NO_THROW(A.combine(B));

	int result = A.GetLast()->GetData();
	EXPECT_EQ(x6, result);
	A.DelLast();

	result = A.GetLast()->GetData();
	EXPECT_EQ(x5, result);
	A.DelLast();

	result = A.GetLast()->GetData();
	EXPECT_EQ(x2, result);
	A.DelLast();

	result = A.GetLast()->GetData();
	EXPECT_EQ(x1, result);
}