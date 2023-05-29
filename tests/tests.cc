// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>
#include <vector>

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(WordLocation left, WordLocation right) {
    if (left.char_positions.size() != right.char_positions.size()) {
        return false;
    }
    for (unsigned int i = 0; i < left.char_positions.size(); i++) {
        CharPositions &l = left.char_positions[i];
        CharPositions &r = right.char_positions[i];
        if (l.character != r.character || l.row != r.row || l.col != r.col) {
            return false;
        }
    }
    return true;
} 
/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

/*
EMPTY BOARD(treat z as an empty character):

std::vector<std::vector<char>> A = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
};

*/
//
//   REMEMBER TO CHECK 2 IN 1S
//
TEST_CASE("True == True", "") { REQUIRE(true == true); }
TEST_CASE("horizontal", "") {
    std::vector<std::vector<char>> Empty = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver A(Empty);
    WordLocation SolA = {};
    REQUIRE(A.FindWord("Alan", CheckDirection::kHorizontal) == SolA);
    REQUIRE(A.FindWord("Alan") == SolA);

    std::vector<std::vector<char>> One = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {'A','L','A','N',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver B(One);
    CharPositions OneA = {'A', 2, 0};
    CharPositions OneB = {'L', 2, 1};
    CharPositions OneC = {'A', 2, 2};
    CharPositions OneD = {'N', 2, 3};
    std::vector<CharPositions> hold = {OneA, OneB, OneC, OneD};
    WordLocation SolB = {"ALAN",hold};
    REQUIRE(B.FindWord("ALAN", CheckDirection::kHorizontal) == SolB);
    REQUIRE(B.FindWord("ALAN") == SolB);

    std::vector<std::vector<char>> Two = {
    {' ','A','L','A','N'}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver C(Two);
    OneA = {'A', 0, 1};
    OneB = {'L', 0, 2};
    OneC = {'A', 0, 3};
    OneD = {'N', 0, 4};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolC = {"ALAN",hold};
    REQUIRE(C.FindWord("ALAN", CheckDirection::kHorizontal) == SolC);
    REQUIRE(C.FindWord("ALAN") == SolC);


    Two = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {'A','L','A','N',' '}
    };
    WordSearchSolver D(Two);
    OneA = {'A', 4, 0};
    OneB = {'L', 4, 1};
    OneC = {'A', 4, 2};
    OneD = {'N', 4, 3};
    hold = {OneA, OneB, OneC, OneD};
    SolC = {"ALAN",hold};
    REQUIRE(D.FindWord("ALAN", CheckDirection::kHorizontal) == SolC);
    REQUIRE(D.FindWord("ALAN") == SolC);

    Two = {
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' ',' '}, 
    {'A','L','A','L','A','N'}
    };
    WordSearchSolver E(Two);
    OneA = {'A', 4, 2};
    OneB = {'L', 4, 3};
    OneC = {'A', 4, 4};
    OneD = {'N', 4, 5};
    hold = {OneA, OneB, OneC, OneD};
    SolC = {"ALAN",hold};
    REQUIRE(E.FindWord("ALAN", CheckDirection::kHorizontal) == SolC);
    REQUIRE(E.FindWord("ALAN") == SolC);

    Two = {
    {' ',' ',' ',' ',' ',' '}, 
    {'A','L','A',' ',' ',' '},
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ','A','L','A','N'}
    };
    WordSearchSolver F(Two);
    OneA = {'A', 4, 2};
    OneB = {'L', 4, 3};
    OneC = {'A', 4, 4};
    OneD = {'N', 4, 5};
    hold = {OneA, OneB, OneC, OneD};
    SolC = {"ALAN",hold};
    REQUIRE(F.FindWord("ALAN", CheckDirection::kHorizontal) == SolC);
    REQUIRE(F.FindWord("ALAN") == SolC);

    Two = {
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' ',' '}, 
    {'A','L','F','L','A','N'}
    };
    WordSearchSolver G(Two);
    REQUIRE(G.FindWord("ALAN", CheckDirection::kHorizontal) == SolA);
    REQUIRE(G.FindWord("ALAN") == SolA);
}
TEST_CASE("vertical", "") {
    std::vector<std::vector<char>> Empty = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver A(Empty);
    WordLocation SolA = {};
    REQUIRE(A.FindWord("Alan", CheckDirection::kVertical) == SolA);
    REQUIRE(A.FindWord("Alan") == SolA);
    std::vector<std::vector<char>> One = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ','A',' ',' '},
    {' ',' ','L',' ',' '}, 
    {' ',' ','A',' ',' '}, 
    {' ',' ','N',' ',' '}
    };
    WordSearchSolver B(One);
    CharPositions OneA = {'A', 1, 2};
    CharPositions OneB = {'L', 2, 2};
    CharPositions OneC = {'A', 3, 2};
    CharPositions OneD = {'N', 4, 2};
    std::vector<CharPositions> hold = {OneA, OneB, OneC, OneD};
    WordLocation SolB = {"ALAN",hold};
    REQUIRE(B.FindWord("ALAN", CheckDirection::kVertical) == SolB); 
    REQUIRE(B.FindWord("ALAN") == SolB); 

    std::vector<std::vector<char>> Two = {
    {'A',' ',' ',' ',' '}, 
    {'L',' ',' ',' ',' '},
    {'A',' ',' ',' ',' '}, 
    {'N',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver C(Two);
    OneA = {'A', 0, 0};
    OneB = {'L', 1, 0};
    OneC = {'A', 2, 0};
    OneD = {'N', 3, 0};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolC = {"ALAN",hold};
    REQUIRE(C.FindWord("ALAN", CheckDirection::kVertical) == SolC); 
    REQUIRE(C.FindWord("ALAN") == SolC); 

    std::vector<std::vector<char>> Three = {
    {' ',' ',' ',' ','A'}, 
    {' ',' ',' ',' ','L'},
    {' ',' ',' ',' ','A'}, 
    {' ',' ',' ',' ','N'}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver D(Three);
    OneA = {'A', 0, 4};
    OneB = {'L', 1, 4};
    OneC = {'A', 2, 4};
    OneD = {'N', 3, 4};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolD = {"ALAN",hold};
    REQUIRE(D.FindWord("ALAN", CheckDirection::kVertical) == SolD);
    REQUIRE(D.FindWord("ALAN") == SolD);
    //do partial word and then the full word
    Three = {
    {' ','A',' ','A',' '}, 
    {' ','L',' ','L',' '},
    {' ','A',' ','A',' '}, 
    {' ',' ',' ','N',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver E(Three);
    OneA = {'A', 0, 3};
    OneB = {'L', 1, 3};
    OneC = {'A', 2, 3};
    OneD = {'N', 3, 3};
    hold = {OneA, OneB, OneC, OneD};
    SolD = {"ALAN",hold};
    REQUIRE(E.FindWord("ALAN", CheckDirection::kVertical) == SolD);
    REQUIRE(E.FindWord("ALAN") == SolD);
    //do a split word
    //ALALAN
    Three = {
    {' ','A',' ',' ',' '}, 
    {' ','L',' ',' ',' '},
    {' ','N',' ',' ',' '}, 
    {' ','L',' ',' ',' '}, 
    {' ','A',' ',' ',' '},
    {' ','N',' ',' ',' '}
    };
    WordSearchSolver F(Three);
    REQUIRE(F.FindWord("ALAN", CheckDirection::kVertical) == SolA);
    REQUIRE(F.FindWord("ALAN") == SolA);
    Three = {
    {' ','A',' ',' ',' '}, 
    {' ','L',' ',' ',' '},
    {' ','A',' ',' ',' '}, 
    {' ','L',' ',' ',' '}, 
    {' ','A',' ',' ',' '},
    {' ','N',' ',' ',' '}
    };
    WordSearchSolver G(Three);
    OneA = {'A', 2, 1};
    OneB = {'L', 3, 1};
    OneC = {'A', 4, 1};
    OneD = {'N', 5, 1};
    hold = {OneA, OneB, OneC, OneD};
    SolD = {"ALAN",hold};
    REQUIRE(G.FindWord("ALAN", CheckDirection::kVertical) == SolD);
    REQUIRE(G.FindWord("ALAN") == SolD);
}
TEST_CASE("leftDiag", "") {
    std::vector<std::vector<char>> Empty = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver A(Empty);
    WordLocation SolA = {};
    REQUIRE(A.FindWord("Alan", CheckDirection::kLeftDiag) == SolA); 
    REQUIRE(A.FindWord("Alan") == SolA); 
    std::vector<std::vector<char>> One = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ','A',' '},
    {' ',' ','L',' ',' '}, 
    {' ','A',' ',' ',' '}, 
    {'N',' ',' ',' ',' '}
    };
    WordSearchSolver B(One);
    CharPositions OneA = {'A', 1, 3};
    CharPositions OneB = {'L', 2, 2};
    CharPositions OneC = {'A', 3, 1};
    CharPositions OneD = {'N', 4, 0};
    std::vector<CharPositions> hold = {OneA, OneB, OneC, OneD};
    WordLocation SolB = {"ALAN",hold};
    REQUIRE(B.FindWord("ALAN", CheckDirection::kLeftDiag) == SolB);
    REQUIRE(B.FindWord("ALAN") == SolB);

    std::vector<std::vector<char>> Two = {
    {' ',' ',' ','A',' '}, 
    {' ',' ','L',' ',' '},
    {' ','A',' ',' ',' '}, 
    {'N',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver C(Two);
    OneA = {'A', 0, 3};
    OneB = {'L', 1, 2};
    OneC = {'A', 2, 1};
    OneD = {'N', 3, 0};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolC = {"ALAN",hold};
    REQUIRE(C.FindWord("ALAN", CheckDirection::kLeftDiag) == SolC); 
    REQUIRE(C.FindWord("ALAN") == SolC); 

    std::vector<std::vector<char>> Three = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ','A'},
    {' ',' ',' ','L',' '}, 
    {' ',' ','A',' ',' '}, 
    {' ','N',' ',' ',' '}
    };
    WordSearchSolver D(Three);
    OneA = {'A', 1, 4};
    OneB = {'L', 2, 3};
    OneC = {'A', 3, 2};
    OneD = {'N', 4, 1};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolD = {"ALAN",hold};
    REQUIRE(D.FindWord("ALAN", CheckDirection::kLeftDiag) == SolD); 
    REQUIRE(D.FindWord("ALAN") == SolD); 

    Three = {
    {' ',' ',' ',' ',' ','A'}, 
    {' ',' ',' ',' ','L',' '},
    {' ',' ',' ','A',' ',' '}, 
    {' ',' ','L',' ',' ',' '}, 
    {' ','A',' ',' ',' ',' '}, 
    {'N',' ',' ',' ',' ',' '}
    };
    WordSearchSolver E(Three);
    OneA = {'A', 2, 3};
    OneB = {'L', 3, 2};
    OneC = {'A', 4, 1};
    OneD = {'N', 5, 0};
    hold = {OneA, OneB, OneC, OneD};
    SolD = {"ALAN",hold};
    REQUIRE(E.FindWord("ALAN", CheckDirection::kLeftDiag) == SolD); 
    REQUIRE(E.FindWord("ALAN") == SolD); 

    Three = {
    {' ',' ',' ','A',' ',' '}, 
    {' ',' ','L',' ',' ',' '},
    {' ','A',' ','A',' ',' '}, 
    {' ',' ','L',' ',' ',' '}, 
    {' ','A',' ',' ',' ',' '}, 
    {'N',' ',' ',' ',' ',' '}
    };
    WordSearchSolver F(Three);
    OneA = {'A', 2, 3};
    OneB = {'L', 3, 2};
    OneC = {'A', 4, 1};
    OneD = {'N', 5, 0};
    hold = {OneA, OneB, OneC, OneD};
    SolD = {"ALAN",hold};
    REQUIRE(F.FindWord("ALAN", CheckDirection::kLeftDiag) == SolD); 
    REQUIRE(F.FindWord("ALAN") == SolD); 

    Three = {
    {' ',' ',' ',' ',' ','A'}, 
    {' ',' ',' ',' ','L',' '},
    {' ',' ',' ','F',' ',' '}, 
    {' ',' ','L',' ',' ',' '}, 
    {' ','A',' ',' ',' ',' '}, 
    {'N',' ',' ',' ',' ',' '}
    };
    WordSearchSolver G(Three);
    REQUIRE(G.FindWord("ALAN", CheckDirection::kLeftDiag) == SolA); 
    REQUIRE(G.FindWord("ALAN") == SolA); 
}
TEST_CASE("rightDiag", "") {
    std::vector<std::vector<char>> Empty = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver A(Empty);
    WordLocation SolA = {};
    REQUIRE(A.FindWord("Alan", CheckDirection::kRightDiag) == SolA); 
    REQUIRE(A.FindWord("Alan") == SolA); 
    std::vector<std::vector<char>> One = {
    {' ',' ',' ',' ',' '}, 
    {'A',' ',' ',' ',' '},
    {' ','L',' ',' ',' '}, 
    {' ',' ','A',' ',' '}, 
    {' ',' ',' ','N',' '}
    };
    WordSearchSolver B(One);
    CharPositions OneA = {'A', 1, 0};
    CharPositions OneB = {'L', 2, 1};
    CharPositions OneC = {'A', 3, 2};
    CharPositions OneD = {'N', 4, 3};
    std::vector<CharPositions> hold = {OneA, OneB, OneC, OneD};
    WordLocation SolB = {"ALAN",hold};
    REQUIRE(B.FindWord("ALAN", CheckDirection::kRightDiag) == SolB); 
    REQUIRE(B.FindWord("ALAN") == SolB); 

    std::vector<std::vector<char>> Two = {
    {'A',' ',' ',' ',' '}, 
    {' ','L',' ',' ',' '},
    {' ',' ','A',' ',' '}, 
    {' ',' ',' ','N',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver C(Two);
    OneA = {'A', 0, 0};
    OneB = {'L', 1, 1};
    OneC = {'A', 2, 2};
    OneD = {'N', 3, 3};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolC = {"ALAN",hold};
    REQUIRE(C.FindWord("ALAN", CheckDirection::kRightDiag) == SolC); 
    REQUIRE(C.FindWord("ALAN") == SolC);

    std::vector<std::vector<char>> Three = {
    {' ','A',' ',' ',' '}, 
    {' ',' ','L',' ',' '},
    {' ',' ',' ','A',' '}, 
    {' ',' ',' ',' ','N'}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver D(Three);
    OneA = {'A', 0, 1};
    OneB = {'L', 1, 2};
    OneC = {'A', 2, 3};
    OneD = {'N', 3, 4};
    hold = {OneA, OneB, OneC, OneD};
    WordLocation SolD = {"ALAN",hold};
    REQUIRE(D.FindWord("ALAN", CheckDirection::kRightDiag) == SolD);
    REQUIRE(D.FindWord("ALAN") == SolD);

    Three = {
    {'A',' ',' ',' ',' ',' '}, 
    {' ','L',' ',' ',' ',' '},
    {' ',' ','A',' ',' ',' '}, 
    {' ',' ',' ','L',' ',' '}, 
    {' ',' ',' ',' ','A',' '}, 
    {' ',' ',' ',' ',' ','N'}
    };
    WordSearchSolver E(Three);
    OneA = {'A', 2, 2};
    OneB = {'L', 3, 3};
    OneC = {'A', 4, 4};
    OneD = {'N', 5, 5};
    hold = {OneA, OneB, OneC, OneD};
    SolD = {"ALAN",hold};
    REQUIRE(E.FindWord("ALAN", CheckDirection::kRightDiag) == SolD);
    REQUIRE(E.FindWord("ALAN") == SolD);

    Three = {
    {'A',' ','A',' ',' ',' '}, 
    {' ','L',' ','L',' ',' '},
    {' ',' ','A',' ','A',' '}, 
    {' ',' ',' ',' ',' ','N'}, 
    {' ',' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' ',' '}
    };
    WordSearchSolver F(Three);
    OneA = {'A', 0, 2};
    OneB = {'L', 1, 3};
    OneC = {'A', 2, 4};
    OneD = {'N', 3, 5};
    hold = {OneA, OneB, OneC, OneD};
    SolD = {"ALAN",hold};
    REQUIRE(F.FindWord("ALAN", CheckDirection::kRightDiag) == SolD);
    REQUIRE(F.FindWord("ALAN") == SolD);

    Three = {
    {'A',' ',' ',' ',' ',' '}, 
    {' ','L',' ',' ',' ',' '},
    {' ',' ','F',' ',' ',' '}, 
    {' ',' ',' ','L',' ',' '}, 
    {' ',' ',' ',' ','A',' '}, 
    {' ',' ',' ',' ',' ','N'}
    };
    WordSearchSolver G(Three);
    REQUIRE(G.FindWord("ALAN", CheckDirection::kRightDiag) == SolA);
    REQUIRE(G.FindWord("ALAN") == SolA);
}
TEST_CASE("last","") {
    std::vector<std::vector<char>> Empty = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver A(Empty);
    WordLocation SolA = {};
    REQUIRE(A.FindWord("Alan") == SolA); 

    std::vector<std::vector<char>> One = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '},
    {'A','L','A','N',' '}, 
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ',' ',' '}
    };
    WordSearchSolver B(One);
    CharPositions OneA = {'A', 2, 0};
    CharPositions OneB = {'L', 2, 1};
    CharPositions OneC = {'A', 2, 2};
    CharPositions OneD = {'N', 2, 3};
    std::vector<CharPositions> hold = {OneA, OneB, OneC, OneD};
    WordLocation SolB = {"ALAN",hold};
    REQUIRE(B.FindWord("ALAN", CheckDirection::kHorizontal) == SolB);

    One = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ','A',' ',' '},
    {' ',' ','L',' ',' '}, 
    {' ',' ','A',' ',' '}, 
    {' ',' ','N',' ',' '}
    };
    WordSearchSolver C(One);
    OneA = {'A', 1, 2};
    OneB = {'L', 2, 2};
    OneC = {'A', 3, 2};
    OneD = {'N', 4, 2};
    hold = {OneA, OneB, OneC, OneD};
    SolB = {"ALAN",hold};
    REQUIRE(C.FindWord("ALAN", CheckDirection::kVertical) == SolB);

    One = {
    {' ',' ',' ',' ',' '}, 
    {' ',' ',' ','A',' '},
    {' ',' ','L',' ',' '}, 
    {' ','A',' ',' ',' '}, 
    {'N',' ',' ',' ',' '}
    };
    WordSearchSolver D(One);
    OneA = {'A', 1, 3};
    OneB = {'L', 2, 2};
    OneC = {'A', 3, 1};
    OneD = {'N', 4, 0};
    hold = {OneA, OneB, OneC, OneD};
    SolB = {"ALAN",hold};
    REQUIRE(D.FindWord("ALAN", CheckDirection::kLeftDiag) == SolB);

    One = {
    {' ',' ',' ',' ',' '}, 
    {'A',' ',' ',' ',' '},
    {' ','L',' ',' ',' '}, 
    {' ',' ','A',' ',' '}, 
    {' ',' ',' ','N',' '}
    };
    WordSearchSolver E(One);
    OneA = {'A', 1, 0};
    OneB = {'L', 2, 1};
    OneC = {'A', 3, 2};
    OneD = {'N', 4, 3};
    hold = {OneA, OneB, OneC, OneD};
    SolB = {"ALAN",hold};
    REQUIRE(E.FindWord("ALAN", CheckDirection::kRightDiag) == SolB); 

}
/////////////////////////////////////////////////////////////////////////////////////////////