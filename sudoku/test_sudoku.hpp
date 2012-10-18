#include <cxxtest/TestSuite.h>
#include <sstream>
#include <iterator>
#define private public 
#include "Board.hpp"
#undef private

#include "Solver.hpp"

using sudoku::Board;

class SudokuBoardTest : public CxxTest::TestSuite
{
  public:
    SudokuBoardTest()
    {
    }

    void test_board_can_be_properly_initialized_with_input_iterator()
    {
      std::stringstream sstr("1");
      std::istream_iterator<Board::CellType> last;
      Board testBoard{std::istream_iterator<Board::CellType>(sstr),last,1,1};
      TS_ASSERT_EQUALS( testBoard.size(), 1 );
      TS_ASSERT_EQUALS( testBoard(0,0), 1 );

      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  1, 2, 3, 4,  1, 2, 3, 4,  1, 2, 3, 4};
      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS( testBoardBig.size(), 4 );
      TS_ASSERT_EQUALS( testBoardBig(3,0), 3 );

      for( size_t y=0; y<=3; ++y)
      {
        for ( size_t x=0; x<=3; ++x)
        {
          TS_ASSERT_EQUALS( testBoardBig(x,y), sstrBig[y*testBoardBig.size()+x]);
        }
      }

      std::stringstream sstrThrowLess("0 1 2 3  0 0 0 0  0 0 0 0  0 0 0");
      TS_ASSERT_THROWS(Board(std::istream_iterator<Board::CellType>(sstrThrowLess),last,2,2), Board::InvalidSizeException);

