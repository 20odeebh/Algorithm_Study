#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAX_SIZE 10001
int N, M;
int parents[MAX_SIZE];
int get_parent(int x)
{
	if (parents[x] == x)
		return x;
	return parents[x] = get_parent(parents[x]);
}
void _union(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a < b)
		parents[b] = a;
	else
		parents[a] = b;
}
bool find(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a == b)
		return true;
	else
		return false;
}
int main()
{
	cin >> N >> M;
	int s, e;
	for (int i = 0; i <= N; i++)
		parents[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		if (!find(s, e)) {
			_union(s, e);
		}
	}
	set<int> se;
	for (int i = 1; i <= N; i++)
		se.insert(get_parent(i));
	int answer = se.size();
	printf("%d\n", answer);
	return 0;
}