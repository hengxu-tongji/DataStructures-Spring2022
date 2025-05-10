#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Picture {
public:
	struct Node {
		int id, earliest, latest;
		std::vector<std::pair<Node*, int>> next;
		std::vector<std::pair<Node*, int>> last;
		Node(const int id_) : id(id_) { earliest = INT_MIN; latest = INT_MAX; }
		~Node() = default;
	};

	bool IsNotEnd(const int n) {
		return n >= 0 && n < nodes.size() &&
			nodes[n].next.empty(); 
	}

	void AddErrorLine(int e) {
		int step = rand() % 10 + 1;
		int i = e;
		while (step-- && nodes[i].next.size() > 0)
			i = nodes[i].next[rand() % nodes[i].next.size()].first->id;
		AddLine(i, e, rand() % 100 + 1);
	}

	void AddLine(int s, int e, int w) {
		nodes[s].next.push_back(std::make_pair(&nodes[e], w));
		nodes[e].last.push_back(std::make_pair(&nodes[s], w));
	}

	int FindKeyPath() {
		std::stack<Node*> S;
		for (auto& node : nodes) {
			if (node.last.empty()) {
				S.push(&node);
			}
		}
		int max_earliest = INT_MIN;
		while (!S.empty()) {
			Node& n = *S.top();
			S.pop();
			max_earliest = std::max(max_earliest, n.earliest);
			for (auto& next : n.next) {
				if (next.first->earliest < n.earliest + next.second) {
					next.first->earliest = n.earliest + next.second;
					S.push(next.first);
				}
			}
		}
		for (auto& node : nodes) {
			if (node.next.empty()) {
				node.latest = max_earliest;
				S.push(&node);
			}
		}
		while (!S.empty()) {
			Node& n = *S.top();
			S.pop();
			for (auto& last : n.last) {
				if (last.first->latest > n.latest - last.second) {
					last.first->latest = n.latest - last.second;
					S.push(last.first);
				}
			}
		}
		return max_earliest - INT_MIN;
	}

	void PrintKeyPath() {
		for (auto& node : nodes) {
			for (auto& next : node.next) {
				if (next.first->earliest == next.first->latest && next.first->earliest
					== node.earliest + next.second)
					cout << node.id + 1 << "->" << next.first->id + 1 << endl;
			}
		}
	}

	void FixOrder() {
		bool (*comp)(std::pair<Node*, int>p1, std::pair<Node*, int>p2) =
			[](std::pair<Node*, int>p1, std::pair<Node*, int>p2) { return p1.first->id
			< p2.first->id; };
		for (auto& node : nodes) {
			std::sort(node.next.begin(), node.next.end(), comp);
			// std::sort(node.last.begin(), node.last.end(), comp);
			// std::reverse(node.next.begin(), node.next.end());
		}
	}

	void PrintLines() {
		for (auto node : nodes) {
			for (auto& next : node.next) {
				cout << node.id + 1 << ' ' << next.first->id + 1 << ' ' << next.second
					<< endl;
			}
		}
	}

	void Build(const int n) { for (int i = 0; i < n; i++) nodes.push_back(Node(i)); }

	void Clear() { nodes.clear(); }
	Picture() = default;
	Picture(const int n) { Build(n); }
	~Picture() = default;
private:
	std::vector<Node> nodes;
};
int main()
{
	Picture AA;
	int n, m;
	cin >> n >> m;
	AA.Build(n);
	AA.FindKeyPath();
	AA.PrintKeyPath();

}