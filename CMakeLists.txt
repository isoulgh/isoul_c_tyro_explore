cmake_minimum_required(VERSION 3.19)
project(c_tyro_explore)

set(CMAKE_CXX_STANDARD 14)

add_executable(6_graph-Graph 6_graph/Graph.cpp)

add_executable(gadget-Fibonacci gadget/Fibonacci.cpp)
add_executable(gadget-SolutionOfHomogeneous gadget/SolutionOfHomogeneous.cpp)

add_executable(list-LinkList list/LinkList.cpp)
add_executable(list-LinkListInsert list/LinkListInsert.cpp)
add_executable(list-SequenceList list/SequenceList.cpp)

add_executable(mess-Demo mess/demo.cpp)
add_executable(mess-Demo2 mess/demo2.cpp)
add_executable(mess-Demo3 mess/demo3.cpp)
add_executable(mess-Main mess/main.cpp)
add_executable(mess-Main2 mess/main2.cpp)
add_executable(mess-Test mess/test.cpp)
add_executable(mess-Test2 mess/test2.cpp)

add_executable(pointer-T01 Pointer/T01.cpp)
add_executable(pointer-T02 Pointer/T02.cpp)

add_executable(string-KMP string/KMP.cpp)
add_executable(string-strAssign string/strAssign.cpp)
add_executable(string-strCompare string/strCompare.cpp)
add_executable(string-StringDemo string/StringDemo.cpp)

add_executable(thread-ThreadDemo thread/ThreadDemo.cpp)
add_executable(thread-ThreadPeter Thread/ThreadPeter.cpp)

add_executable(tree-AVL tree/AVL.cpp)
add_executable(tree-BinarySortTree tree/BinarySortTree.cpp)
add_executable(tree-PostOrder tree/PostOrder.cpp)
