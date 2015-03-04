#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<stack>
using namespace std;
#define MAX 205
#define INF 1<<30   

int n, k, s;
int road[MAX];     //·����
int dist[MAX];
int visit[MAX];
int g[MAX][MAX];
int happy[MAX];     //ÿ�����happiness
int totalHappy[MAX];  //·�����ܹ���happiness
int cnt[MAX];       //��ȥ��ʼ�ڵ㣬·���ϵ�ĸ���
int pre[MAX];       //��¼��ǰ���ǰһ�ڵ㣬�����·��
map<string, int>S2N;
map<int, string>N2S;    //���ڵص����������໥ת��������map
stack<int> S;      //��stack��·���������


void dij()
{//�Ͻ�˹����
	dist[0] = 0;
	road[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		int mark = -1;
		int mindis = INF;
		for (int j = 0; j < n; ++j)
		{
			if (!visit[j] && dist[j] < mindis)
			{
				mindis = dist[j];
				mark = j;
			}
		}
		if (mark == -1)break;
		visit[mark] = 1;
		for (int j = 0; j < n; ++j)
		{
			if (!visit[j])
			{
				if (dist[mark] + g[mark][j] < dist[j])
				{
					dist[j] = dist[mark] + g[mark][j];
					totalHappy[j] = totalHappy[mark] + happy[j];
					road[j] = road[mark];
					cnt[j] = cnt[mark] + 1;
					pre[j] = mark;
				}
				else if (dist[mark] + g[mark][j] == dist[j])
				{
					road[j] += road[mark];
					if (totalHappy[j] < totalHappy[mark] + happy[j])
					{
						totalHappy[j] = totalHappy[mark] + happy[j];
						cnt[j] = cnt[mark] + 1;
						pre[j] = mark;
					}
					else if (totalHappy[j] == totalHappy[mark] + happy[j])
					{
						if (cnt[j] > cnt[mark] + 1)
						{
							cnt[j] = cnt[mark] + 1;
							pre[j] = mark;
						}
					}

				}
			}
		}
	}
}


void init()
{//��ʼ��һ�б���ֵ
	for (int i = 0; i < n; ++i)
	{
		pre[i] = 0;
		road[i] = 0;
		cnt[i] = 0;
		visit[i] = 0;
		dist[i] = INF;
		happy[i] = 0;
		totalHappy[i] = 0;
		S2N.clear();
		N2S.clear();
		while (!S.empty())
		{
			S.pop();
		}
		for (int j = 0; j < n; ++j)
		{
			g[i][j] = INF;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//while (scanf("%d%d", &n, &k))
	//{
		scanf("%d%d", &n, &k);
		init();
		string start;
		cin >> start;
		if (S2N.find(start) == S2N.end())
		{
			S2N[start] = 0;
			N2S[0] = start;
		}
		for (int i = 1; i < n; ++i)
		{
			string tmpCity;
			int tmpHappy;
			cin >> tmpCity >> tmpHappy;
			if (S2N.find(tmpCity) == S2N.end())
			{
				S2N[tmpCity] = i;
				N2S[i] = tmpCity;
			}
			happy[i] = tmpHappy;
		}
		for (int i = 0; i < k; ++i)
		{
			string a, b;
			int length;
			cin >> a >> b >> length;
			g[S2N[a]][S2N[b]] = length;
			g[S2N[b]][S2N[a]] = length;
		}
		s = S2N[start];
		dij();
		cout << road[S2N["ROM"]] << " " << dist[S2N["ROM"]] << " " << totalHappy[S2N["ROM"]];
		printf(" %d\n", (totalHappy[S2N["ROM"]] / cnt[S2N["ROM"]]));
		//���·��
		int iter = S2N["ROM"];
		while (1)//��֮ǰ��·���ϵĽڵ�ȫ��ѹջ
		{
			S.push(iter);
			if (iter == pre[iter])
			{
				break;
			}
			iter = pre[iter];
		};
		int tmpCnt = cnt[S2N["ROM"]];
		while (!S.empty())
		{
			cout << N2S[S.top()];
			S.pop();
			if (tmpCnt != 0)
			{
				cout << "->";
			}
			else
			{
				printf("\n");
			}
			tmpCnt--;
		}
	//}
	return 0;
}