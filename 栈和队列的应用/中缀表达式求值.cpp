#include <bits/stdc++.h>
using namespace std;

//https://www.bilibili.com/video/BV1b7411N798?p=28
//以下是实现的答大体思路
/*初始化一个栈，用于保存暂时还不能确定运算顺序的运算符。
从左到右处理各个元素，直到末尾。可能遇到三种情况：
① 遇到操作数。直接加入后缀表达式。
② 遇到界限符。遇到“(”直接入栈；遇到“)”则依次弹出栈内运算符并加入后缀表达式，直到
弹出“(”为止。注意：“(”不加入后缀表达式。
③ 遇到运算符。依次弹出栈中优先级高于或等于当前运算符的所有运算符，并加入后缀表达式，
若碰到“(” 或栈空则停止。之后再把当前运算符入栈。
按上述方法处理完所有字符后，将栈中剩余运算符依次弹出，并加入后缀
 *
 * */

//比较两个符号的优先级，大于或者等于返回true
bool comp(char op1, char op2) {
    if (op1 == '+' || op1 == '-') {
        if (op2 == '-' || op2 == '+') return true;
        if (op2 == '*' || op2 == '/') return false;
    } else if (op1 == '*' || op1 == '/') {
        if (op2 == '-' || op2 == '+') return false;
        if (op2 == '*' || op2 == '/') return true;
    }
    return false;
}

//传入中缀表达式
int getValue(string str) {
    //初始化2个栈
    vector<char> opStack;   //存放操作符
    vector<char> numStack;  //存放操作数
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            numStack.push_back(str[i]);
        } else if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            opStack.push_back(str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            //依次出栈运算符,直到遇到栈内第一个左括号就停止

            while (opStack.back() != '(' || opStack.back() != '[' ||
                   opStack.back() != '{') {
                char temp = opStack.back();
                opStack.pop_back();
                int right = numStack.back() - '0';
                numStack.pop_back();
                int left = numStack.back() - '0';
                numStack.pop_back();
                if (temp == '+') numStack.push_back(left + right + '0');
                if (temp == '-') numStack.push_back(left - right + '0');
                if (temp == '*') numStack.push_back(left * right + '0');
                if (temp == '/') numStack.push_back(left / right + '0');
            }
        } else {  //遇到运算符
            if (opStack.back() == '(' || opStack.back() == '[' ||
                opStack.back() == '}') {
                opStack.push_back(str[i]);
            } else {
                if (opStack.empty() || opStack.back() == '(' ||
                    opStack.back() == '[' || opStack.back() == '{') {
                    opStack.push_back(str[i]);
                } else {  //比较当前符号栈的优先级
                    while (comp(opStack.back(), str[i])) {
                        char temp = opStack.back();
                        opStack.pop_back();
                        int right = numStack.back() - '0';
                        numStack.pop_back();
                        int left = numStack.back() - '0';
                        numStack.pop_back();
                        if (temp == '+') numStack.push_back(left + right + '0');
                        if (temp == '-') numStack.push_back(left - right + '0');
                        if (temp == '*') numStack.push_back(left * right + '0');
                        if (temp == '/') numStack.push_back(left / right + '0');
                    }
                }
            }
        }
    }
    return numStack.back();
}

int main() {
    string test = "2+3*4";
    cout << getValue(test) << endl;
    return 0;
}