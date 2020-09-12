Building Pipelines
==================

Prerequisites
-------------

CMake
.....

Pipelines uses `CMake <https://cmake.org/>`_ to generate a build system. See
`line 1 in
CMakeLists.txt <https://github.com/brobeson/pipelines/blob/fa9423a1e1db777732853b761a320549acaf8fa3/CMakeLists.txt#L1>`_
for the minimum required version. Install it however you like.

C++ Compiler
............

Pipelines requires some features from C++17. Right now, I only build and test
with GCC 9, but I'll expand to other compilers in the future.

Catch2
......

`Catch2 <https://github.com/catchorg/Catch2>`_ is required to build the tests.
If you don't want to build the tests, set the CMake variable ``BUILD_TESTING``
to ``off`` on your CMake command line:

.. code-block:: bash

    cmake -D BUILD_TESTING:BOOL=off path/to/pipelines

Otherwise, `build and install
Catch2 <https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#getting-catch2>`_.
I was able to build a Debian package and install that with apt. Note that
these instructions are for Catch2, not pipelines. Run these commands relative
the Catch2 repository and build directory.

.. code-block:: bash

    cmake -D CMAKE_BUILD_TYPE=Release path/to/catch2
    cmake --build .
    cpack -G DEB
    sudo apt install ./Catch2-2.13.1-Linux.deb

Cppcheck
........

`Cppcheck <https://github.com/danmar/cppcheck>`_ is required as a part of the
build process. Install it using the appropriate mechanism for your platform.

Doxgyen
.......

`Doxygen <https://www.doxygen.nl/index.html>`_ is used to build the
documentation. At this time, Doxygen is required; there is no way to disable
building the documentation. Install it using the appropriate mechanism for
your platform.

Sphinx
......

`Sphinx <https://www.sphinx-doc.org/en/master/index.html>`_ is also used to
build the documentation. Install it from PyPI:

.. code-block:: bash

    sudo pip3 install Sphinx

Breathe
.......

`Breathe <https://breathe.readthedocs.io/en/latest/>`_ is an extension for
Sphinx; it's the final piece needed to build the pipelines documentation.
Install this from PyPI, too:

.. code-block:: bash

    sudo pip3 install breathe

Building
--------

Building the software is pretty straight forward: run CMake a couple times:

.. code-block:: bash

    cmake path/to/pipelines
    cmake --build .

Run unit tests with CTest:

.. code-block:: bash

    ctest