      std::stringstream sstrThrowMore("0 1 2 3  0 0 0 0  0 0 0 0  0 0 0 3 1234467670");
      TS_ASSERT_THROWS(Board(std::istream_iterator<Board::CellType>(sstrThrowMore),last,2,2), Board::InvalidSizeException);
    }

    void test_board_can_only_be_initialized_with_valid_values()
    {
      std::vector<Board::CellType> vec{0, 1, 2, 3,  11, 12, 13, 14,  21, 22, 23, 24,  31, 32, 33, 34};
      TS_ASSERT_THROWS(Board(vec.begin(), vec.end(), 2, 2), Board::InvalidValueException);
    }
    

    void test_board_getRow_function_works()
    {
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  2, 2, 1, 1,  1, 4, 3, 2,  4, 4, 4, 4};

      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS(testBoardBig.getRow(0,1), (Board::CellContainer{2, 2, 1, 1}));
      TS_ASSERT_EQUALS(testBoardBig.getRow(0,0), (Board::CellContainer{0, 1, 2, 3}));
      TS_ASSERT_EQUALS(testBoardBig.getRow(1), (Board::CellContainer{2, 2, 1, 1}));
      TS_ASSERT_EQUALS(testBoardBig.getRow(0), (Board::CellContainer{0, 1, 2, 3}));
    }

    void test_board_getColumn_function_works()
    {
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  2, 2, 1, 1,  1, 4, 3, 2,  4, 4, 4, 4};

      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS(testBoardBig.getColumn(1), (Board::CellContainer{1, 2, 4, 4}));
      TS_ASSERT_EQUALS(testBoardBig.getColumn(1, 0), (Board::CellContainer{1, 2, 4, 4}));
    }

    void test_board_getBox_function_works()
    {
      std::vector<Board::CellType> sstrBig{0, 1, 2, 3,  2, 2, 1, 1,  1, 4, 3, 2,  4, 4, 4, 4};

      Board testBoardBig{sstrBig.begin(),sstrBig.end(),2,2};
      TS_ASSERT_EQUALS(testBoardBig.getBox(1), (Board::CellContainer{2, 3, 1, 1}));
      TS_ASSERT_EQUALS(testBoardBig.getBox(1,1), (Board::CellContainer{0, 1, 2, 2}));
    }


    void test_board_CellContainer_isValid()
    {
      TS_ASSERT(Board::isValid(Board::CellContainer{0, 1, 2, 3}));
      TS_ASSERT(Board::isValid(Board::CellContainer{0, 0, 0, 0}));
      TS_ASSERT(Board::isValid(Board::CellContainer{1, 2, 3, 4}));
      TS_ASSERT(!Board::isValid(Board::CellContainer{0, 2, 2, 3}));
    }

    void test_if_board_is_valid()
    {
      Board::CellType brd[] = { 1 };
      Board easyBoard(&brd[0], &brd[1], 1, 1);
      TS_ASSERT( easyBoard.isValid() );

      Board::CellType brd2[] = {0, 4, 3, 0, 0, 0, 2, 7, 0, 8, 0, 0, 0, 0, 0, 0, 0, 9, 2, 0, 9, 0, 0, 0, 5, 0, 6, 0, 0, 0, 2, 6, 9, 0, 0, 0, 0, 0, 0, 8, 0, 5, 0, 0, 0, 0, 0, 0, 1, 7, 4, 0, 0, 0, 9, 0, 7, 0, 0, 0, 1, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 2, 0, 5, 2, 0, 0, 0, 6, 3, 0};
      Board bigBoard(&brd2[0], &brd2[81], 3, 3);
      TS_ASSERT( bigBoard.isValid() );

      Board::CellType brd_ok[] =
      { 0, 4, 3, 0, 0, 0, 2, 7, 0,
        2, 0, 0, 0, 0, 0, 0, 9, 0,
        0, 9, 0, 0, 0, 5, 0, 6, 0,
        0, 0, 2, 6, 9, 0, 0, 0, 0,
        0, 0, 8, 0, 5, 0, 0, 0, 0,
        0, 0, 1, 7, 4, 0, 0, 0, 9,
        0, 7, 0, 0, 0, 1, 0, 0, 4,
        0, 0, 0, 0, 0, 0, 0, 2, 0,
        5, 2, 0, 0, 0, 6, 3, 0, 8};
      Board board_ok(&brd_ok[0], &brd_ok[81], 3, 3);
      TS_ASSERT( board_ok.isValid() );

      Board::CellType brd_row_error[] =
      { 0, 4, 3, 0, 0, 0, 2, 7, 0,
        2, 0, 0, 0, 0, 0, 0, 9, 0,
        0, 9, 0, 0, 0, 5, 0, 6, 0,
        0, 0, 2, 6, 9, 0, 0, 0, 0,
        0, 0, 8, 0, 5, 0, 0, 0, 0,
        0, 0, 1, 7, 4, 0, 0, 0, 9,
        0, 7, 0, 0, 0, 1, 0, 0, 4,
        0, 0, 0, 0, 0, 0, 0, 2, 0,
        5, 2, 2, 0, 0, 6, 3, 0, 8};
      Board board_row_error(& brd_row_error[0], & brd_row_error[81], 3, 3);
      TS_ASSERT( !board_row_error.isValid() );

      Board::CellType brd_column_error[] =
      { 0, 4, 3, 0, 0, 0, 2, 7, 0,
        2, 0, 0, 0, 0, 0, 0, 9, 0,
        0, 9, 0, 0, 0, 5, 0, 6, 0,
        0, 0, 2, 6, 9, 0, 0, 0, 0,
        0, 0, 8, 0, 5, 0, 0, 0, 0,
        0, 0, 1, 7, 4, 0, 0, 0, 9,
        0, 7, 0, 0, 0, 1, 0, 0, 4,
        0, 2, 0, 0, 0, 0, 0, 2, 0,
        5, 2, 0, 0, 0, 6, 3, 0, 8};
      Board board_column_error(& brd_column_error[0], & brd_column_error[81], 3, 3);
      TS_ASSERT( !board_column_error.isValid() );

      Board::CellType brd_group_error[] =
      { 0, 4, 3, 0, 0, 0, 2, 7, 0,
        2, 0, 0, 0, 0, 0, 0, 9, 0,
        0, 9, 0, 0, 0, 5, 0, 6, 0,
        0, 0, 2, 6, 9, 0, 0, 0, 0,
        0, 0, 8, 0, 5, 0, 0, 0, 0,
        0, 0, 1, 7, 4, 0, 0, 0, 9,
        0, 7, 0, 0, 0, 1, 0, 0, 4,
        2, 0, 0, 0, 0, 0, 0, 2, 0,
        5, 2, 0, 0, 0, 6, 3, 0, 8};
      Board board_group_error(& brd_group_error[0], & brd_group_error[81], 3, 3);
      TS_ASSERT( !board_group_error.isValid() );
    }

    void test_if_board_is_solved()
    {
      Board::CellType brd[] = {1, 2, 2, 1};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      TS_ASSERT(board.isSolved());
    }

    void test_solver_is_able_to_solve_1x1_board()
    {
      Board::CellType brd[] = { 0};
      Board board(&brd[0], &brd[1], 1, 1);
      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::SUCCESS, solver.solve());
      TS_ASSERT_EQUALS(board(0,0), 1);
    }

    void test_solver_is_able_to_solve_1x2_board()
    {
      Board::CellType brd[] = {0, 1, 1, 2};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::SUCCESS, solver.solve());
      TS_ASSERT_EQUALS(board(0,0), 2);
    }

    void test_solver_deals_with_not_filled_invalid_board()
    {
      Board::CellType brd[] = {1, 1, 0, 2};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::INVALID, solver.solve());
    }

    void test_solver_deals_with_filled_invalid_board()
    {
      Board::CellType brd[] = {1, 2, 1, 2};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::INVALID, solver.solve());
    }

    void test_solver_deals_with_filled_valid_board()
    {
      Board::CellType brd[] = {1, 2, 2, 1};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::SUCCESS, solver.solve());
      TS_ASSERT(board.isSolved());
    }

    void test_solver_deals_with_another_board()
    {
      Board::CellType brd[] = {0, 0, 0, 2};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::SUCCESS, solver.solve());
      TS_ASSERT_EQUALS(board(0,0), 2);
      TS_ASSERT_EQUALS(board(1,0), 1);
      TS_ASSERT_EQUALS(board(0,1), 1);
      TS_ASSERT_EQUALS(board(1,1), 2);
    }

    void test_solver_deals_with_unsolvable_board()
    {
      Board::CellType brd[] = {1, 0, 0, 2};
      Board board(&brd[0], &brd[sizeof(brd)/sizeof(brd[0])], 1, 2);

      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::INVALID, solver.solve());
    }

  void print(Board & b)
  {
    for (auto i = 0u; i < b.size(); ++i)
      {
	for (auto j = 0u; j < b.size(); ++j)
	  {
	    std::cout << " " << b(i,j);
	  }
	std::cout << std::endl;
      }
  }

    void test_solver_bigger_table_ok_case()
    {
      Board::CellType brd_ok[] =
      {
  0, 4, 3, 0, 0, 0, 2, 7, 0, 8, 0, 0, 0, 0, 0, 0, 0, 9, 2, 0, 9, 0, 0, 0, 5, 0, 6, 0, 0, 0, 2, 6, 9, 0, 0, 0, 0, 0, 0, 8, 0, 5, 0, 0, 0, 0, 0, 0, 1, 7, 4, 0, 0, 0, 9, 0, 7, 0, 0, 0, 1, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 2, 0, 5, 2, 0, 0, 0, 6, 3, 0 
      };
      Board board(&brd_ok[0], &brd_ok[81], 3, 3);
      sudoku::Solver solver(board);
      TS_ASSERT_EQUALS(sudoku::Solver::Result::SUCCESS, solver.solve());
      TS_ASSERT(board.isSolved());
      print(board);
    }
};

