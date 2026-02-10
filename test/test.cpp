#include <catch2/catch_test_macros.hpp>
#include "GatorBST.h"
#include <vector>
#include <string>
#include <iostream>
#include <optional>
using namespace std;

TEST_CASE("Tree height/insert"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(4444, "Student 4");
	tree1.Insert(00, "Student 0");


	int height = tree1.Height();
	REQUIRE(height == 4);
}

TEST_CASE("Insert duplicate ID"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	bool has_inserted = tree1.Insert(1111, "Student 2");

	REQUIRE(has_inserted == false);
}

TEST_CASE("Empty Tree Height"){
	GatorBST tree1;
	int height = tree1.Height();
	REQUIRE(height == 0);
}

TEST_CASE("Tree height after all insert/deletion done"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Remove(1111);
	tree1.Remove(0);
	tree1.Remove(2222);
	int height = tree1.Height();
	REQUIRE(height == 0);
}

TEST_CASE("Deleting nonexistent node"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(4444, "Student 4");
	tree1.Insert(5555, "Student 5");
	tree1.Remove(00);
	tree1.Remove(4444);
	bool isRemoved = tree1.Remove(1000);

	REQUIRE(isRemoved == false);
}

TEST_CASE("Empty vector finding student after deleting their ID"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(4444, "Student 4");
	tree1.Insert(5555, "Student 5");
	tree1.Remove(00);
	tree1.Remove(4444);
	vector<int> names = tree1.SearchName("Student 4");

	REQUIRE(names.empty() == true);
}

TEST_CASE("2 same name students creates vector size of 2"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(1112, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	vector<int> names = tree1.SearchName("Student 1");

	REQUIRE(names.size() == 2);
}

TEST_CASE("First duplicate student ID is 1111"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(1112, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	vector<int> names = tree1.SearchName("Student 1");

	REQUIRE(names[0] == 1111);
}

TEST_CASE("Finds student by ID"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	optional<string_view> opt = tree1.SearchID(2222);

	REQUIRE(opt.has_value() == true);
}

TEST_CASE("In order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");

	vector<Node*> inOrder = tree1.TraverseInorder();
	REQUIRE(inOrder[0]->ufid == 00);
}

TEST_CASE("Empty vector traversal - inorder"){
	GatorBST tree1;	
	vector<Node*> inOrder = tree1.TraverseInorder();
	REQUIRE(inOrder.empty() == true);
}

TEST_CASE("Pre order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");
	
	vector<Node*> preOrder = tree1.TraversePreorder();
	REQUIRE(preOrder[0]->ufid == 1111);
}

TEST_CASE("Empty vector traversal - pre"){
	GatorBST tree1;	
	vector<Node*> preOrder = tree1.TraversePreorder();
	REQUIRE(preOrder.empty() == true);
}

TEST_CASE("Post order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");
	
	vector<Node*> postOrder = tree1.TraversePostorder();
	REQUIRE(postOrder[0]->ufid == 700);
}

TEST_CASE("Empty Post order traversal"){
	GatorBST tree1;
	vector<Node*> postOrder = tree1.TraversePostorder();
	REQUIRE(postOrder.empty() == true);
}
