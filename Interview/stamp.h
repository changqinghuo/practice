 /*  
    ������������  
    �㷨���:  
    �������������ѵ���Ʊ��ֵ��������ʾ��������  
    ���������������⣬��nԪ��x[1:n]��ʾn�ֲ�ͬ����Ʊ��ֵ��Լ�����Ǵ�С�������С�  
    x[1] = 1��Ψһ��ѡ�񡣴�ʱ�����������������[1:m]  
    ������x[2]�Ŀ���ȡֵ��Χ��[2:m+1]�����ȡֵ��Χ�;�����x[2]Ӧ����ôѡ��  
    ֻ����ȷ�������ķ�Χ����Ϊ������Ҫ��֤����һ����ֵ�󣬿��Խ�������  
    ��1һ������£���ѡ��x[1:i-1]����ʱ�����������������[1:r]���������  
    x[i]�Ŀ�ȡֵ��Χ��[x[i-1]+1:r+1]���ɴ˿��Կ��������û��ݷ�ʱ��������һ������ʾ��  
    ��ռ䡣�ý�ռ����и����Ķ���x�Ĳ�ͬȡֵ���仯��  
      
    ��x[1��n]�Ǵ�С�������е�n����Ʊ��ֵ��   
    ����x[1]=1 �Ǻ������ʵģ�������С���� 1 �޷�֧����   
    ��ֵΪ1����Ʊ���ɵ������������ֻ����[1,m] (ֻ��1�ž���1����m����Ʊȫ������m)��  
    �����ʱ���ٸ����ǵڶ���������Ʊ����Ϊ����Ҫ��x[1]����������ֻ����2��  
    ����Ϊ������x[1]֧���������������ֻ��m�������Ͼͳ����˶ϵ�������x[2]���Ҳֻ��ȡm+1  
    ������ٴ�Ļ���m+1���ֵ���޷�������ʾ��   
    ͬ���ĵ���������ǰ��k����Ʊ��ֵ���Ѿ����ˣ������ܹ���[1, r]�������������䣬  
    ��ô��k+1����Ʊ����ֵ�������㣺   
    x[k]+1 <= x[k+1] <= r+1   
    �㷨����Ҫ�ҵ���ô���ֿ�������µ����ŷ���  
      
    ���������������⣬��nԪ��x[1��n]��ʾn�ֲ�ͬ����Ʊ��ֵ����Լ�����Ǵ�С�������С�  
    x[1] = 1��Ωһ��ѡ����δȷ��ʣ������n��1����Ʊ��ֵ������£�ֻ��x[1]һ����Ʊ��ֵ��  
    ���ܵõ��������������������[1��m]����������ȷ��x[2]��ȡֵ��Χ�������ԣ�  
    x[2]��ֵ��С����ȡ��2����Ϊx[1] ��ʱ�Ѿ�Ϊ1�ˡ���ô������ȡ��ֵ�أ�Ӧ����m+1��  
    Ϊʲô����Ϊ���x[2]ȡm+2��������������У�����m+1������ȡ�ã�  
    �����ʱ��x[2��n]���κ�һ����ֵ�ǲ���ȡ�ģ���Ϊ����ֻȡһ�ţ��ܺ�Ҳ������Ϊm+2��  
    ����m+1�ˣ������������ֻȡx[1]��ֵ��������m��ȫȡ�ˣ�Ҳֻ�ܴյ�m�������ԣ�  
    ��������2����Ʊ��ʱ��������Χ��2 ~ m+2��m+2����ȡ������һ�������£���ѡ��x[1��i-1]��  
    �����������������[1��r]ʱ��������x[i]�Ŀ�ȡֵ��Χ��[x[i-1]+1 ��r+1]���ɴ˿��Կ�����  
    [x[i-1]+1 ��r+1]��Ϊ�޽纯�������û��ݷ���������������ʱ����������ʾ���ռ䣬  
    �ý�ռ����и����Ķ���x�Ĳ�ͬȡֵ���仯��  
      
    ���ڿ��Դ��»����ý�ռ����Ľṹ��  
    ���ڵĹؼ������ǣ����ȷ��x3��ȡֵ��Χ��ת��һ�¾�����������x[1]��x[2]��ֵȷ��������£�  
    �ò�����m����Ʊ�����õ�������������������Ƕ��٣����ÿһ�������������ܹ�ȷ����  
    ���ռ����Ѿ�������ˣ�ÿһ���Ķ��ӽ��Ϊr-x[i-1]�������ǾͿ���ͨ��������ȱ����ķ�ʽ�õ������ֵ���  
    (ÿ����Ҷ�����Ƚϸ���)��  
      
        ����������x[1]��x[2]��ֵȷ��������£��ò�����m����Ʊ�����õ�������������������Ƕ��٣�  
    ���������������������1��Ϊ���ģ�����������max����ʾ������ֵ����Ȼ��max���ٿ���ȡ��m��  
    ��Ϊ��ʹ����x[2]��ֵ��ֻ��x[1]��ֵ������£����ܵõ������ֵ���Ѿ���m�ˡ�����������x[1]��  
    x[2]��ֵȷ��������£��ò�����m����Ʊ��max+1�ܲ���ȡ����   
    ������ƴ�յĹ����У�x[2]��ֵ����Ʊȡt�ţ���t>=0��t<=��max+1�� /x[2] && t<=m  
    ����x[2]��ֵ����Ʊ�����Ѿ�ȷ����ԭ����ת��Ϊ��һ�������⣬������x[1]��ֵȷ��������£�  
    �ò�����m��t����Ʊ��max+1 - t*x[2] �ܲ���ȡ���� ������������  
    ����һ���ͺ����������ˣ���Ϊx[1] ��ֵΪ1���������Ҫƴ�յ�ֵmax+1- t*x[2] <= n-t�Ļ���  
    ��ֻ��ȡmax+1- t*x[2]�žͿ��������෴�����max+1- t*x[2] > m-t�Ļ������ǲ���������ġ�  
      
      
      ������Ļ��ݷ������У��ݹ麯��Backtrackʵ�ֶ�������ռ�Ļ���������  
    maxvalue��¼��ǰ�Ѿ��ҵ�����������������䣬bestx����Ӧ�ĵ�ǰ���Ž⡣  
    ����y������¼��ǰ�Ѿ�ѡ������Ʊ��ֵx[1:i]�������������������������Ʊ����  
      
      Ҳ����˵,y[k]���ò�����m����ֵΪx[1:i]����Ʊ����������k�����������Ʊ������  
    �ں���Backtrack�У�  
    ��i>nʱ����ʾ�㷨�Ѿ�������һ��Ҷ��㣬�õ�һ���µ���Ʊ��ֵ��Ʒ���x[1:n]������÷�����������  
    �����������������ڵ�ǰ�Ѿ��ҵ������������������maxvalue������µ�ǰ����ֵmaxvalue����Ӧ�����Ž⡣  
    ��i <= nʱ����ǰ��չ���z�ǽ�ռ��е�һ���ڲ���㣬�ڸý�㴦x[1:i-1]  
    ����������������������Ϊr-1.����ڽ��z��x[i]�Ŀ�ȡ��Χ��x[i-1]+1:r��  
    �Ӷ������z��r-x[i-1]�����ӽ�㡣�㷨�Ե�ǰ��չ���z��ÿһ�����ӽ�㣬  
    ��������ȵķ�ʽ�ݹ�ض���Ӧ������������  
      
      ��ռ��Ƕ���������ӽӵ������ÿ�㶼�ڱ仯��  
 */   

    #include<iostream>   
    using namespace std;   
       
    class Stamp   
    {   
        friend int MaxStamp(int,int,int[]);   
    private:   
        void Backtrack(int i,int r);   
        int n;   
        //��Ʊ��ֵ��   
        int m;   
        //ÿ���ŷ��������������Ʊ��   
        int maxvalue;   
        //��ǰ����ֵ   
        int maxint;   
        //������   
        int maxl;   
        //�����Ͻ磬��������ʱ�ʾ�������   
        int *x;   
        //��ǰ��   
        int *y;   
        //����������������������Ʊ��   
        int *bestx;   
        //��ǰ���Ž�   
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
       