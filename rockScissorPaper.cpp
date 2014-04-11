/**
http://blog.csdn.net/twlkyao/article/details/23474155
*/

#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<functional>  
#include<iterator>  
#include<cstdio>  
#include<queue>  
using namespace std;  
//并查集  
const int MAX_N = 50010;  
const int MAX_K = 100010;  
int set[MAX_N*3];//父亲  
int height[MAX_N*3];//树的高度  
int T[MAX_K],X[MAX_K],Y[MAX_K];  
//并查集  
//初始化n个元素  
void init(int n)  
{  
    for (int i = 0; i < n; i++)  
    {  
        set[i] = i;//set[x]==x时，x是所在树的根  
        height[i] = 0;  
    }  
}  
//查 查询x所在树的根  
int cha(int x)  
{  
    int r = x;  
    while (set[r] != r)  
        r = set[r];  
    int i = x;  
    int j(0);  
    while (i != r)//路径压缩  
    {  
        j = set[i];  
        set[i] = r;  
        i = j;  
    }  
    return r;  
}  
//并  合并x和y所属的集合  
void unite(int x, int y)  
{  
    x = cha(x);  
    y = cha(y);  
    if (x == y)  
        return ;  
    if (height[x] < height[y])  
    {  
        set[x] = y;  
    }  
    else  
    {  
        set[y] = x;  
        if (height[x] == height[y])  
            height[x]++;  
    }  
}  
//判断x和y是否属于同一个集合  
bool same(int x, int y)  
{  
    return cha(x) == cha(y);  
}  
int main()  
{  
//#ifdef ONLINE_JUDGE    
//#else    
//    freopen("D:\\in.txt", "r", stdin);  
//    freopen("D:\\out.txt", "w", stdout);  
//#endif // ONLINE_JUDEG  
	
	int kk(0);
    int n(0), k(0);  
    int ans(0);
    int i(0);
	scanf("%d", &kk); 
	for(i = 0; i < kk; i++) {
		scanf("%d%d", &n, &k);  
      
    for (int i = 0; i < k; i++)  
    {  
        scanf("%d%d%d", &T[i], &X[i], &Y[i]);  
    }  
    //初始化并查集，元素x,x+n,x+2*n分别代表x-A,x-B,x-C  
    init(n * 3);  
    ans = 0;  
    for (int i = 0; i < k; i++)  
    {  
        int t = T[i];//信息的类型  
        int x = X[i] - 1;  
        int y = Y[i] - 1;//把输入变成0--N-1的范围  
  
        //不正确的编号   
        if (x < 0 || y < 0 || x >= n || y >= n)  
        {  
            ans++;  
            continue;  
        }  
              
        if (t == 1)//“x 和 y 属于同一类”的信息  
        {  
            if (same(x,y+n)||same(x,y+2*n))  
            {  
                ans++;  
            }  
            else  
            {  
                unite(x, y);  
                unite(x + n, y + n);  
                unite(x + n * 2, y + n * 2);  
            }  
        }  
        else// "x吃y的信息"  
        {  
            if (same(x, y) || same(x, y + 2 * n))  
            {  
                ans++;  
            }  
            else  
            {  
                unite(x, y + n);  
                unite(x + n, y + 2 * n);  
                unite(x + 2 * n, y);  
            }  
        }    
    }  
    printf("%d\n", ans);	
	}
    return 0;  
}
