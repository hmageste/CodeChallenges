/*
* Question:
* Write a function to crush candy in a one dimensional board.
* In candy crusing games, groups of like items are removed from the board.
* In this problem, any sequence of 3 or more like items should be removed and
* any items adjacent to that sequence should now be considered adjacent to each
* other. This process should be repeated as many time as possible.
*
* Sample Inputs -> Expected Outputs
* ABBBCC        -> ACC
* ABCCCBB       -> A
* ABCCCBBAAC    -> C
*/

#include "pch.h"

#include "CandyCrashSolvers.h"

#include <string>
using namespace std;

TEST(StackApproach, Sample1) {
    const string input = "AAABB";
    const string expected_ouput = "BB";

    const string output = stack_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(StackApproach, Sample2) {
    const string input = "CCAAABBBBCC";
    const string expected_ouput = "";

    const string output = stack_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(StackApproach, Sample3) {
    const string input = "ABBBCC";
    const string expected_ouput = "ACC";

    const string output = stack_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(StackApproach, Sample4) {
    const string input = "ABCCCBB";
    const string expected_ouput = "A";

    const string output = stack_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(StackApproach, Sample5) {
    const string input = "ABCCCBBAAC";
    const string expected_ouput = "C";

    const string output = stack_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(IteratorApproach, Sample1) {
    const string input = "AAABB";
    const string expected_ouput = "BB";

    const string output = recursive_iterator_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(IteratorApproach, Sample2) {
    const string input = "CCAAABBBBCC";
    const string expected_ouput = "";

    const string output = recursive_iterator_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(IteratorApproach, Sample3) {
    const string input = "ABBBCC";
    const string expected_ouput = "ACC";

    const string output = recursive_iterator_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(IteratorApproach, Sample4) {
    const string input = "ABCCCBB";
    const string expected_ouput = "A";

    const string output = recursive_iterator_approach(input);

    EXPECT_EQ(output, expected_ouput);
}

TEST(IteratorApproach, Sample5) {
    const string input = "ABCCCBBAAC";
    const string expected_ouput = "C";

    const string output = recursive_iterator_approach(input);

    EXPECT_EQ(output, expected_ouput);
}