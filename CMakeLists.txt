cmake_minimum_required(VERSION 3.19)
project(data_structure_review)

set(CMAKE_CXX_STANDARD 11)

include_directories(testall)
include_directories(串)
include_directories(图)
include_directories(栈/动态栈)
include_directories(栈/静态栈)
include_directories(栈和队列的应用)
include_directories(树)
include_directories(特殊矩阵的压缩存储)
include_directories(线性表/动态或链式)
include_directories(线性表/静态或顺式)
include_directories(线性表/题解练习)
include_directories(队列/动态队列)
include_directories(队列/静态队列)

add_executable(data_structure_review
        testall/test_all.cpp
        串/kmpSTL版本.cpp
        串/KMP匹配.cpp
        串/串的基本操作.cpp
        串/朴素匹配.cpp
        串/朴素匹配stl版本.cpp
        图/广度优先搜索BFS.cpp
        图/最短路径算法.cpp
        图/深度优先搜索DFS.cpp
        图/邻接矩阵基本操作.cpp
        栈/动态栈/linkStack.cpp
        栈/动态栈/linkStack.h
        栈/静态栈/staticStack.cpp
        栈/静态栈/staticStack.h
        栈和队列的应用/中缀表达式求值.cpp
        栈和队列的应用/后缀表达式求值stl版本.cpp
        栈和队列的应用/括号匹配.cpp
        栈和队列的应用/括号匹配版本2.cpp
        树/practiceP196.cpp
        树/二叉排序树BST.cpp
        树/二叉树的线索化.cpp
        树/二叉树的线索化.h
        树/二叉树的遍历应用.cpp
        树/求平衡二叉树最少结点数.cpp
        特殊矩阵的压缩存储/三角矩阵.cpp
        特殊矩阵的压缩存储/对称矩阵.cpp
        线性表/动态或链式/linklist.cpp
        线性表/动态或链式/linklist.h
        线性表/静态或顺式/staticList.cpp
        线性表/静态或顺式/staticList.h
        线性表/题解练习/p37.cpp
        线性表/题解练习/p37.h
        队列/动态队列/linkQueue.h
        队列/动态队列/p80.cpp
        队列/动态队列/无头结点链式队列.h
        队列/静态队列/staticQueue.cpp
        队列/静态队列/staticQueue.h)
add_executable(t1 图/最短路径算法.cpp)