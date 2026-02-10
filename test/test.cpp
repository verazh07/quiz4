#include <catch2/catch_test_macros.hpp>
#include "GatorBST.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

TEST_CASE("Tree height/insert"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");

	SECTION("heihgt is 4") {
		tree1.Insert(5123, "Student 5");
		tree1.Insert(700, "Student 4");
		int height = tree1.Height();
		REQUIRE(height == 4);
	};

	SECTION("height is 3") {
		tree1.Insert(1000, "Student 5");
		tree1.Insert(2000, "Student 4");
		int height = tree1.Height();
		REQUIRE(height == 3);
	};
}

TEST_CASE("Find student by name"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(1112, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	vector<int> names = tree1.SearchName("Student 1");

	REQUIRE(names.size() == 2);
}

TEST_CASE("In order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");

	vector<Node*> inOrder = tree1.TraverseInorder();
	REQUIRE(inOrder[0]->ufid == 00) ;
}

TEST_CASE("Pre order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");
	
	vector<Node*> preOrder = tree1.TraversePreorder();
	REQUIRE(preOrder[0]->ufid == 1111) ;
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

// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...
