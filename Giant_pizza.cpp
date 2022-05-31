#include<bits/stdc++.h>//modified the code on gfg for the given algo
using namespace std;

const int MAX = 200000+1;
vector<int> adj[MAX];
vector<int> adjInv[MAX];
bool visited[MAX];
bool visitedInv[MAX];
stack<int> s;

int scc[MAX];

int counter = 1;
vector<bool>res;

void addEdges(int a, int b)
{
	adj[a].push_back(b);
}


void addEdgesInverse(int a, int b)
{
	adjInv[b].push_back(a);
}


void dfsFirst(int u)
{
	if(visited[u])
		return;

	visited[u] = 1;

	for (int i=0;i<adj[u].size();i++)
		dfsFirst(adj[u][i]);

	s.push(u);
}

void dfsSecond(int u,int n)
{
	if(visitedInv[u])
		return;

	visitedInv[u] = 1;

	for (int i=0;i<adjInv[u].size();i++)
		dfsSecond(adjInv[u][i],n);

	scc[u] = counter;
    if(u<=n)res[u]=true;
    else res[u-n]=false;
}
void is2Satisfiable(int n, int m, int a[], int b[])
{
    int z=n;
	for(int i=0;i<m;i++)
	{
	
		if (a[i]>0 && b[i]>0)
		{
			addEdges(a[i]+n, b[i]);
			addEdgesInverse(a[i]+n, b[i]);
			addEdges(b[i]+n, a[i]);
			addEdgesInverse(b[i]+n, a[i]);
		}

		else if (a[i]>0 && b[i]<0)
		{
			addEdges(a[i]+n, n-b[i]);
			addEdgesInverse(a[i]+n, n-b[i]);
			addEdges(-b[i], a[i]);
			addEdgesInverse(-b[i], a[i]);
		}

		else if (a[i]<0 && b[i]>0)
		{
			addEdges(-a[i], b[i]);
			addEdgesInverse(-a[i], b[i]);
			addEdges(b[i]+n, n-a[i]);
			addEdgesInverse(b[i]+n, n-a[i]);
		}

		else
		{
			addEdges(-a[i], n-b[i]);
			addEdgesInverse(-a[i], n-b[i]);
			addEdges(-b[i], n-a[i]);
			addEdgesInverse(-b[i], n-a[i]);
		}
	}

	for (int i=1;i<=2*n;i++)
		if (!visited[i])
			dfsFirst(i);

	while (!s.empty())
	{
		int n = s.top();
		s.pop();

		if (!visitedInv[n])
		{
			dfsSecond(n,z);
			counter++;
		}
	}

	for (int i=1;i<=n;i++)
	{
		if(scc[i]==scc[i+n])
		{
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	for (int i=1;i<=n;i++)
	{
		if(res[i])
		{
			cout << "+ ";
		}
        else
		{
			cout << "- ";
		}
	}
	return;
}

int main()
{

	int n ,m;
    cin>>m>>n;
    int a[n],b[n];
    int i;
    res.resize(n+1);
    for(i=0;i<m;i++){
        char c1,c2;
        int aa,bb;
        cin>>c1>>aa>>c2>>bb;
        if (c1=='+'){
            a[i]=aa;
        }
        else a[i]=-aa;
        if (c2=='+'){
            b[i]=bb;
        }
        else b[i]=-bb;
    }



	is2Satisfiable(n, m, a, b);

	return 0;
}

