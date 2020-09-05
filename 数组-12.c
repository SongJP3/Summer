/*给你一个?m * n?的整数矩阵?mat?，
请你将同一条对角线上的元素（从左上到右下）按升序排序后，
返回排好序的矩阵。

示例 1：

输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
?
提示：
m ==?mat.length
n ==?mat[i].length
1 <= m, n?<= 100
1 <= mat[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-the-matrix-diagonally
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//解题思路：
/*
初步思路还是决定用for循环和排序，
在原来的坐标的基础上都加1，直到其中一个坐标达到m或者n
*/
#include<stdio.h>
#define N 100
int main(void)
{
    int a[N][N],i=0,j=0,m,n,temp,l,f,k,h;
    printf("请输入数组的行数和列数：");
    scanf("%d %d",&m,&n);
    do
    {
        if(j==n)
        {
            i++;
            j=0;
        }
        scanf("%d",&a[i][j]);
        j++;
    }while(getchar()!='\n');
    /*for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    //这个地方是本题最关键的地方
    /*做法：
    基本思路：行为主，然后对那一行每一列的元素的对角线进行排列
    先从第i行的元素开始，从第i行的第一个元素到倒数第二个元素
    */
        for(i=0;i<m;i++)
        {
            k=i;
            for(j=0;j<n-1;j++)//第i行的第j个数字
            {
            h=j;k=i;
            while((i<m-1)&&(j<n-1))
            {
               l=i;
               f=j;
               while((l<m-1)&&(f<n-1))
               {
                   if(a[i][j]>a[l+1][f+1])
                   {
                       temp=a[i][j];
                       a[i][j]=a[l+1][f+1];
                       a[l+1][f+1]=temp; 
                   } 
                   l++; 
                   f++;//令对角线上的第一个数为最小值  
               }
               i++;
               j++;//跳转到对角线的下一个值，并让他成为次小值
            }
            j=h;i=k;
            }
            i=k;
        }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*总结：做本题花费的时间挺长的，大致框架和想法是有的，但是不够健全，
一开始只考虑到了对角线上的每一个数是上一个数的坐标位置的横纵坐标加一，
并且侧重点只放在了每一行的第一个数字，没有考虑到列的问题，
后来考虑到列的问题，却忘了把行赋值为最初的数字，我做的是最基础的做法，没有参考其他的答案，
属于暴力解法，有点凑的嫌疑*/
