#Author:	Taylor Jones (jonest3)
#Date:		March 15, 2016
#Description:	makefile Final Project

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = Compartment.o Future.o main.o ParallelUniverse.o Past.o PocketUniverse.o Space.o Creature.o VashtaNerada.o Cybermen.o Krafayis.o TheMaster.o WeepingAngels.o Player.o
SRCS = Compartment.cpp Future.cpp main.cpp ParallelUniverse.cpp Past.cpp PocketUniverse.cpp Space.cpp Creature.cpp VashtaNerada.cpp Cybermen.cpp Krafayis.cpp TheMaster.cpp WeepingAngels.cpp Player.cpp
HEADERS = Compartment.hpp Future.hpp ParallelUniverse.hpp Past.hpp PocketUniverse.hpp Space.hpp Creature.hpp VashtaNerada.hpp Cybermen.hpp Krafayis.hpp TheMaster.hpp WeepingAngels.hpp Player.hpp

fp: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o fp

clean:
	rm -f ${OBJS} *.o *a.out
