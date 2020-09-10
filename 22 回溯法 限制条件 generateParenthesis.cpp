class Solution {
public:
	string cur_str = "(";   // 深度优先遍历一课树， 每到达一次叶子结点，都输出一次合法的cur_str字符串 
	vector<string> res;     // 存储所有合法的结果
	vector<string> strMap;  // 从17题电话号码的组合思路启发， 定义每一个vector的对象为"()",每次选择一个
	map<char, char> Match;  // 定义左右括号匹配的另一半是谁  '(' -> ')'   ')'->'('
	void initMatch(int n) { // 初始化变量
		string temp = "()";
		Match['('] = ')'; Match[')'] = '(';
		for (int i = 0; i < 2*n; i++) {  // 对应假定的2n个相同的字符串“()” 
			strMap.push_back(temp);
		}
	}
	void DFS(int index, int left, int right, int n){
		if(right == n && left == n){ // 如果左括号数量和右括号数量都等于n，则到达了结束条件
			res.push_back(cur_str);
			return;
		}
        // 除了终止条件之外 为了满足合法的括号组合，还必须满足两个条件。 然后两两组合变成了以下四个 if-else
        // 1. left >= right （指代数量）
        // 2. left <= n
		if (right == left && left < n) {  // 该情况下只能 插入左括号
			cur_str.push_back('(');
			DFS(index + 1, left + 1, right, n);
			cur_str.pop_back();
		}else if (right < left && left < n) { // 这种情况下，左括号和右括号可以随意插入一种
			for (int i = 0; i < strMap[index].size(); i++) {//遍历 ‘（’ 和 ')'
				cur_str.push_back(strMap[index][i]);
				if(i == 0) DFS(index + 1, left + 1, right, n);  // i=0  插入左括号
				else DFS(index + 1, left, right + 1, n);        // i=1  插入右括号
				cur_str.pop_back();
			}
		}else if (right < left && left == n) { // 此类情况，整个组合字符串的空位都只能用 ')'来填充
			cur_str.push_back(')');
			DFS(index + 1, left, right + 1, n);
			cur_str.pop_back();
		}else if(right == left && left == n) {
			printf("\n 执行到这来，就凉了");
		}
	}

	vector<string> generateParenthesis(int n){
		if (n == 0) return res;
		initMatch(n);
		DFS(0, 1, 0, n); //第一个字符为左括号
		return res;
	}
};