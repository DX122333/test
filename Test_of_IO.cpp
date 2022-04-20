#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
//exercise8.1
istream& test801(istream& is) {
	std::string s;
	while (is >> s) {
		cout << s << endl;
	}
	is.clear();
	return is;
}

//ecercise8.3
void test803() {
	string i;
	while (cin >> i) {
		cout << "ok";
		return;
	}
	cout << "fail";//failbit、badbit、eofbit被置位
	return;
}
void check813() {
	cout << "hi!" << endl;//endl完成一个换行，并刷新缓冲区
	cout << "hi!" << flush;//flush刷新缓冲区
	cout << "hi!" << ends;//ends输出一个空字符，并刷新缓冲区
	return;
}
//exercise8.4&8.5
void test804(const string& fname) {
	ifstream ifs(fname);
	vector<string> v1;
	string buf1;
	if (ifs) {
		while (getline(ifs, buf1)) {
			v1.push_back(buf1);
		}
	}
	//文件指针从文件尾定位到文件头
	ifs.clear();
	ifs.seekg(std::ios::beg);
	vector<char> v2;
	char buf;
	if (ifs) {
		while (ifs >> buf) {
			v2.push_back(buf);
		}
	}
	for (const char& s : v2) cout << s << endl;
	//当一个fstream对象离开作用域时，与之关联的文件会自动关闭
	return;
}
void test810(const string& fname) {
	vector<string> v1;
	ifstream is(fname);
	string buf;
	if (!is) {
		cerr << "open error" << endl;
		return;
	}
	while (getline(is, buf)) {
		v1.push_back(buf);
	}
	for (const string& s : v1) {
		istringstream iss(s);
		while (iss >> buf)
			cout << buf << endl;
	}
}
int main() {
	//string s;
	//cout << "Ready to test?" << endl;
	//while (cin >> s) {//>>表达式会返回流的状态
	//	cout << "ok";
	//}
	//test801(cin);
	//test803();
	//check813();
	/*string s = "data.txt";
	test804(s);*/
	/*string s = "data.txt";
	test810(s);*/
	return 0;
}