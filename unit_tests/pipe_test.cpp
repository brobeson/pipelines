#define CATCH_CONFIG_MAIN
#include "pipelines/pipe.h"
#include "catch.hpp"

SCENARIO("A pipe can be constructed.")
{
  WHEN("A pipe is constructed")
  {
    pipelines::pipe<int> pipe;
    THEN("it is empty") { CHECK(pipe.empty()); }
    AND_THEN("it's size is 0") { CHECK(pipe.size() == 0); }
  }
}

SCENARIO("Data can be written to a pipe.")
{
  GIVEN("An empty pipe")
  {
    pipelines::pipe<int> pipe;
    WHEN("data is read")
    {
      THEN("an empty_channel exception is thrown.")
      {
        CHECK_THROWS_AS(pipe.read(), pipelines::empty_pipe);
      }
    }
    WHEN("a datum is written")
    {
      pipe.write(10);
      THEN("the pipe's size is one") { CHECK(pipe.size() == 1); }
    }
    WHEN("Two data are written")
    {
      pipe.write(10);
      pipe.write(20);
      THEN("The pipe's size is two") { CHECK(pipe.size() == 2); }
    }
  }
}

SCENARIO("Data can be read from a pipe.")
{
  GIVEN("A pipe with two data")
  {
    pipelines::pipe<int> pipe;
    pipe.write(10);
    pipe.write(20);
    WHEN("One datum is read")
    {
      const auto d {pipe.read()};
      THEN("The read datum is the first written") { CHECK(d == 10); }
      AND_THEN("The pipe's size is one") { CHECK(pipe.size() == 1); }
    }
    WHEN("Two data are read")
    {
      const auto d {pipe.read()};
      const auto e {pipe.read()};
      THEN("The first read datum is the first written") { CHECK(d == 10); }
      AND_THEN("The second read datum is the second written")
      {
        CHECK(e == 20);
      }
      AND_THEN("The pipe is empty") { CHECK(pipe.empty()); }
      AND_THEN("The pipe's size is zero") { CHECK(pipe.size() == 0); }
    }
  }
}