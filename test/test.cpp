// Note - the autograder expects this exact include for your catch code! If you use the manual catch compilation method, be sure you put this include back before submitting.
#include <catch2/catch_test_macros.hpp>

#include "GatorBST.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Tree height/insert"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");

	SECTION("heihgt is 4") {
		tree1.Insert(5123, "Student 5");
		tree1.Insert(700, "Student 4");
		int height = tree.Height();
		REQUIRE(height == 4);
	};

	SECTION("height is 3") {
		tree1.Insert(1000, "Student 5");
		tree1.Insert(2000, "Student 4");
		int height = tree.Height();
		REQUIRE(height == 3);
	};
}

TEST_CASE("Find student"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");

	String* name = tree1.SearchName("Student 3");
	
	REQUIRE(name == "Student 3");
}

TEST_CASE("Find student"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(1112, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	vector<int> names = tree1.SearchName("Student 1");
	String* name = tree1.SearchID("3333");
	
	REQUIRE(*name == 3333);
	REQUIRE(names.size() == 2);
}

TEST_CASE("Find student"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");

	String* name = tree1.SearchName("Student 3");
	
	REQUIRE(name == "Student 3");
}

TEST_CASE("In order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");

	vector<Node*> inOrder = tree1.TraverseInorder();
	REQUIRE(inOrder[i]->ufid == 00) ;
}

TEST_CASE("Pre order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");
	
	vector<Node*> preOrder = tree1.TraversePreorder();
	REQUIRE(preOrder[i]->ufid == 1111) ;
}

TEST_CASE("Post order traversal"){
	GatorBST tree1;
	tree1.Insert(1111, "Student 1");
	tree1.Insert(2222, "Student 2");
	tree1.Insert(3333, "Student 3");
	tree1.Insert(00, "Student 0");
	tree1.Insert(700, "Student 7");
	
	vector<Node*> postOrder = tree1.TraversePostorder();
	REQUIRE(postOrder[i]->ufid == 700);
}

// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...
