#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Node {
	bool leaf;
	unordered_map<char, unique_ptr<Node>> next;
};

unique_ptr<Node> build_prefix_tree(vector<string> terms) {
	unique_ptr<Node> root(new Node());
	root->leaf = false;

	for (auto term : terms) {
		Node* current = root.get();
		for (int i = 0; i < term.size(); ++i) {
			auto iter = current->next.find(term[i]);
			if (iter == current->next.end()) {
				unique_ptr<Node> next(new Node());
				next->leaf = false;
				current->next[term[i]] = std::move(next);
			}

			current = current->next[term[i]].get();
		}
		current->leaf = true;
	}

    return root;
}

void traverse(const Node* current, string prefix, vector<string>& results) {
	if (current->next.empty()) {
		results.push_back(prefix);
		return;
	}

	if (current->leaf) {
		results.push_back(prefix);
	}

	for (auto iter = current->next.begin() ; iter != current->next.end(); ++iter) {
		traverse(iter->second.get(), prefix + iter->first, results);
	}
}

vector<string> guess(const string& prefix, unique_ptr<Node>& root) {
	vector<string> results;

	Node* current = root.get();
	for (int i = 0; i < prefix.size(); ++i) {
		auto iter = current->next.find(prefix[i]);
		if (iter == current->next.end()) {
			// no term in database has same prefix
			return results;
		}

		current = current->next[prefix[i]].get();
	}

	traverse(current, prefix, results);
	return results;
}

int main() {
	vector<string> terms {
		"abc", "abcd", "acd",
			"baa", "ca",
	};

	unique_ptr<Node> root = build_prefix_tree(terms);

	vector<string> tests = {
		"ab",
		"bc",
		"ca"
	};

	for (auto test : tests) {
		vector<string> output = guess(test, root);

		for (auto s : output) {
			cout << s << " ";
		}
		cout << endl;
	}

	return 0;
}
