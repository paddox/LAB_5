#include <iostream>

using namespace std;
/** Структура дерева */
struct Node {
  int info;
  Node *child;
  bool seed;
};
/** Фунция добавления узла в дерево */
void add(Node *tree,int n, int current, int after)
{
    Node *p;
    for(int i=0; i<n; i++)
    {
        if (after==tree[i].info)
        {
            p = tree[i].child;
            while(p)
            {
                p = p->child;
            }
            p = new Node;
            p->info = current;
            p->child = NULL;
        }
    }
}
/** Функция, осуществляющая обход дерева в прямом порядке */
void probhod(Node *tree,int n)
{
    for(int i=0; i<n; i++)
        tree[i].seed = false;
    Node *p = NULL;
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if (tree[i].seed==false)
            {
                cout << tree[i].info <<" ";
                tree[i].seed = true;
                p = tree[i].child;
                while(p)
                {
                    for(int k=0; k<n; k++)
                        if ((p->info==tree[k].info) && (tree[k].seed == false))
                        {
                            i=k-1;
                        }
                }
            }
        }
    }
}

/** Функция, осуществляющая обход дерева в обратном порядке */
void obobhod(Node *tree,int n)
{
    for(int i=0; i<n; i++)
        tree[i].seed = false;
    Node *p = NULL;
    for(int j=0; j<n*n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if ((tree[i].child==NULL) && (tree[i].seed==false))
            {
                cout << tree[i].info <<" ";
                tree[i].seed = true;
            }
            else
            {
                p = tree[i].child;
                while(p)
                {
                    for(int k=0; k<n; k++)
                        if ((p->info==tree[k].info) && (tree[k].seed == false))
                        {
                            i=k-1;
                        }
                }
            }
        }
    }
}
int main()
{
    int N, info;
    Node *p;
    cout << "Kolichestvo vershin ->";
    cin >> N;
    p = new Node[N];
    for(int i=0; i<N; i++)
    {
        cin >> p[i].info >> info;
        p[i].child = NULL;
        p[i].seed = false;
        if (i!=0)
            add(p, N, p[i].info, info);
    }
    //probhod(p, N);
    obobhod(p, N);
    return 0;
}
