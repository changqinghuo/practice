#include "StdAfx.h"
#include "stamp.h" 
void Stamp::Backtrack(int i,int r)   
{   
        for( int j = 0; j <= x[i-2]*(m-1); ++j )   
        //y[j]是用不超过m张面值为x[1:i]的邮票，贴出邮资j所需的最少邮票张数   
        //x[i-2]*(m-1)是第i-2层循环的一个上限，目的是找到r-1的值   
        //首先要判断已经表示出来的邮资能不能用更少的邮票数来表示,x[i-2]*(m-1)是旧的   
        //邮票能表示的最大范围，因为x[i-2]*(m-1)+x[i-1]*k,最大也就是说只有m-1个是x[i-2]   
        //至少有一个是x[i-1]   
        {   
            if ( y[j] < m )   
            {   
                for( int k = 1; k <= m - y[j]; ++k )   
                //k是对表示j剩余的票数进行检查   
                {   
                    if ( y[j] + k < y[j + x[i-1]*k] )   
                    //x[i-1]*k是k张邮票能表示的最大邮资   
                    //+j表示增加了i邮资后能   
                    //判断新增加的能表示的邮资需要多少   
                    {   
                        y[j+x[i-1]*k] = y[j] + k;   
                    }   
                    //对第i-2层扩展一个x[i-1]后的邮资分布   
                }   
            }   
        }   
        //查看邮资范围扩大多少，然后查询y数组从而找到r   
       
        while( y[r] < maxint )   
        {   
            ++r;   
        }   
        //搜索求出r-1的值，对应x[1:i-1]的在m张限制内的最大区间   
       
        if ( i > n )   
        {   
            if ( r - 1 > maxvalue )   
            {   
                maxvalue = r - 1;   
                for( int j = 1; j <= n; ++j )   
                {   
                    bestx[j] = x[j];   
                }   
                return;   
            }   
        }   
       
        int *z = new int[maxl];   
        for( int k = 1; k <= maxl; ++k )   
        {   
            z[k] = y[k];   
        }   
        //保留数据副本，以便返回上层时候能够恢复数据   
        //以上都是处理第i-1层及其之上的问题   
        for( j = x[i-1] + 1; j <= (r-1)+1; ++j )   
        //在第i层有这么多的孩子结点供选择   
        {   
            x[i] = j;   
            Backtrack(i+1,r);   
            //返回上层恢复信息   
            for( int k = 1; k <= maxl; ++k )   
            {   
                y[k] = z[k];   
            }   
        }   
        delete []z;   
}       
