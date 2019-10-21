#include<iostream>
#include<unordered_map>
using namespace std;


class node {

public:
	char data;
	unordered_map<char, node*> h;
	bool isTerminating;

	node(char d) {
		data = d;
		isTerminating = false;

	}

};
class trie
{	node* root;
public:

	trie() {
		root = new node('\0');
	}

	void insertWord(string str) {
		node* temp = root;

		for (int i = 0; i < str.length(); ++i)
		{
			char ch = str[i];
			if (temp->h.count(ch) == 0) {
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = child;
			} else {
				temp = temp->h[ch];
			}
		}
		temp -> isTerminating = true;
	}

	bool search(string str) {
		node* temp = root;
		for (int i = 0; i < str.length(); ++i)
		{
			char ch = str[i];
			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			}
			else {
				return false;
			}
		}
		return temp->isTerminating;
	}

};

int main(int argc, char const *argv[])
{
	trie t;
	t.insertWord("mango");
	t.insertWord("apple");
	t.insertWord("man");
	t.insertWord("appe");

	cout << t.search("mango") << endl;
	cout << t.search("apple") << endl;

	cout << t.search("manipal") << endl;

	cout << t.search("appe") << endl;

	return 0;
}
