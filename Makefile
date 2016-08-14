COMPILER=g++

COMPILER_ARGS=-std=c++11

make:
	${COMPILER} -o DBZ.exe src/test.cpp src/TypeList.h ${COMPILER_ARGS}
