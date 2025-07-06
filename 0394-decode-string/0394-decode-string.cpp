class Solution{
    public:

string decodeString(string s) {
    stack<int> countStack;
    stack<string> strStack;
    string currStr = "";
    int num = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // handle multi-digit numbers
        } else if (ch == '[') {
            countStack.push(num);
            strStack.push(currStr);
            num = 0;
            currStr = "";
        } else if (ch == ']') {
            int repeat = countStack.top(); countStack.pop();
            string temp = strStack.top(); strStack.pop();
            while (repeat--) temp += currStr;
            currStr = temp;
        } else {
            currStr += ch;
        }
    }
    return currStr;
}
};