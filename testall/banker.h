/*
 * 银行家算法
 * Created by JMChen on 2021/8/11.
**/

# include <bits/stdc++.h>

using namespace std;


/*
长度为 m 的一维数组 Available 表示还有多少可用资源
n*m 矩阵 Max 表示各进程对资源的最大需求数
n*m 矩阵 Allocation 表示已经给各进程分配了多少资源
Max – Allocation = Need 矩阵表示各进程最多还需要多少资源
*/
// 安全性检查
bool isSafety(vector<vector<int>> maxSource, vector<vector<int>> allocation, vector<int> available) {
    vector<vector<int>> need(maxSource.size(), vector<int>(maxSource[0].size()));
    vector<int> safeList;//安全序列加入安全进程的编号
    vector<bool> isJudge(maxSource.size(), false);//判断是否已经加入

    //得到各个进程还需要多少资源
    for (int i = 0; i < maxSource.size(); i++)
        for (int j = 0; j < maxSource[0].size(); ++j)
            need[i][j] = maxSource[i][j] - allocation[i][j];

    int cnt = need.size();
//    int cnt = int(pow(need.size(), 3));
    //判断剩下的资源够不够进程用，够的话就加到安全序列
    while (cnt--) {
        for (int i = 0; i < need.size(); ++i) {
            if (isJudge[i]) continue;//已经加入安全序列的就不用检查了

            bool flag = false;
            for (int j = 0; j < need[0].size(); ++j) {
                if (available[j] < need[i][j]) {//此时还不满足
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                safeList.emplace_back(i);
                isJudge[i] = true;
                //修改剩余可用资源,把已经分配的加回去
                for (int k = 0; k < available.size(); k++)
                    available[k] += allocation[i][k];
            }
        }
        //所有线程编号都加入安全序列，则是个安全的状态
        if (safeList.size() == need.size()) {
            cout << "安全序列是：";
            for (int i : safeList)
                cout << "P" << i << "  ";
            cout << endl << endl;
            return true;
        }
    }
    return false;
}

void showMsg(vector<vector<int>> maxSource, vector<vector<int>> allocation,
             vector<vector<int>> need, vector<int> &available) {
    cout << "可用资源向量：";
    for (int i : available)
        cout << i << " ";

    cout << endl << "资源分配情况：" << endl;
    cout << "进程Pi\t Max\t Allocation\t \tNeed\t" << endl;
    for (int i = 0; i < maxSource.size(); ++i) {
        cout << "P" << i << "\t\t ";
        for (int j = 0; j < maxSource[0].size(); ++j)
            cout << maxSource[i][j] << " ";
        cout << "\t\t ";
        for (int j = 0; j < maxSource[0].size(); ++j)
            cout << allocation[i][j] << " ";
        cout << "\t \t";
        for (int j = 0; j < maxSource[0].size(); ++j)
            cout << need[i][j] << " ";
        cout << "\t ";
        cout << endl;
    }
}

//加入进程Pi发送的请求request[i]的银行家算法
//即 request 是进程Pi的请求向量
bool bankerAl(vector<int> request_i, int pi, vector<vector<int>> &maxSource, vector<vector<int>> &allocation,
              vector<int> &available) {

    //开始的时候，先进行一次安全性检查
    if (!isSafety(maxSource, allocation, available))
        return false;

    //开始进行银行家算法
    vector<vector<int>> need(maxSource.size(), vector<int>(maxSource[0].size()));
    vector<int> safeList;//安全序列加入安全进程的编号

    //得到各个进程还需要多少资源
    for (int i = 0; i < maxSource.size(); i++)
        for (int j = 0; j < maxSource[0].size(); ++j)
            need[i][j] = maxSource[i][j] - allocation[i][j];

    showMsg(maxSource, allocation, need, available);


    //1. 如果 Request_i[j] ≤ Need[i,j]便转向步骤 2；否则认为出错，因为它所需要的资源数已超过它所宣布的最大值。
    for (int j = 0; j < need[0].size(); ++j)
        if (request_i[j] > need[pi][j]) return false;


    //2.如果 Request_i[j] ≤ Available[j]，便转向步骤 3；否则，表示尚无足够资源，Pi须等待
    for (int i = 0; i < request_i.size(); ++i)
        if (request_i[i] > available[i]) {
            cout << "P" << pi << "需要等待资源" << endl;
            return false;
        }

    //3.系统试探着把资源分配给进程 Pi，并修改下面数据结构中的数值
    /*
     * Available[j] = Available[j] - Requesti[j]; // 分配出去
        Allocation[i,j] = Allocation[i,j] + Requesti[j]; // 获得资源
        Need[i,j] = Need[i,j] - Requesti[j];　　　　// 需求减少
     * */
    for (int i = 0; i < available.size(); ++i) {
        available[i] -= request_i[i];
        allocation[pi][i] += request_i[i];
        need[pi][i] -= request_i[i];
    }

    showMsg(maxSource, allocation, need, available);

    //再次执行安全性检查算法看看当前情况是否可以得到一个安全序列
    if (isSafety(maxSource, allocation, available)) {
        cout << "进程P" << pi << "可以申请资源" << endl;
        return true;
    }
    cout << "进程P" << pi << "无法申请资源" << endl;
    return false;

}

void testIsSafety() {
    vector<vector<int>> maxSource = {
            {7, 5, 3},
            {3, 2, 2},
            {9, 0, 2},
            {2, 2, 2},
            {4, 3, 3}
    };
    vector<vector<int>> allocation = {
            {0, 1, 0},
            {2, 0, 0},
            {3, 0, 2},
            {2, 1, 1},
            {0, 0, 2}
    };
    vector<int> available = {3, 3, 2};
    vector<int> allHas = {10, 5, 7};
    if (isSafety(maxSource, allocation, available))
        cout << "is safe" << endl;
    else cout << "not safe" << endl;
}

void testBankerAl() {
    //p0, (211)
    vector<vector<int>> maxSource = {
            {7, 5, 3},
            {3, 2, 2},
            {9, 0, 2},
            {2, 2, 22},
            {4, 3, 3}
    };
    vector<vector<int>> allocation = {
            {0, 1, 0},
            {2, 0, 0},
            {3, 0, 2},
            {2, 1, 1},
            {0, 0, 2}
    };
    vector<int> available = {3, 3, 2};
    vector<int> allHas = {10, 5, 7};
//    vector<int> request_i = {2, 1, 1};
    vector<int> request_i = {1, 0, 2};
//    int pi = 0;
    int pi = 1;
    cout << endl << "申请资源的进程: P" << pi << endl;
    cout << "申请各类资源数量：";
    for (int i : request_i)
        cout << i << " ";
    cout << endl;
    if (bankerAl(request_i, pi, maxSource, allocation, available))
        cout << "存在安全序列" << endl;
    else cout << "不存在安全序列" << endl;

}

#ifndef DATA_STRUCTURE_REVIEW_BANKER_H
#define DATA_STRUCTURE_REVIEW_BANKER_H

#endif //DATA_STRUCTURE_REVIEW_BANKER_H
