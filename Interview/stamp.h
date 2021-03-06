 /*  
    连续邮资问题  
    算法设计:  
    该问题是设计最佳的邮票面值，用来表示最大的区间  
    对于连续邮姿问题，用n元组x[1:n]表示n种不同的邮票面值并约定它们从小到大排列。  
    x[1] = 1是唯一的选择。此时最大连续邮资区间是[1:m]  
    接下来x[2]的可能取值范围是[2:m+1]，这个取值范围就决定了x[2]应该怎么选，  
    只所以确定这样的范围是因为，至少要保证增加一个面值后，可以将区间增  
    大1一般情况下，已选定x[1:i-1]，此时最大连续邮资区间是[1:r]，则接下来  
    x[i]的可取值范围是[x[i-1]+1:r+1]。由此可以看出，在用回溯法时，可以用一棵树表示其  
    解空间。该解空间树中各结点的度随x的不同取值而变化。  
      
    设x[1～n]是从小到大排列的n种邮票面值。   
    首先x[1]=1 是毫无疑问的，否则最小邮资 1 无法支付。   
    面值为1的邮票构成的最大连续区间只能是[1,m] (只贴1张就是1……m张邮票全贴满是m)。  
    如果这时候再给我们第二种面额的邮票。因为它需要比x[1]大，所以最少只能是2；  
    又因为单纯由x[1]支付的邮资区间最大只到m，再往上就出现了断档，所以x[2]最大也只能取m+1  
    （如果再大的话，m+1这个值就无法正常表示）   
    同样的道理，假设前面k种邮票面值都已经有了，并且能构成[1, r]的连续邮资区间，  
    那么第k+1种邮票的面值必须满足：   
    x[k]+1 <= x[k+1] <= r+1   
    算法就是要找到这么多种可能情况下的最优方案  
      
    对于连续邮资问题，用n元组x[1：n]表示n种不同的邮票面值，并约定它们从小到大排列。  
    x[1] = 1是惟一的选择。在未确定剩余其它n－1种邮票面值的情况下，只用x[1]一种邮票面值，  
    所能得到的最大连续邮资区间是[1：m]。接下来，确定x[2]的取值范围，很明显，  
    x[2]的值最小可以取到2，因为x[1] 这时已经为1了。那么最大可以取的值呢？应当是m+1，  
    为什么？因为如果x[2]取m+2，则在这个方案中，邮资m+1不可能取得，  
    （这个时候，x[2：n]的任何一个面值是不能取的，因为就算只取一张，总和也会至少为m+2，  
    超过m+1了，反过来，如果只取x[1]面值，则就算把m张全取了，也只能凑到m）。所以，  
    在搜索第2张邮票的时候，搜索范围是2 ~ m+2（m+2不剪取）。在一般的情况下，已选定x[1：i-1]，  
    最大连续邮资区间是[1：r]时，接下来x[i]的可取值范围是[x[i-1]+1 ：r+1]。由此可以看出，  
    [x[i-1]+1 ：r+1]（为限界函数）在用回溯法解连续邮资问题时，可用树表示其解空间，  
    该解空间树中各结点的度随x的不同取值而变化。  
      
    现在可以大致画出该解空间树的结构。  
    现在的关键问题是，如何确定x3的取值范围？转换一下就是如何求得在x[1]，x[2]面值确定的情况下，  
    用不超过m张邮票，所得到的最大连续邮资区间是多少？如果每一个这样的问题能够确定，  
    则解空间树已经构造好了（每一个的儿子结点为r-x[i-1]），我们就可以通过深度优先遍历的方式得到最佳面值设计  
    (每到达叶结点见比较更新)。  
      
        现在来看在x[1]，x[2]面值确定的情况下，用不超过m张邮票，所得到的最大连续邮资区间是多少？  
    最大连续邮资区间总是以1作为起点的，所以我们用max来表示这个最大值，显然，max至少可以取到m，  
    因为即使不用x[2]面值，只用x[1]面值的情况下，所能得到的最大值就已经是m了。现在来看在x[1]，  
    x[2]面值确定的情况下，用不超过m张邮票，max+1能不能取到？   
    假设在拼凑的过程中，x[2]面值的邮票取t张，则t>=0，t<=（max+1） /x[2] && t<=m  
    现在x[2]面值的邮票张数已经确定，原问题转化为另一个子问题，即，在x[1]面值确定的情况下，  
    用不超过m－t张邮票，max+1 - t*x[2] 能不能取到？ 。。。。。。  
    到这一步就很容易理解了，因为x[1] 面值为1，所以如果要拼凑的值max+1- t*x[2] <= n-t的话，  
    则只用取max+1- t*x[2]张就可以拉。相反，如果max+1- t*x[2] > m-t的话，则是不可以满足的。  
      
      
      在下面的回溯法描述中，递归函数Backtrack实现对整个解空间的回溯搜索。  
    maxvalue记录当前已经找到的最大连续邮资区间，bestx是相应的当前最优解。  
    数组y用来记录当前已经选定的邮票面值x[1:i]能贴出各种邮资所需的最少邮票数。  
      
      也就是说,y[k]是用不超过m张面值为x[1:i]的邮票，贴出邮资k所需的最少邮票张数。  
    在函数Backtrack中，  
    当i>n时，表示算法已经搜索到一个叶结点，得到一个新的邮票面值设计方案x[1:n]。如果该方案能贴出的  
    最大连续邮资区间大于当前已经找到的最大连续邮资区间maxvalue，则更新当前最优值maxvalue和相应的最优解。  
    当i <= n时，当前扩展结点z是解空间中的一个内部结点，在该结点处x[1:i-1]  
    能贴出的最大最大邮资区间为r-1.因此在结点z处x[i]的可取范围是x[i-1]+1:r，  
    从而，结点z有r-x[i-1]个儿子结点。算法对当前扩展结点z的每一个儿子结点，  
    以深度优先的方式递归地对相应子树进行搜索  
      
      解空间是多叉树，孩子接点个数是每层都在变化的  
 */   

    #include<iostream>   
    using namespace std;   
       
    class Stamp   
    {   
        friend int MaxStamp(int,int,int[]);   
    private:   
        void Backtrack(int i,int r);   
        int n;   
        //邮票面值数   
        int m;   
        //每张信封最多允许贴的邮票数   
        int maxvalue;   
        //当前最优值   
        int maxint;   
        //大整数   
        int maxl;   
        //邮资上界，假设的邮资表示的最大数   
        int *x;   
        //当前解   
        int *y;   
        //贴出各种邮资所需最少邮票数   
        int *bestx;   
        //当前最优解   
    };   
       
   
    int MaxStamp(int n,int m,int bestx[])   
    {   
        Stamp X;   
        int maxint = 32767;   
        int maxl = 1500;   
        X.n = n;   
        X.m = m;   
        X.maxvalue = 0;   
        X.maxint = maxint;   
        X.maxl = maxl;   
        X.bestx = bestx;   
        X.x = new int[n+1];   
        X.y = new int[maxl + 1];   
        for( int i = 0; i <= n; ++i )   
        {   
            X.x[i] = 0;   
        }   
        for( i = 1; i <= maxl; ++i )   
        {   
            X.y[i] = maxint;   
        }   
        X.x[1] = 1;   
        X.y[0] = 0;   
        X.Backtrack(2,1);   
        delete []X.x;   
        delete []X.y;   
        return X.maxvalue;   
    }   
       
