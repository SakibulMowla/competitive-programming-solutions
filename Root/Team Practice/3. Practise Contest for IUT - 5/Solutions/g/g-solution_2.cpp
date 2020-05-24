// CERC 2012
// Problem G: Jewel heist
// Alternative solution using complex interval tree, O(n log n)
// Author: Bartosz Walczak


#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
using namespace std;

struct point {
	int x, y, color;
};

inline bool compare_x(const point &p, const point &q) { return p.x < q.x; }
inline bool compare_y(const point &p, const point &q) { return p.y < q.y; }

template<typename Iterator>
inline Iterator prev(Iterator p) { return --p; }
template<typename Iterator>
inline Iterator next(Iterator p) { return ++p; }

struct node {
	int x, used, size;
	
	node() {}
	node(int x) : x(x), used(0), size(0) {}
};

inline node make_node(const point &p) { return node(p.x); }

int count(vector<node>::iterator p, vector<node>::iterator q, int x1, int x2) {
	if (p >= q) return 0;
	vector<node>::iterator m = p + (q-p)/2;
	if (x1 == numeric_limits<int>::min() && x2 == numeric_limits<int>::max()) return m->size;
	int cnt = 0;
	if (x1 < m->x) cnt += count(p, m, x1, x2 < m->x ? x2 : numeric_limits<int>::max());
	if (x1 <= m->x && x2 >= m->x) cnt += m->used;
	if (x2 > m->x) cnt += count(next(m), q, x1 > m->x ? x1 : numeric_limits<int>::min(), x2);
	return cnt;
}

inline int get_size(vector<node>::iterator p, vector<node>::iterator q) {
	if (p >= q) return 0;
	else return (p + (q-p)/2)->size;
}

void mark_used(vector<node>::iterator p, vector<node>::iterator q, int x) {
	vector<node>::iterator m = p + (q-p)/2;
	if (x < m->x) mark_used(p, m, x);
	else if (x == m->x) ++m->used;
	else mark_used(next(m), q, x);
	m->size = get_size(p, m) + m->used + get_size(next(m), q);
}

void testcase() {
	int n, k;
	cin >> n >> k;
	vector<point> points(n);
	for (vector<point>::iterator p = points.begin(); p != points.end(); ++p) {
		cin >> p->x >> p->y >> p->color;
		--p->color;
	}
	sort(points.begin(), points.end(), compare_x);
	vector<node> nodes(n);
	transform(points.begin(), points.end(), nodes.begin(), make_node);
	sort(points.begin(), points.end(), compare_y);
	int result = 0;
	multiset<int> init;
	init.insert(numeric_limits<int>::min());
	init.insert(numeric_limits<int>::max());
	vector<multiset<int> > colors(k, init);
	vector<point>::iterator q = points.begin();
	for (vector<point>::iterator p = points.begin(); p != points.end(); ++p) {
		for (; q->y < p->y; ++q) {
			colors[q->color].insert(q->x);
			mark_used(nodes.begin(), nodes.end(), q->x);
		}
		multiset<int>::iterator it = colors[p->color].upper_bound(p->x);
		int x1 = *prev(it), x2 = *it;
		if (x1 != numeric_limits<int>::min()) ++x1;
		if (x2 != numeric_limits<int>::max()) --x2;
		result = max(result, count(nodes.begin(), nodes.end(), x1, x2));
	}
	for (; q != points.end(); ++q) {
		colors[q->color].insert(q->x);
		mark_used(nodes.begin(), nodes.end(), q->x);
	}
	for (vector<multiset<int> >::iterator c = colors.begin(); c != colors.end(); ++c) {
		for (multiset<int>::iterator it = c->begin(); next(it) != c->end(); ++it) {
			int x1 = *it, x2 = *next(it);
			if (x1 != numeric_limits<int>::min()) ++x1;
			if (x2 != numeric_limits<int>::max()) --x2;
			result = max(result, count(nodes.begin(), nodes.end(), x1, x2));
		}
	}
	cout << result << endl;
}

int main() {
	int t;
	cin >> t;
	for (; t; --t) testcase();
	return 0;
}