#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"
 

TEST_CASE("creating matrix")
{
    matrix_t matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input
    {
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}

TEST_CASE("copying matrix")
{
    std::string input
    {
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    matrix_t matrix;
    std::istringstream istream{ input };
    REQUIRE( matrix.read(istream));
    
    matrix_t copy(matrix);
    REQUIRE( copy.rows() == 3);
    REQUIRE( copy.collumns() == 3);
}
    
TEST_CASE("operator+")
{
    std::string input
    {
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    std::string input2
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input3
    {
        "3, 3\n"
        "2 2 2\n"
        "3 3 3\n"
        "4 4 4" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    REQUIRE(matrix1.rows() == 3);
    REQUIRE(matrix1.collumns() == 3);
        
    REQUIRE(matrix2.rows() == 3);
    REQUIRE(matrix2.collumns() == 3);
    
    std::ostringstream stream;
    (matrix1+matrix2).write(stream);
    
    REQUIRE( input3 == stream.str());
}

TEST_CASE("operator-")
{
    std::string input
    {
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input2
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input3
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    REQUIRE(matrix1.rows() == 3);
    REQUIRE(matrix1.collumns() == 3);
        
    REQUIRE(matrix2.rows() == 3);
    REQUIRE(matrix2.collumns() == 3);
    
    std::ostringstream stream;
    (matrix1-matrix2).write(stream);
    
    REQUIRE( input3 == stream.str());
}
TEST_CASE ("operator*")
{
    std::string input
    {
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input2
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input3
    {
        "3, 3\n"
        "6 6 6\n"
        "6 6 6\n"
        "6 6 6" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    std::ostringstream stream;
    (matrix1 * matri2).write( stream );
    
    REQUIRE( input3 == stream.str() );
}

TEST_CASE ("operator=")
{
    std::string input
    {
         "3, 3\n"
         "1 1 1\n"
         "1 1 1\n"
        	"1 1 1" };
 	std::string input2
{
          "3, 3\n"
          "2 2 2\n"
          "2 2 2\n"
         	"2 2 2" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    matrix1 = matrix2;
    std::ostringstream stream;
    matrix1.write( stream );
    
    REQUIRE( input2 == stream.str() );
}   

TEST_CASE ("operator=*")
{
    std::string input
    {
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    std::string input2
    {
        "3, 3\n"
        "3 3 3\n"
        "4 4 4\n"
        "5 5 5" };
    std::string input3
    {
        "3, 3\n"
        "12 12 12\n"
        "24 24 24\n"
        "36 36 36" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    matrix1 *= matrix2;
    std::ostringstream stream;
    matrix1.write( stream );
    
    REQUIRE (input3 == stream.str());
}

TEST_CASE ("operator=+")
{
  std::string input{
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input2
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input3
    {
         "3, 3\n"
        "3 3 3\n"
        "3 3 3\n"
        "3 3 3" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    matrix1 += matrix2;
    std::ostringstream stream;
    matrix1.write( stream );
    
    REQUIRE (input3 == stream.str());
}

TEST_CASE ("operator-=")
{
    std::string input
      
        {
        "3, 3\n"
        "2 2 2\n"
        "2 2 2\n"
        "2 2 2" };
    std::string input2
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    std::string input3
    {
        "3, 3\n"
        "1 1 1\n"
        "1 1 1\n"
        "1 1 1" };
    matrix_t matrix1, matrix2;
    std::istringstream istream1{ input };
    std::istringstream istream2{ input2 };
    REQUIRE(matrix1.read(istream1));
    REQUIRE(matrix2.read(istream2));
    
    matrix1 -= matrix2;
    std::ostringstream stream;
    matrix1.write( stream );
    
    REQUIRE (input3 == stream.str());
}
