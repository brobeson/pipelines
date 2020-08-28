#include "pipelines.h"
#include <iostream>
#include <string>

namespace pipelines_test
{
  std::string append(const char input) { return std::string {input, 2}; }
  void print(const std::string& output) { std::cout << output << '\n'; }
}  // namespace pipelines_test

int main()
{
  pipelines::channel<char> input;
  pipelines::channel<std::string> output;
  pipelines::pipe append_step(input, output, &pipelines_test::append);
  pipelines::sink print_step(output, &pipelines_test::print);

  for (char c {'a'}; c <= 'z'; ++c)
  {
    input.push(c);
  }
  return EXIT_SUCCESS;
}