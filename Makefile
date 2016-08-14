COMPILER=g++

COMPILER_ARGS=-std=c++11

make:
	${COMPILER} -o DBZ.exe src/*.cpp src/*.h ${COMPILER_ARGS}
