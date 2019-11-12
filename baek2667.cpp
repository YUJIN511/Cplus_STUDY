#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

queue<pair<int, int> > q;
vector<int> vc;

int map[26][26] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int main()
{
	int N;
	int x, y;
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			scanf("%1d", &map[i][j]);
	int group_id;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			if (map[i][j] == 1)
			{
				group_id = 0;
				map[i][j] = 0;
				q.push(make_pair(i, j));

				while (!q.empty())
				{
					group_id++;
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int k = 0; k<4; k++)
					{
						if (x + dx[k] >= 0 || x + dx[k] < N || y + dy[k] >= 0 || y + dy[k] < N) {
							if (map[x + dx[k]][y + dy[k]] == 1)
							{
								map[x + dx[k]][y + dy[k]] = 0;
								q.push(make_pair(x + dx[k], y + dy[k]));
							}
						}
					}
				}
				vc.push_back(group_id);
			}
		}
	}

	cout << vc.size() << endl;

	sort(vc.begin(), vc.end());

	for (int i = 0; i<vc.size(); i++)
	{
		cout << vc[i] << endl;
	}

	return 0;
}