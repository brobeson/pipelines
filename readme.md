# pipelines

This is an experimental library for parallel pipeline processing in C++.

The idea is an easy-to-use system of sequential stages. Each stage operates
independently, then passes its output as input to the next stage. Thus, the
stages can work in parallel.
