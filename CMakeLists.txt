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

add_executable(test testall/test_all.cpp)
add_executable(t1 图/最短路径算法.cpp)
add_executable(t2 图/拓扑排序.cpp 图/拓扑排序.h)
add_executable(find 查找/查找算法.cpp)
add_executable(hashtable 查找/哈希表.cpp)
add_executable(unionFind 查找/并查集.cpp)

add_executable(sortAl 排序/排序算法.cpp 排序/排序算法.h)

add_executable(banker testall/banker.cpp testall/banker.h)

add_executable(graph_bfs 图/STL_version/graph_bfs.cpp)
add_executable(graph_bfs_djstra 图/STL_version/graph_bfs_djstra.cpp)
add_executable(graph_djstra 图/STL_version/graph_djstra.cpp)

add_executable(p17 线性表/题解练习/p17.cpp 线性表/题解练习/p17.h)
