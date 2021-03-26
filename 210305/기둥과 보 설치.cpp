#include <bits/stdc++.h>

using namespace std;
 
int block[110][110][2], N;
 
int insert(int x, int y, int type)
{

    if(type == 0)
    {
        if(y == 0)
        {
            return 1;
        }
        else if((x-1 >= 0 && block[x-1][y][1] == 1) || block[x][y][1] == 1)
        {
            return 1;
        }
		else if(y-1 >= 0 && block[x][y-1][0] == 1)
        {
            return 1;
        }
        
        return 0;
    }
    
    else
    {
       
        if((y-1 >= 0 && block[x][y-1][0] == 1) || (x+1 <= N && y-1 >= 0 && block[x+1][y-1][0] == 1))
        {
            return 1;
        }   
        
        else if(x-1 >= 0 && x+1 <= N && block[x-1][y][1] == 1 && block[x+1][y][1] == 1)
        {
            return 1;
        }
    
        return 0;   
    }
}
 
int erase()
{   
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                if(block[i][j][k] == 1)
                {
                    block[i][j][k] = 0;
                    
                    if(insert(i, j, k) == 0)
                    {
                        block[i][j][k] = 1;
                        return 0;
                    }
                    
                    block[i][j][k] = 1;
                }
            }
        }
    }
    
    return 1;
}
 
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) 
{
    vector<vector<int>> answer;
    N = n;
    
    for(int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
             
        if(build_frame[i][2] == 0)
        {       
         
            if(build_frame[i][3] == 1)
            {
          
                if(insert(x, y, 0) == 1)
                {
                    block[x][y][0] = 1;
                }
            }
       
            else
            {
                block[x][y][0] = 0;
                
                if(erase() == 0)
                {
                    block[x][y][0] = 1;
                }
            }
        }
        
        else if(build_frame[i][2] == 1)
        {
          
            if(build_frame[i][3] == 1)
            {
              
                if(insert(x, y, 1) == 1)
                {
                    block[x][y][1] = 1;
                }
            }
           
            else
            {
                block[x][y][1] = 0;
                
                if(erase() == 0)
                {
                    block[x][y][1] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                if(block[i][j][k] == 1)
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                    
                    answer.push_back(temp);
                }
            }
        }
    }
    
    return answer;
}
