#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:

    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
vector<Edge> edge_list;
int dis[1005];
bool cycle = false;

void ballman_ford()
{
    for(int i = 0; i < n-1; i++) //Ballman Ford algo always runs < n-1 times as we are setting the distance[0] = 0 by ourself; 
    {
        for(auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
    
            if(dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    for(auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
    
        if(dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if(cycle)
        cout << "Negative Weighted Cycle Detected" << endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }



}


int main()
{
    cin >> n >> e;
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a, b, c));
    }


    for(int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    ballman_ford();
    
    return 0;
}
