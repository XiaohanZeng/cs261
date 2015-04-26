#AUthor Xiaohan Zeng
#Date:04/05/2015
#Filename:makefile


CXX = gcc
#CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#LDFLAGS = -lboost_date_time
EXECUTABLE = assignment0

OBJS = 
SRCS =  


all: clean ${EXECUTABLE}

${EXECUTABLE}: ${OBJS} ${EXECUTABLE}.c
	${CXX} ${CXXFLAGS} ${OBJS} ${EXECUTABLE}.c  -o ${EXECUTABLE}


${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm -rf *.o ${EXECUTABLE}

