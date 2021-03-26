#include <bits/stdc++.h>

using namespace std;
 
typedef struct node
{
    int x;
    int y;
    int num;
    struct node *left;
    struct node *right;
}node;

node *root;
vector<node> newinfo;


vector<int> pre;
vector<int> post;
 
bool cmp(node a, node b)
{
    if(a.y > b.y)
    {
        return true;
    }
    else if(a.y == b.y)
    {
        if(a.x < b.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
 
void find_position_and_connect(node *now, int idx)
{        
    if(now == NULL)
    {
        return;
    }
        
    if(now->x < newinfo[idx].x)
    {
        if(now->right == NULL)
        {
            node *newNode = (node*)malloc(sizeof(node)*1);
            newNode[0] = {newinfo[idx].x, newinfo[idx].y, newinfo[idx].num, NULL, NULL};
            now->right = newNode;
            
            return;
        }
        else
        {
            find_position_and_connect(now->right, idx);   
        }
    }
    else
    {
        if(now->left == NULL)
        {
            node *newNode = (node*)malloc(sizeof(node)*1);
            newNode[0] = {newinfo[idx].x, newinfo[idx].y, newinfo[idx].num, NULL, NULL};
            now->left = newNode;
            
            return;
        }
        else
        {
            find_position_and_connect(now->left, idx);   
        }
    }
}
 
void preOrder(node *now)
{
    if(now == NULL)
    {
        return;
    }
    
    pre.push_back(now->num+1);
    preOrder(now->left);
    preOrder(now->right);
}
 
void postOrder(node *now)
{
    if(now == NULL)
    {
        return;
    }
    
    postOrder(now->left);
    postOrder(now->right);
    post.push_back(now->num+1);
}
 
vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{    
    vector<vector<int>> answer;
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        newinfo.push_back({nodeinfo[i][0], nodeinfo[i][1], i, NULL, NULL}); 
    }
    sort(newinfo.begin(), newinfo.end(), cmp);
    
    root = (node*)malloc(sizeof(node)*1);
    root[0] = {newinfo[0].x, newinfo[0].y, newinfo[0].num, NULL, NULL};
    
    for(int i = 1; i < newinfo.size(); i++)
    {
        find_position_and_connect(root, i);
    }
 
    preOrder(root);
    postOrder(root);   
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}
